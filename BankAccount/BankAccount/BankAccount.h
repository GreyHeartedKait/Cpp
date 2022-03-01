#pragma once
#include <string>

class BankAccount
{
public:
	//Constructor
	BankAccount(std::string, double);

	//Functions
	std::string getID() { return accountID; }
	virtual void deposit(double);
	virtual void withdraw(double);
	virtual void endOfMonth() = 0;
	virtual void endOfYear();
	virtual void printStatus() = 0;

	//Operator
	bool operator<(const BankAccount&);

protected:

	double balance; //account balance
	int num_deposits; //Number of deposits 
	int num_withdrawl; //Number of withdrawls 
	std::string accountID;
};

class SimpleSavings : public BankAccount {

public:
	//constructor
	SimpleSavings(std::string, double);

	//overwritten-functions
	virtual void withdraw(double);
	virtual void endOfMonth();
	virtual void endOfYear();
	virtual void printStatus();
};

class AdvancedSavings : public BankAccount {
public:
	//constructor
	AdvancedSavings(std::string, double);

	//overwritten-functions
	virtual void withdraw(double);
	virtual void endOfMonth();
	virtual void endOfYear();
	virtual void printStatus();
};

class CheckingAccount : public BankAccount {
public:
	//constructor
	CheckingAccount(std::string, double);

	//overwritten-functions
	virtual void withdraw(double);
	virtual void endOfYear();
	virtual void endOfMonth();
	virtual void printStatus();
};

class CreditAccount : public BankAccount {
public:
	//constructor
	CreditAccount(std::string, double);

	//overwritten functions
	virtual void deposit(double);
	virtual void endOfMonth();
	virtual void endOfYear();
	virtual void printStatus();
	virtual void withdraw(double);

private:
	int num_late; //number of months in which payment was late

	double amount_deposited; //the amount deposited in a month

	bool closed; //if account is closed

	//helper function
	bool isLate(); 
};

