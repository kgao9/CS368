///////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  main.cpp
////// File:             Student.h
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

#ifndef STUDENT_H
#define STUDENT_H

enum Semester {Spring, Fall};

/*
 * Course Information structure
 *
 * Stores the grade information for every course student took
 */
struct CourseInfo {
    int courseNumber;
    int credits;
    int year;
    char studentGrade;
    Semester cSemester;
};

/*
 * Student class
 *
 * A Student object contains a student ID, the number of credits, and an
 * overall GPA.
 */
class Student {
  public:

    Student(const Student& student);
    //student copy constructor

    Student();
    // Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.

    Student(int ID);
    // Constructs a student with the given ID, 0 credits, and 0.0 GPA.

    Student(int ID, CourseInfo ** courses);
    // Constructs a student with the given ID and the list of taken courses.
    // You can assume that courses pointer list will end with a NULL pointer.

    Student& operator = (const Student& student);
    //student copy operator

    // Accessors
    int getID() const;       // returns the student ID
    int getCredits() const;  // returns the number of credits
    double getGPA() const;   // returns the GPA
    CourseInfo const ** getCourses();
    // creates a list of pointers to the CourseInfo structures in the student record
    // returned list should end with a NULL pointer

    // Other methods

    void update(int courseNumber, int credits, int year, Semester cSemester, char grade);
    // Update the student record by adding a new course. You should add a new CourseInfo
    // instance to takenCourses member.

    void print() const;
    // Prints out the student to standard output in the format:
    //   ID,credits,GPA
    // Note: the end-of-line is NOT printed after the student information

    bool tookCourse(int courseNumber, int year, Semester cSemester);
    // returns true if student took the specified course

    ~Student();
    //destructor
  
private:
    int studentID;
    CourseInfo coursesTaken[100]; int nCoursesTaken;
    // You can assume that none of the students will have more than 100 courses in their record.
};

#endif
