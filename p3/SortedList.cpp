///////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  main.cpp
////// File:             SortedList.cpp
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
#include "SortedList.h"

#include <iostream>

#include "Student.h"
#include "SortedList.h"

using namespace std;

/**
 * The purpose of this constructor is to initialize a list of students
 * no parameters
 * no returns
 */


SortedList::SortedList()
{
    //constructs empty list
    head = new Listnode();

}

/**
 * Constructs new list using list pointer
 * @param pointer to a list
 */

SortedList::SortedList(const SortedList& list)
{
    this -> head = copyList(list.head);

    Listnode *temp = list.head;
    Listnode *itr = this -> head;

    while(temp->next)
    {
        itr -> next = copyList(temp -> next);
        itr = itr -> next;
        temp = temp -> next;
    }
}

/**
 * The purpose of this method is to deallocate and recreate a new list
 * @param reference to another list
 * @return reference to newly created list
 */

SortedList& SortedList::operator = (const SortedList& list) 
{
    this -> freeList(this -> head);
    
    this -> head = copyList(list.head);

    Listnode *temp = list.head;
    Listnode *itr = this -> head;

    while(temp->next)
    {
        itr -> next = copyList(temp -> next);
        itr = itr -> next;
        temp = temp -> next;
    }

    return *this;
}

/**
 * The purpose of this method is to find a student based on their id
 *
 * @param studentID to find
 * @return student found; NULL if not found
 */

Student * SortedList::find(int studentID)
{
    //test if head is empty
    if(!(head -> student))
    {
        return NULL;
    }

    if(head->student->getID() == studentID)
    {
        return head->student;
    }

    else
    {
        Listnode * itr = head;

        while(itr)
        {
            if(itr->student->getID() == studentID)
            {
                return itr->student;
            }

            else
            {
                itr = itr -> next;
            }
        }
    }

    return NULL;
}

/**
 * used to free the list
 * @param head of list
 */

void SortedList::freeList (Listnode * l) 
{
    Listnode * temp;

    while(l)
    {
        temp = l->next;
	delete l;
        l = temp;
	
    }
}

/**
 * The purpose of this method is to create a list using a copy of the previous list
 * @param list
 * @return pointer to new list
 */
SortedList::Listnode * SortedList::copyList(Listnode *list)
{
    Listnode *copyHead = new Listnode();
    copyHead->student = list -> student;
    
    return copyHead;
}

/**
 * The purpose of this method is to insert a student based on their id
 * It returns true if insertion succeeded; false otherwise
 *
 * @param student to insert
 * @return true if isertion succeeded; false otehrwise
 */

bool SortedList::insert(Student *s)
{
    Listnode *newNode = new Listnode();
    newNode->student = s;
    newNode->next = NULL;

    if(find(s -> getID()))
    {
        freeList(newNode);
        return false;
    }

    else if(!(head->student))
    {
        head->student = s;
        freeList(newNode);

        return true;
    }

    //check if new node is in head
    else if(!(head->next))
    {
        if(head -> student -> getID() == s -> getID())
        {
            freeList(newNode);
            return false;
        }

        else
        {
            if(head->student->getID() < s->getID()) 
            {
                head->next = newNode;
                return true;
            }

            else
            {
                Listnode *temp = head;
                head = newNode;
                newNode->next = temp;
                return true;
            }
        }
    }

    else
    {
        Listnode * iterator = head;
        while(iterator->next)
        {
            if(iterator->next->student->getID() > s->getID())
            {
                Listnode *temp = iterator->next;
                iterator->next = newNode;
                newNode->next = temp;
                return true;
            }

            iterator = iterator->next;
        }

        iterator->next = newNode;
        return true;
    }
}
/**
 * The purpose of this method is to remove a student based upon their id
 *
 * @param studentID
 * @return the student removed or null if not found
 */

Student * SortedList::remove(int studentID)
{
    //test to see if student id is found
    if(!find(studentID))
    {
        return NULL;
    }

    //if removing first node, head must be updated.
    Listnode *iterator = head;

    //first off, we need to check if head points to nothing
    //if so, just replace head with a new listnode and
    //delete iterator

    if(!(head -> next))
    {
        head = new Listnode();
        Student *hopeNoSegFault = &*(iterator -> student);
        iterator -> student = NULL;
        delete iterator;
        return hopeNoSegFault;
    }

    else if(iterator -> student -> getID() == studentID)
    {
        head = head -> next;
        Student *hopeNoSegFault = &*(iterator -> student);
        iterator -> student = NULL;
        delete iterator;
        return hopeNoSegFault;
    }

    else
    {
        while(iterator)
        {
            if(iterator -> next -> student -> getID() == studentID)
            {
                Listnode *temp = iterator -> next;
                iterator -> next = temp -> next;
                Student *hopeNoSegFault = &*(temp -> student);
                delete temp;
                return hopeNoSegFault;
            }

            else
            {
                iterator = iterator -> next;
            }
        }

        return NULL;
    }
}


/**
 * The purpose of this method is to get the number of students who took a specific
 * course.
 *
 * @param course information
 * @return the number of people who took the course
 */

int SortedList::getNStudents (int courseNumber, int inYear, Semester inSemester)
{
    int numberOfStudents = 0;

    Listnode *itr = head;

    while(itr)
    {
        if(itr -> student -> tookCourse(courseNumber, inYear, inSemester))
        {
            numberOfStudents ++;
        }
    
        itr = itr -> next;
    }

    return numberOfStudents;
}

/**
 * The purpose of this method is to return a list of students who took a particular class
 *
 * @param the course statistics
 * @return list of students who took the specified course
 */

Student ** SortedList::getClassRoster(int courseNumber, int inYear, Semester inSemester)
{
    int length = getNStudents(courseNumber, inYear, inSemester);

    Student **classRoster = new Student *[length + 1];

    int i = 0;

    Listnode *itr = head;

    while(itr)
    {
        if(itr -> student -> tookCourse(courseNumber, inYear, inSemester))
        {
            classRoster[i] = (itr -> student);
            i++;
        }

        itr = itr -> next;
    }

    return classRoster;
}

/**
 * THe purpose of this method is to print the class roster of a class
 *
 * @param the course statistics
 * no return
 */

void SortedList::printClassRoster(int courseNumber, int inYear, Semester inSemester)
{
    if(getNStudents(courseNumber, inYear, inSemester) == 0)
    {
        cout << "Course " << courseNumber << " was not offered in ";
        cout << inSemester << " of " << inYear << "." << endl;
        return;
    }

    Student ** classRoster = getClassRoster(courseNumber, inYear, inSemester);

    int pos = 0;

    while(classRoster[pos])
    {
        classRoster[pos] -> print();
        pos++;
    }
    

    delete []classRoster;
    
}

/**
 * The purpose of this method is to print out pairs of classmates who have taken a course together
 *
 * @param list of students, and the list's length
 * no returns
 */

void SortedList::printClassmates(int * studentGroup, int nStudents)
{
    bool pairFound = false;
    bool notEmpty = false;

    //create new sorted list
    SortedList sortedStudentGroup = SortedList();

    // for every student in database, add to sorted list
    for(int i = 0; i < nStudents; i++)
    {
        Student *found = find(studentGroup[i]);

        if(found)
        {
            sortedStudentGroup.insert(found);
        }
    }

    if(!notEmpty)
    {
        cout << "Cannot find a valid pair." << endl;
        return;
    }

    // for every student in database, find out if they were ever class mates
    for(int i = 0; i < nStudents; i++)
    {
        //get student id
        int sID1 = studentGroup[i];

        for(int j = i + 1;j < nStudents; j++)
        {
            //get next stud's id
            int sID2 = studentGroup[j];

            //get their corresponding student objects
            Student *one = sortedStudentGroup.find(sID1);
            Student *two = sortedStudentGroup.find(sID2);

            //get one's courses
            CourseInfo const ** oneCourses = one -> getCourses();

            int k = 0;

            bool classmates = false;

            //get courses
            while(oneCourses[k])
            {
                //get stats
                int courseNumber = oneCourses[k] -> courseNumber;
                int year = oneCourses[k] -> year;
                Semester cSemester = oneCourses[k] -> cSemester;

                //see if second stud took course
                //if did, they were classmates
                if(two -> tookCourse(courseNumber, year, cSemester))
                {
                    classmates = true;
                    break;
                }

                k++;
            }

            //if they were classmates
            if(classmates)
            {
                //print out
                if(sID1 < sID2)
                {
                    cout << "(" << sID1 << ", " << sID2 << ")" << endl;
                    pairFound = true;
                }
            }
        }
    }

    if(!pairFound)
    {
        cout << "Cannot find a valid pair." << endl;
    }
}

/**
 * The purpose of this method is to print out the list of students
 *
 * no params
 * no returns
 */

void SortedList::print() const
{
    if(!(head -> student))
    {
        return;
    }

    Listnode *itr = head;


    while(itr)
    {
        itr -> student -> print();
        itr = itr -> next;
    }
}

SortedList::~SortedList() 
{
    this->freeList(this->head);
}

