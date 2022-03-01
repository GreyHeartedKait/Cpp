#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <string>


//////////////////////////////Bank Account Abstract Base Class//////////////////////////////
BankAccount::BankAccount(std::string ID, double money) {
	balance = money;
	accountID = ID;

	//set counters to 0.
	num_deposits = 0;
	num_withdrawl = 0;
}


/* Bank Account deposit */
void BankAccount::deposit(double money) {
	//if inputted value is negative,
	if (money < 0) money *= -1;

	balance += money;
	num_deposits++;
}


/* Bank Account withdraw */
void BankAccount::withdraw(double money) {
	if (money < 0) money *= -1;

	balance -= money;
	num_withdrawl++;
}


/* Bank Account endOfYear
* Set all counters to 0.
*/
void BankAccount::endOfYear() {
	num_deposits = 0;
	num_withdrawl = 0;
}


/* Bank Account < Bank Account
* 
* Using the account ID, compare the bank accounts.
*/
bool BankAccount::operator<(const BankAccount& rhs) {
	return accountID < rhs.accountID;
}


////////////////////////////// Simple Savings Account ////////////////////////////// 
SimpleSavings::SimpleSavings(std::string ID, double money) : BankAccount(ID, money) {
	//Starting balance cannot be negative. 
	if (money < 0) balance = 0;
	else balance = money;

	accountID = ID;
}


/* Simple Saving Withdraw
* 
* Withdraw money that is in the account.
*/
void SimpleSavings::withdraw(double money){
	if (balance >= money) BankAccount::withdraw(money);
}


/* Simple Saving endOfMonth
* 
* At the end of each month, add .5% interest to the account.
*/
void SimpleSavings::endOfMonth() {
	double monthly_interest = balance * 0.005;
	balance += monthly_interest;
}


/* Simple Saving endOfYear
* 
* Subtract $5 fee and set all counters to 0.
*/
void SimpleSavings::endOfYear() {
	balance -= 5;
	BankAccount::endOfYear();
}


/* Simple Savings printStatus
* 
* EX: Simple Account #00000 has $00000.00.
*/
void SimpleSavings::printStatus() {
	std::cout << "Simple Account #" << accountID
		<< " has $" << std::fixed << std::showpoint << std::setprecision(2) << balance <<"."<<std::endl;
}


////////////////////////////// Advanced Savings Account //////////////////////////////
AdvancedSavings::AdvancedSavings(std::string ID, double money) : BankAccount(ID, money) {
	//balance cannot be negative
	if (money < 0) balance = 0;
	else balance = money;

	accountID = ID;
}


/*
* Advanced Savings Withdraw
* 
* One cannot take out more money than there is in the account.
* Each time a withdrawl is made, take a fee: $1 more dollar for ever withdraw made. 
*/
void AdvancedSavings::withdraw(double money){
	if (balance >= money) {
		BankAccount::withdraw(money);

		if (num_withdrawl > 1) balance = balance - num_withdrawl + 1;

	}
}


/* Advanced Savings endOfMonth
* 
* If there is more than 10k in the account, add 2% interest. 
* Otherwise, add the 1% monthly interest. 
*/
void AdvancedSavings::endOfMonth(){
	double interest = 0.01;
	if (balance > 10000) interest *= 2;

	double monthly_interest = balance * interest;
	balance += monthly_interest;
}


/* Advanced Savings endOfYear
* 
* If no withdrawls were made, take away a $15 fee.
* Otherwise, take a $100 fee.
* Set all counters to 0.
*/
void AdvancedSavings::endOfYear(){
	if (num_withdrawl == 0) balance -= 15;
	else balance -= 100;

	BankAccount::endOfYear();
}


/* Advanced Savings printStatus 
* 
* EX: Advanced Account #00000 has $00000.00 with 00 withdrawls this year.
*/
void AdvancedSavings::printStatus(){
	std::cout << "Advanced Account #" << accountID
		<< " has $" << std::fixed << std::showpoint << std::setprecision(2) << balance
		<< " with "<< num_withdrawl<<" withdrawls this year."<<std::endl;
}


////////////////////////////// Checking Account //////////////////////////////
CheckingAccount::CheckingAccount(std::string ID, double money) : BankAccount(ID, money){
	//checking account can start with a negative balance.
	balance = money;
	accountID = ID;
}


/* Checking Account Withdraw
* 
* If balance becomes/is negative at withdraw, then charge at $15 service fee. 
*/
void CheckingAccount::withdraw(double money){
	BankAccount::withdraw(money);

	if (balance < 0) balance -= 15; 
}


/* Checking Account endOfYear
* 
* Charge fees: $5 + .10 * number of withdraws
* Then, if account balance is negative, charge an extra 10% of balance. 
*/
void CheckingAccount::endOfYear(){
	balance -= (5 + .10 * num_withdrawl);
	if (balance < 0) balance += balance * .10;
}


/* Checking Account endOfMonth
* 
* There is no monthly interest. 
*/
void CheckingAccount::endOfMonth() {}


/* Checking Account printStatus
* 
* EX: Checking Account #0000 has $0000.00 with 00 withdrawls this year.
*/
void CheckingAccount::printStatus(){
	std::cout << "Checking Account #" << accountID
		<< " has $" << std::fixed << std::showpoint << std::setprecision(2) << balance
		<< " with " << num_withdrawl << " withdrawls this year."<<std::endl;
}


////////////////////////////// Credit Account //////////////////////////////
CreditAccount::CreditAccount(std::string ID, double money) : BankAccount(ID, money) {
	//balance cannot be greater than 0. If passed value > 0, set balance as 0.
	if (money > 0) balance = 0;
	else balance = money;

	accountID = ID;

	//set counters to 0, and closed to 'false'
	num_late = 0;
	amount_deposited = 0;
	closed = 0;
}


/* Credit Account deposit
* 
* Money amounts larger than the amount owed (balance) cannot be deposited. 
* Add to amount_deposited counter.
*/
void CreditAccount::deposit(double money){
	if ((money + balance) <= 0) {
		balance += money;
		amount_deposited += money;
	}
}


/* Credit Account endOfMonth
* 
* If payment is late, add to num_late counter.
* If money is owed, add 4% interest to amount owed (balance).
* Reset monthly amount_deposited counter.
*/
void CreditAccount::endOfMonth() {
		if (isLate()) num_late++;
		if (balance < 0) balance += .04 * balance;

		amount_deposited = 0;
}


/* Credit Account endOfYear
* 
* If two or more monthly payments were late, close the account.
* Charge a $25 yearly fee.
* Reset late payments counter. 
*/
void CreditAccount::endOfYear(){
	if (num_late >= 2) closed = true;
	balance -= 25;
	num_late = 0;
}


/* Credit Account isLate
* 
* If money is owed and less than $100 has been deposited for the month, a payment is late.
*/
bool CreditAccount::isLate() {
	return ((balance < 0) && (amount_deposited < 100));
}


/* Credit Account printStatus
* 
* EX: Credit Account #00000 owes $0.00.
* EX: Credit Account #00000 owes $10.00 and is currently closed.
* EX: Credit Account #00000 owes $0.00 and is late (month #00).
*/
void CreditAccount::printStatus() {
	std::cout << "Credit Account #" << accountID << " owes $"
		<< std::fixed << std::showpoint << std::setprecision(2);

	if (balance < 0) std::cout << balance * -1;
	else std::cout << balance; 

	if (closed)
		std::cout << " and is currently closed.";

	else if (num_late > 0) std::cout << " and is late (month #" <<num_late<<").";

	else std::cout << ".";

	std::cout << std::endl;
}

/* Credit Account withdraw
* 
* If account is closed, do not allow withdrawls.
*/
void CreditAccount::withdraw(double money) {
	if (closed) std::cout << "Credit account #" << accountID << " is closed. No money can be withdrawed."
		<< std::endl;

	else BankAccount::withdraw(money);
}

