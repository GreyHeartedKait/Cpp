/* Rock Paper Scissors
* This class creates a RPSMove that can be printed and compared to other moves (to see who wins).
*
* By Kaitlyn Bui
* 01.27.2022, Version 1
*/

#include "RPSMove.h"


//Constructors--------------------------------------------------------------


//Set
RPSMove::RPSMove(std::string move){
	if (validMove(move)) name = move;
	else name = randomMove();
}

//Random
RPSMove::RPSMove(){
	name = randomMove();
}


//Functions-----------------------------------------------------------------

/* RPSMove wins versus RPS Move
* -1 = lose
* 0 = draw
* 1 = win
*/
int RPSMove::Vs(const RPSMove& rhs) const {
	if (name == rhs.name) return 0;

	else if ((name == "rock") && (rhs.name == "scissors")) return 1;

	else if ((name == "paper") && (rhs.name == "rock")) return 1;

	else if ((name == "scissors") && (rhs.name == "paper")) return 1;

	else if ((name == "scissors") && (rhs.name == "rock")) return -1;

	else if ((name == "rock") && (rhs.name == "paper")) return -1;

	else if ((name == "paper") && (rhs.name == "scissors")) return -1;

	else return 1000;

}

/* validMove(string)
* Determines if string input is a valid move.
*/
bool RPSMove::validMove(std::string &name) {
	makeTrim(name);
	toLower(name);
	return ((name == "rock") || (name == "scissors") || (name == "paper"));
}

/* << Operator */
std::ostream& operator<<(std::ostream& stream, const RPSMove& move) {
	stream << move.name;
	return stream;
}

/* >> Operator */
std::istream& operator>>(std::istream& stream, RPSMove& move) {
	stream >> move.name;

	if (!move.validMove(move.name)) move.name = move.randomMove();

	return stream;
}


//Helper Functions----------------------------------------------------------


/* randomMove()
* Return a random move. 
*/
std::string RPSMove::randomMove() {
	int x = rand() % 3;

	switch (x){

	case 0:
		return "rock";

	case 1:
		return "scissors";

	case 2:
		return "paper";

	default: //should never be returned.
		return "ERROR";
	}
}



//Outside Functions----------------------------------------------------


/* toLower(string) 
* This function ensures a string only has lower case letters. 
*/
void toLower(std::string &var) {
	std::string temp = "";
	for (unsigned int i = 0; i < var.length(); i++) {
		temp += tolower(var.at(i));
	}
	var = temp;
}

/* makeTrim(string&)
* This method will trim extraneous white space at the front and end of a string.
* Code courtesy of Prof. Wood.
*/
void makeTrim(std::string& x) {
	const char* ws = " \t\n\r\f\v";
	x.erase(0, x.find_first_not_of(ws)); //erases prefix white space
	x.erase(x.find_last_not_of(ws) + 1);  //erases suffix white space
}

