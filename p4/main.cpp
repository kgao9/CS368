///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            ComplexNumbers
//// Files:            ComplexNumber.cpp, ComplexNumber.h
//// Semester:         CS368 Fall 2015
////
//// Author:           Kenny Gao
//// Email:            kgao9@wisc.edu
//// CS Login:         kenny
//// Lecturer's Name:  Okan
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
////                   CHECK ASSIGNMENT PAGE TO see IF PAIR-PROGRAMMING IS ALLOWED
////                   If pair programming is allowed:
////                   1. Read PAIR-PROGRAMMING policy (in cs302 policy) 
////                   2. choose a partner wisely
////                   3. REGISTER THE TEAM BEFORE YOU WORK TOGETHER 
////                      a. one partner creates the team
////                      b. the other partner must join the team
////                   4. complete this section for each program file.
////
//// Pair Partner:     Kevin Gao
//// Email:            kxgao@wisc.edu
//// CS Login:         kgao
//// Lecturer's Name:  Okan
////
////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
////                   must fully acknowledge and credit those sources of help.
////                   Instructors and TAs do not have to be credited here,
////                   but tutors, roommates, relatives, strangers, etc do.
////
//// Persons:          Identify persons by name, relationship to you, and email.
////                   Describe in detail the the ideas and help they provided.
////
//// Online sources:   avoid web searches to solve your problems, but if you do
////                   search, be sure to include Web URLs and description of 
////                   of any information you find.
////////////////////////////// 80 columns wide //////////////////////////////////

#include <iostream>
#include "ComplexNumber.h"

int main()
{
    ComplexNumber *turk = new ComplexNumber();
    ComplexNumber *thanksgivingProgrammingSucks = new ComplexNumber(6.3, 3.14);

    ComplexNumber testCopy;
    testCopy = *thanksgivingProgrammingSucks;

    cout << *turk << endl;
    cout << *thanksgivingProgrammingSucks << endl;

    turk -> print();
    cout << endl;

    testCopy.print();
    cout << endl;
    thanksgivingProgrammingSucks -> print();
    cout << endl;
    //print methods and constructors work
    cout << "end of constructor testing" << endl;

    //start of system test
    cout << "start of system test\n\n" << endl;

    ComplexNumber firstChoice;
    ComplexNumber secondChoice;

    cout << "Please enter the first complex number, please." << endl;
    cin >> firstChoice;

    cout << "Please enter the second complex number, please." << endl;
    cin >> secondChoice;

    cout << "for C1 = ";
    firstChoice.print(); 
    cout << " and C2 = ";
    secondChoice.print();
    cout << " :" << endl;

    cout << "C1 + C2 = ";

    ComplexNumber addSum = firstChoice + secondChoice;
    addSum.print();
    cout << endl;
   

    cout << "C1 - C2 = ";
    
    ComplexNumber subSum = firstChoice - secondChoice;
    subSum.print();
    cout << endl;

    cout << "C1 * C2 = ";

    ComplexNumber prod = firstChoice * secondChoice;
    prod.print();
    cout << endl;

    cout << "C1 == C2 is ";

    if(firstChoice == secondChoice)
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "false" << endl;     
    }

    cout << "C1 != C2 is ";
    if(firstChoice != secondChoice)
    {
        cout << "true" << endl;
    }
  
    else
    {
        cout << "false" << endl;
    }

    ComplexNumber temp;
    temp = firstChoice;

    cout << "After C1 += C2, C1 = ";
    firstChoice += secondChoice;
    firstChoice.print();
    cout << endl;

    firstChoice = temp;

    cout << "After C1 -= C2, C1 = ";
    firstChoice -= secondChoice;
    firstChoice.print();
    cout << endl;

    firstChoice = temp;
    
    cout << "After C1 *= C2, C1 = ";
    firstChoice *= secondChoice;
    firstChoice.print();
    cout << endl;

    //free vars
    delete turk;
    delete thanksgivingProgrammingSucks;

    return 0;
}
