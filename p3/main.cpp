///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            Student DB Memory Leakage
//// Files:            Student.h, Student.cpp, SortedList.cpp, SortedList.h
//// Semester:         cs 368 Fall 2015
////
//// Author:           Kenny Gao
//// Email:            kgao9@wisc.edu
//// CS Login:         kenny
//// Lecturer's Name:  Prof. Okan
//// Lab Section:      Lec 1
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
//// Lecturer's Name:  Prof. Okan
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


/**
*
* Differences between this and p3:
* 136 bytes certainly leaked
* 144 bytes might've leaked
*
* Also has an unconditionally jump bug that we couldn't debug
*/

#include "Student.h"
#include "SortedList.h"
#include <iostream>
using namespace std;

int main()
{
    //uses default constructor
    Student firstCase();
    
    //uses second constructor
    Student secondCase(100000);

    //test print
    secondCase.print();
    cout << endl;

    //creates courses
    CourseInfo math = {421, 3, 2015, 'B', Fall};
    CourseInfo eCE = {352, 3, 2015, 'A', Fall};

    //create course array of pointers
    CourseInfo ** courses = new CourseInfo *[3];
    courses[0] = &math;
    courses[1] = &eCE;
    courses[2] = NULL;

    //tests third constructor
    Student thirdCase(100011, courses);
    thirdCase.print();
    cout << endl;

    //tests getID and getGPA()
    cout << thirdCase.getID() << endl;
    cout << thirdCase.getGPA() << endl;

    //tests get Courses
    CourseInfo const** temp = thirdCase.getCourses();

    cout << temp << endl;

    //tests update
    thirdCase.update(119, 4, 2015, Fall, 'B');

    //test print
    thirdCase.print();

    //tests tookcourse
    thirdCase.tookCourse(421, 2015, Fall);

    //tests copy operator
    Student copy;
    copy = thirdCase;
    
    //tests copy operator
    Student copy1 = thirdCase;

    //deallocate memory in main
    delete []temp;

    delete []courses;

    //testing sorted list
    Student *yourFace = new Student(100000);
    Student *tough = new Student(100001);
    Student *fun = new Student(999999);
    Student *lagging = new Student(665665);
    Student *savage = new Student(665665);

    //create arrays
    int a[] = {665665, 665665, 999999, 100001, 1000000};
    int b[] = {665665, 999999, 100001, 1000000};

    //test default constructor
    SortedList *crap = new SortedList();

    //test print classmates without any students
    crap -> printClassmates(a, 5);
    
    //tests insert and remove
    crap -> insert(lagging);
    crap -> insert(savage);
    crap -> remove(665665);
    crap -> insert(tough);
    crap -> insert(lagging);
    crap -> insert(fun);
    crap -> insert(yourFace);

    //test print classmates with students
    crap -> printClassmates(b, 4);
    crap -> printClassmates(a,5);

    //test find
    crap -> find(665665);
 
    //test print
    crap -> print();
    cout << endl;

    //test print class roster, get class roster, getNstudents
    crap -> printClassRoster(119, 2015, Fall);

    //update
    lagging -> update(119, 4, 2015, Fall, 'B');
    yourFace -> update(119, 4, 2015, Fall, 'B');
    tough -> update(119, 4, 2015, Fall, 'B');
    fun -> update(119, 4, 2015, Fall, 'B');

    cout << "\n\n\n" << endl;

    //test classmates again with actual classmates
    crap -> print();
    crap -> printClassmates(a,5);

    //test with actual students
    crap -> printClassRoster(119, 2015, Fall);

    //test operator
    SortedList listCopy;

    listCopy = *crap;

    listCopy.print();
    cout << endl;
    crap -> print();

    cout << "done" << endl;
    
    //test copy constructor
    SortedList copyList1 = listCopy;

    delete crap;
    delete yourFace;
    delete tough;
    delete fun;
    delete lagging;
    delete savage;

    //cout deleted everything
    cout << "deleted everything" << endl;

    return 0;
}
