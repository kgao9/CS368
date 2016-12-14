#include "SortedList.h"

#include <iostream>

#include "Student.h"

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
        //if head is empty, nothing is found
        return NULL;
    }

    //test if head is the only node
    if(head->student->getID() == studentID)
    {
        //match found
        return head->student;
    }

    else
    {
        //create iterator to go through list
        Listnode * itr = head;

        while(itr) 
        {
            if(itr->student->getID() == studentID)
            {
                //if found, return
                
                Student *found = itr -> student;
                itr = NULL;
                delete itr;
                return found;
            }

            else 
            {
                //if not found, go to next node
                itr = itr -> next;
            }
        }

        delete itr;
    }
    //not found at all
    return NULL;
}

/**
* The purpose of this method is to insert a student based on their id
* It returns true if insertion succeeded; false otherwise
*
* @param student to insert
* @return true if isertion succeeded; false otehrwise
*/

bool SortedList:: insert(Student *s)
{
    Listnode *newNode = new Listnode();
    newNode->student = s;
    newNode->next = NULL;

    //empty list
    if(!(head->student)) 
    {
        //just fill in head node
        head->student = s;

        //free new node
        delete newNode;

        return true;
    }
    
    //check if head is the only node
    else if(!(head->next))
    {
        //if new node is in head
        if(head -> student -> getID() == s -> getID())
        {
            //free node
            delete newNode;
            return false;
        }
        
        else
        {
            if(newNode -> student -> getID() > head -> student -> getID())
            {
                //add new node to list
                head->next = newNode;
                return true;
            }

            else
            {
                //add new node to list
                newNode -> next = head;
                head = &(*newNode);
                newNode = NULL;
                delete newNode;
                return true;
            }
        }
    }

    else 
    {
        if(find(s -> getID()))
        {
            //free node
            delete newNode;
            return false;
        }
       
        //check to see if insert to face
        if(newNode -> student -> getID() < head -> student -> getID())
        {
            //new node point to head
            newNode -> next = head;
              
            //update head
            head = &(*newNode);

            //delete new node
            newNode = NULL;
            delete newNode;
            return true;
        }

        //find out where to find node
        Listnode * iterator = head;

        while(iterator->next) 
        {
            Listnode *temp = iterator -> next;

            //if inbetween these two ids, insert
            bool big = newNode -> student -> getID() > iterator -> student -> getID();
            bool small = newNode -> student -> getID() < temp -> student -> getID();
            if(big && small)
            {
                //insert
                iterator -> next = &(*newNode);
                newNode -> next = &(*temp);

                //delete iterator, newnode and temp
                iterator = NULL;
                newNode = NULL;
                temp = NULL;

                delete iterator;
                delete newNode;
                delete temp;

                return true;
            }

            //get next node
            iterator = &(*temp);

            //free temp
            temp = NULL;
            delete temp;
        }

        //end of while
        //insert to end of list
        iterator->next = &(*newNode);
       
        //delete new node and iterator
        newNode = NULL;
        iterator = NULL;
        delete newNode;
        delete iterator;
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

    Listnode *iterator = head;

    //first off, we need to check if head points to nothing
    //if so, just replace head with a new listnode and
    //delete terator
    
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
    if(!(head -> student))
    {
        return 0;
    }

    //initialize # of studs
    int numberOfStudents = 0;

    //create iterator
    Listnode *itr = head;

    //go through linked list
    while(itr)
    {
        //count # of studs who took the course
        if(itr -> student -> tookCourse(courseNumber, inYear, inSemester))
        {
            numberOfStudents ++;
        }

        //get next node
        itr = itr -> next;
    }

    //free space
    delete itr;

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
    //get length
    int length = getNStudents(courseNumber, inYear, inSemester);
    
    //create class roster
    Student **classRoster = new Student *[length + 1];

    //gets the pos of roster
    int i = 0;

    //creates iterators
    Listnode *itr = head;

    //fills roster
    while(itr)
    {
        //if stud took course, add to roster
        if(itr -> student -> tookCourse(courseNumber, inYear, inSemester))
        {
            classRoster[i] = (itr -> student);
            i++;
        }
     
        //get the next stud
        itr = itr -> next;
    }

    //free space
    delete itr;

    //set null termintor
    classRoster[length + 1] = NULL;
    return classRoster;
}

/** 
* The purpose of this method is to print the class roster of a class
* 
* @param the course statistics
* no return
*/

void SortedList::printClassRoster(int courseNumber, int inYear, Semester inSemester)
{
    //if no students took a course, print outline
    if(getNStudents(courseNumber, inYear, inSemester) == 0)
    {
        cout << "Course " << courseNumber << " was not offered in ";
        cout << inSemester << " of " << inYear << "." << endl;
    }

    else{

        //get roster
        Student ** classRoster = getClassRoster(courseNumber, inYear, inSemester);

        //position 
        int pos = 0;

        while(classRoster[pos])
        {
            //student prints
            classRoster[pos] -> print();

            //get next position
            pos++;
        }
    }
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
                    cout << "(" << sID1 << ", " << sID2 << ")";
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
 *  * The purpose of this method is to print out the list of students
 *   *
 *    * no params
 *     * no returns
 *      */

void SortedList::print() const
{
    //if empty list, return
    if(!(head -> student))
    {
        return;
    }

    //create iterator
    Listnode *itr = head;

    //print student
    while(itr)
    {
        itr -> student -> print();
        cout << endl;
        itr = itr -> next;
    }

    delete itr;
}
