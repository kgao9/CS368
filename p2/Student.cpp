#include "Student.h"
#include <iostream>
#include <stdio.h>
using namespace std;

/*
* Course Information structure
*
* Stores the grade information for every course student took
*/


/**
* The purpose of this default constructor is to
* initialize a student with an initial ID of 0,
* a credit value of 0 and a GPA of 0.
*
* @param no params
* @return no returns
*/

//constructs default student with an ID of 0, 0 credits, and 0 GPA
Student::Student()
{
    //sets student id and amount of courses taken to 0
    studentID = 0;
    nCoursesTaken = 0;
}

/**
* The purpose of this one-param constructor
* is to initialize a student with a given ID,
* but with the same No. of credits and GPA as the
* default.
*
* @param student id
* no returns
*/

Student::Student(int ID)
{
    //sets student id
    //sets numer of courses taken to 0
    studentID = ID;
    nCoursesTaken = 0;
}

/**
* The purpose of this two-param constructor is to
* construct a student with the given ID and the list of taken courses.
* @param courseInfo list
* no returns
*/

Student::Student(int ID, CourseInfo ** courses)
{

    //sets student ID
    studentID = ID;

    //number of courses taken shall update
    nCoursesTaken = 0;

    while(courses[nCoursesTaken])
    {
        //update the courses taken array
        coursesTaken[nCoursesTaken] = *courses[nCoursesTaken];

        //update number of courses taken
        nCoursesTaken++;
    }

    //always over by one, for it included null terminator
    nCoursesTaken--;
}

/**
* The purpose of this method is to get the student's ID
*
* no params
* @return student id
*/

int Student::getID() const
{
    //returns the student ID
    return studentID;
}

/**
* The purpose of this method is to get the number of credits
* a student took
* no params
* @return the number of credits a student took
*/

int Student::getCredits() const
{
    //initialize number of creds
    int numCreds = 0;
    for(int i = 0; i < nCoursesTaken; i++)
    {
        //counts them
        numCreds += coursesTaken[i].credits;
    }

    //returns numebr of credits
    return numCreds;
}

/**
 * The purpose of this method is to get the student's GPA
 * no params
 * @return GPA
 */

double Student::getGPA() const
{
    double gPA = 0;

    int numOfCredits = 0;

    for(int i = 0; i < nCoursesTaken; i++)
    {
        //get grade received
        char gradeReceived = coursesTaken[i].studentGrade;

        //add gpa with grade received * credits

        switch(gradeReceived)
        {
            case 'A':
                gPA += 4*coursesTaken[i].credits;
                break;

            case 'B':
                gPA += 3*coursesTaken[i].credits;
                break;
    
            case 'C':
                gPA += 2*coursesTaken[i].credits;
                break;

            case 'D':
                gPA += coursesTaken[i].credits;
                break;

            case 'F':
                gPA += 0;
                break;
        }
    }

    //make sure no divides by zero
    if(nCoursesTaken != 0)
    {
        //return calculated gpa
        return gPA / ((double)this->getCredits());
    }

    //if 0, return 0
    else
    {
        return 0;
    }
}

/**
* The purpose of this method is to get a student's course history
*
* @return list of courses student took
* no params
*/

CourseInfo const ** Student::getCourses()
{
    //initialize constant pointer to array of pointers
    CourseInfo const ** infoStructAddr = new CourseInfo const * [100];
   
    //pointers point to references of values
    for(int i = 0; i < nCoursesTaken; i++) 
    {
        infoStructAddr[i] = &coursesTaken[i];
    }

    //create null terminator
    infoStructAddr[nCoursesTaken] = NULL;

    //return that array
    return infoStructAddr;
}

/**
* The purpose of this method is to update the student's record
* 
* @params grade statistics
* no returns
*/

void Student::update(int courseNumber, int credits, int year, Semester cSemester, char grade)
{

    //update
    CourseInfo updates = {courseNumber, credits, year, grade, cSemester};
    coursesTaken[nCoursesTaken] = updates;
    nCoursesTaken ++;
}

/**
* The purpose of this method is to print out a student's stats in the format:
* ID,credits,GPA
*
* no params or returns
*/

void Student::print() const
{
    //print out in format id, creds, GPA
    cout << getID() << ", " << this->getCredits() << ", " << getGPA();
}

/**
* The purpose of this method is to figure out if a student had taken
* this course
*
* @param course info
* @return true if the student took the course; false otherwise
*/

bool Student::tookCourse(int courseNumber, int year, Semester cSemester)
{
    //find out if course is in this array
    for(int i = 0; i <  nCoursesTaken; i++)
    {
        //get course
        CourseInfo getCourse = coursesTaken[i];
 
        //get stats
        int getCourseNumber = getCourse.courseNumber;
        int getYear = getCourse.year;
        Semester getSemester = getCourse.cSemester;

        //see if course number is right
        bool rightCN = (getCourseNumber == courseNumber);

        //if stats match, return true
        if(rightCN && getYear == year && cSemester == getSemester)
        {
            return true;
        }
    }

    return false;
}
