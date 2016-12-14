///////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  main.cpp
////// File:             Student.cpp
////// Semester:         cs368 Fall 2015
//////
////// Author:           Kevin Gao
////// CS Login:         kgao
////// Lecturer's Name:  Okan
//////
//////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
//////
////// Pair Partner:     Kenny Gao
////// Email:            kgao9@wisc.edu
////// CS Login:         kenny
////// Lecturer's Name:  Okan

#include "Student.h"
#include <iostream>
#include <stdio.h>
using namespace std;

/**
 * The purpose of this is to construct a student with a pointer of another student
 * @param student
 */

Student::Student(const Student& student)
{
    this->studentID = student.studentID;
    this->nCoursesTaken = student.nCoursesTaken;
    for(int i = 0; i < nCoursesTaken; i++) 
    {
        this->coursesTaken[i] = student.coursesTaken[i];
    }
}

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
    studentID = ID;
    nCoursesTaken = 0;

    while(courses[nCoursesTaken])
    {
        coursesTaken[nCoursesTaken] = *courses[nCoursesTaken];
        nCoursesTaken++;
    }
}

/**
 * This creates an override of the equals operator by deallocating the student and then copying the new one
 * @param new student
 * @return pointer to newly created student
 */

Student& Student::operator = (const Student& student) {
    if(this->nCoursesTaken != 0)
    {
        for(int i = 0; i < this->nCoursesTaken; i++) 
        {
            delete &this->coursesTaken[i];
        }
    }

    this->studentID = student.studentID;
    this->nCoursesTaken = student.nCoursesTaken;
    for(int i = 0; i < nCoursesTaken; i++) 
    {
        this->coursesTaken[i] = student.coursesTaken[i];
    }

    return *this;
}

/**
 * The purpose of this method is to get the student's ID
 *
 * no params
 * @return student id
 */

int Student::getID() const
{
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
    int numCreds = 0;
    for(int i = 0; i < nCoursesTaken; i++)
    {
        numCreds += coursesTaken[i].credits;
    }

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
        char gradeReceived = coursesTaken[i].studentGrade;

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

    if(nCoursesTaken != 0)
    {
        return gPA / ((double)this->getCredits());
    }

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
    CourseInfo const ** infoStructAddr = new CourseInfo const * [100];
    for(int i = 0; i < nCoursesTaken; i++) 
    {
        const CourseInfo *ptr = &coursesTaken[i];
        infoStructAddr[i] = ptr;
    }

    // infoStructAddr[nCoursesTaken] = NULL;

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
    for(int i = 0; i <  nCoursesTaken; i++)
    {
        CourseInfo getCourse = coursesTaken[i];
        int getCourseNumber = getCourse.courseNumber;
        int getYear = getCourse.year;
        Semester getSemester = getCourse.cSemester;

        bool rightCN = (getCourseNumber == courseNumber);

        if(rightCN && getYear == year && cSemester == getSemester)
        {
            return true;
        }
    }

    return false;
}

/**
 * destructor
 */
Student::~Student()
{
}
