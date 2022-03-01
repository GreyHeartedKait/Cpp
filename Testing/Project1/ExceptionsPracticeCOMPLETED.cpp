#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;



/* CLASS DEFINITION
 *
 *  This is the student class.   No changes
 *  should be made to this.
 */
 class StudentScores
{
    private:
        vector<int> scores;
        string name;
    public:
        virtual ~StudentScores();
        StudentScores(string, vector<double>);

        double getAverage() const;
        friend ostream & operator << (ostream &out, const StudentScores &ss);


        /* EXCEPTION CLASS
        *
        * This is an exception class created for the student class.
        */

        class StudentERROR {
        public:
            string error();
            StudentERROR(string = "ERROR Found");

            friend ostream& operator << (ostream&, const StudentERROR&);

        private:
            string errorFound;
        };
};


vector<StudentScores> setupDataFile();
/* Main
 *
 *  This is where the try/catch blocks
 *  should be added
 */

int main()
{
    vector<StudentScores>  myClass;
    myClass = setupDataFile();

    for (StudentScores student : myClass)
    {
        try { cout << student << endl << endl; }
        catch (StudentScores::StudentERROR error) { cout << error << endl << endl; }
    }
  

    cout << "!!!!!     Program Finished Successfully     !!!!!" << endl;
}

/* Class Methods.
 * Add the proper throw methods here.
 */

StudentScores::~StudentScores(){}

StudentScores::StudentScores(string n, vector<double> decimalScores)
{
    for (double d : decimalScores)
    {
        int roundedScore = (int) ceil(d);
        scores.push_back(d);
    }
    name = n;
}

double StudentScores::getAverage() const
{
   double sum = 0;

   for (int i : scores) {
       if (i > 100 || i < 0) throw StudentERROR("Error Found : Improper score found.");

       sum += i;
   }

   return sum / scores.size();
}

ostream & operator << (ostream &out, const StudentScores &ss)
{
    if (ss.name.length() < 2) throw StudentScores::StudentERROR("Error Found : Name is too short to print");

    double avg = ss.getAverage();

    out << "Student : " <<setw(10)<< ss.name << " has an average of " 
        << setprecision(2) << fixed << avg << endl;
    out << "     With Scores ";
    for (int i : ss.scores) out << i << "  ";

    return out;
}


/* Error Class Methods */

string StudentScores::StudentERROR::error() {
    return errorFound;
}

StudentScores::StudentERROR::StudentERROR(string error) {
    errorFound = error;
}

ostream& operator << (ostream& output, const StudentScores::StudentERROR& error) {
    output << error.errorFound;

    return output;
}


//******************** Data Setup Method
//  Don't modify this
//**************************************

vector<StudentScores> setupDataFile()
{
        vector<double> list1 = {77.7, 88.8, 99.9, 11.1, 22.2, 33.3, 44.4};
    vector<double> list2 = {23.4, 34.5, 45.6, 56.7, 67.8, 120.3};
    vector<double> list3 = {98.7, 87.6, 76.5, 54.4, 43.2, -12.2};
    vector<double> list4 = {53.4, 75.8, 57.8, 98.7, 56.76, 84.5};
    vector<double> list5 = {44.4, 55.5, 66.6, 77.7, 88.8, 99.9, 11.1, 22.2};

    vector<StudentScores>  myClass;
    myClass.push_back(StudentScores("Anna", list1));
    myClass.push_back(StudentScores("Betty", list2));
    myClass.push_back(StudentScores("Charlie", list3));
    myClass.push_back(StudentScores("Donna", list4));
    myClass.push_back(StudentScores("", list5));

    return myClass;
}



