
#include <iostream>
#include "FractionalComplex.h"

using namespace std;

//void intro();
//void section1();
//void section2();
//void section3();
//void section4();
//void section5();
//void section6();
//void section7();
//void section8();

void section8();

int main()
{
   
    section8();

}


void intro()
{

    cout << "* Welcome to the testing class for the FractionalComplex number.";
    cout << endl;
    cout << "* By the end of the assignment, every line below must work, but to begin";
    cout << endl;
    cout << "* most of the sections are commented off.  Uncomment each section as you";
    cout << endl;
    cout << "* get more and more to work : Good Luck!" << endl;
    cout << "************************************************************************"<< endl << endl;
}

void section1()
{
    cout << "** Section 1" << endl;
    cout << "Basic creation and printing" << endl << endl;
    FractionalComplex a;
    FractionalComplex b(5, 10);
    FractionalComplex c(1,2,3,4);

    cout<<a;
    cout<<b;
    cout<<c;
}

void section2()
{

    cout << endl << endl;
    cout << "** Section 2" << endl;
    cout << "Reductions " << endl << endl;

    FractionalComplex a;

    a = FractionalComplex(20, 6, 10, 8);
    cout << a;
    a = FractionalComplex(-45, 105, 60, 54);
    cout << a;
    a = FractionalComplex(-2, -4, -12, -8);
    cout << a;
    a = FractionalComplex(1, -4, 2, -10);
    cout << a;

}

void section3()
{

    cout << endl << endl;
    cout << "** Section 3" << endl;
    cout << "Addition " << endl << endl;

    FractionalComplex a, b, c;

    cout << "Sample 1" << endl;
    a = FractionalComplex(1, 2, 3, 4);
    cout << a;
    b = FractionalComplex(1, 3, 5, 4);
    cout << a;

    c = a + b;
    cout << "The sum is : " ;
    cout << a;

    cout << endl << "Sample 2" << endl;
    a = FractionalComplex(1, 6, 2, 8);
    cout << a;
    b = FractionalComplex(-1, 4, 7, 11);
    cout << b;

    c = a + b;
    cout << "The sum is : " ;
    cout << c;
}

void section4()
{

    cout << endl << endl;
    cout << "** Section 4" << endl;
    cout << "Subtraction " << endl << endl;

    FractionalComplex a, b, c;

    cout << "Sample 1" << endl;
    a = FractionalComplex(1, 2, 4, 5);
    cout << a;
    b = FractionalComplex(1, 3, 2, 3);
    cout << b;

    c = a - b;
    cout << "The difference is : " ;
    cout << c;

    cout << endl << "Sample 2" << endl;
    a = FractionalComplex(2, 5, 3, 7);
    cout << a;
    b = FractionalComplex(1, 4, 7, 11);
    cout << b;

    c = a - b;
    cout << "The difference is : " ;
    cout << c;
}

void section5()
{

    cout << endl << endl;
    cout << "** Section 5" << endl;
    cout << "Comparisons " << endl << endl;

    FractionalComplex a, b, c, d;
    a = FractionalComplex(2, 5, 3, 7);
    b = FractionalComplex(2, 5, 3, 7);
    c = FractionalComplex(10, 25, 15, 35);
    d = FractionalComplex(10, 25, 35, 36);

    cout << a;
    cout << b;
    cout << endl << "Test 1: Are they equal? (They should be) : " ;
    if (a == b) {cout << "TRUE!" << endl;}
    else        {cout << "FALSE - Error" << endl;}

    cout << endl;

    cout << a;
    cout << c;
    cout << endl << "Test 2: Are they equal? (They should be) : " ;
    if (a == c) {cout << "TRUE!" << endl;}
    else        {cout << "FALSE - Error" << endl;}

    cout << endl;

    cout << c;
    cout << d;
    cout << endl << "Test 3: Are they equal? (They should not be) : " ;
    if (c == d) {cout << "TRUE - Error" << endl;}
    else        {cout << "FALSE!" << endl;}

    cout << endl;

    cout << c;
    cout << a;
    
    cout << endl << "Test 4: Which is bigger? ";
    if (d < a) {cout << "The First one!  Error" << endl;}
    else if (a < d) { cout << "The second one!  Good Work" << endl; }
    else {cout << "They are equal?? This is an error" << endl;}

    cout << endl;

    cout << a;
    cout << d;

    cout << endl << "Test 5: Which is smaller? ";
    if (a > d) {cout << "The second one!  Error" << endl;}
    else if (d > a) {cout << "The first one!  Good Work" << endl;}
    else {cout << "They are equal?? This is an error" << endl;}

}

void section6()
{

    cout << endl << endl;
    cout << "** Section 6" << endl;
    cout << "Cout Println " << endl << endl;

    FractionalComplex a, b;
    a = FractionalComplex(6,4,12,9);
    b = FractionalComplex(1,5,5,6);

    cout << "Testing cout a = " << a;
    cout << endl;
    cout << "Testing a chain b = " << b << " It worked! " << endl;
    cout << endl;
    cout << "Testing inline addition " << a + b << endl;
}

void section7()
{
    cout << endl << endl;
    cout << "** Section 7" << endl;
    cout << "Multiplication " << endl << endl;

    FractionalComplex a, b;
    a = FractionalComplex(1,2,3,5);
    b = FractionalComplex(1,3,2,5);

    cout << "Test #1 " << endl;
    cout << "a = " << a << endl << "b = " << b << endl;
    cout << "a * b = " << a * b << endl;

    a = FractionalComplex(-1,1,2,9);
    b = FractionalComplex(3,5,1,5);

    cout << endl << "Test #2 " << endl;
    cout << "a = " << a << endl << "b = " << b << endl;
    cout << "a * b = " << a * b << endl;

    cout << endl << "Test #3 " << endl;
    cout << "b = " << b << endl;
    cout << "b * 10 = " << b * 10 << endl;


}

void section8()
{
    cout << endl << endl;
    cout << "** Section 8" << endl;
    cout << "Pre and Post increment " << endl << endl;

    FractionalComplex a,b;
    a = FractionalComplex(1,2,1,4);

    cout << "PostFix Test" << endl;
    cout << "a = " << a << endl;
    cout << "a = " << a++ << " This should match above" << endl;
    cout << "a = " << a++ << " This should be one bigger" << endl;
    cout << "a = " << a   << " This should be one bigger" << endl;

    b = FractionalComplex(1,3,1,5);
    cout << "Prefix Test" << endl;
    cout << "a = " << b<< endl;
    cout << "a = " << ++b << " This should be one bigger" << endl;
    cout << "a = " << ++b << " This should be one bigger" << endl;
    cout << "a = " << b   << " This should match above" << endl;
}
