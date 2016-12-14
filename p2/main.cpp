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

    secondCase.print();
    cout << endl;

    CourseInfo math = {421, 3, 2015, 'B', Fall};
    CourseInfo eCE = {352, 3, 2015, 'A', Fall};

    CourseInfo *mathp = &math;
    CourseInfo *eCEp = &eCE;

    CourseInfo ** courses = new CourseInfo *[3];
    courses[0] = &math;
    courses[1] = &eCE;
    courses[2] = NULL;

    Student thirdCase(100011, courses);
    thirdCase.print();
    cout << endl;

    cout << thirdCase.getID() << endl;
    cout << thirdCase.getGPA() << endl;

    CourseInfo const** temp = thirdCase.getCourses();

    cout << temp << endl;

    thirdCase.update(119, 4, 2015, Fall, 'B');

    thirdCase.print();

    thirdCase.tookCourse(421, 2015, Fall);

    Student copy;

    copy = thirdCase;

    Student copy1 = thirdCase;

    delete []temp;

    delete []courses;

    //testing sorted list
    Student *yourFace = new Student(100000);
    Student *tough = new Student(100001);
    Student *fun = new Student(999999);
    Student *lagging = new Student(665665);
    Student *savage = new Student(665665);

    int a[] = {665665, 665665, 999999, 100001, 1000000};

    int b[] = {665665, 999999, 100001, 1000000};

    SortedList *crap = new SortedList();

    crap -> printClassmates(a, 5);

    crap -> insert(lagging);
    crap -> insert(savage);
    crap -> remove(665665);
    crap -> insert(tough);
    crap -> insert(lagging);
    crap -> insert(fun);
    crap -> insert(yourFace);

    crap -> printClassmates(b, 4);
    crap -> printClassmates(a,5);

    crap -> find(665665);
 
    crap -> print();
    cout << endl;

    crap -> printClassRoster(119, 2015, Fall);

    lagging -> update(119, 4, 2015, Fall, 'B');
    yourFace -> update(119, 4, 2015, Fall, 'B');
    tough -> update(119, 4, 2015, Fall, 'B');
    fun -> update(119, 4, 2015, Fall, 'B');

    cout << "\n\n\n" << endl;

    crap -> print();
    crap -> printClassmates(a,5);

    crap -> printClassRoster(119, 2015, Fall);

    SortedList listCopy;

    listCopy = *crap;

    listCopy.print();
    cout << endl;
    crap -> print();

    cout << "done" << endl;
    
    SortedList copyList1 = listCopy;

    delete crap;
    delete yourFace;
    delete tough;
    delete fun;
    delete lagging;
    delete savage;

    cout << "deleted everything" << endl;

    return 0;
}
