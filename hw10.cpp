/***********************************************
Author: <Elijah Miles>
Date: <11/22/20>
Purpose: <To test functions given in the PFArrayD class, and make
another class that handles exceptions.>
Sources of Help: <Introduction to C++.>
Time Spent: <2.5 hours>
***********************************************/

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 11/22/20
Name: Elijah Miles
*/

#include <iostream>
#include <string>

using namespace std;

void testPFArrayD(void);

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    PFArrayD();
    //Initializes with a capacity of 50.

    PFArrayD(int capacityValue);

    PFArrayD(const PFArrayD& pfaObject);

    void addElement(double element);
    //Precondition: The array is not full.
    //Postcondition: The element has been added.

    bool full() const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.

    int getCapacity() const { return capacity; }

    int getNumberUsed() const { return used; }

    void emptyArray() { used = 0; }
    //Empties the array.

    double& operator[](int index);
    //Read and change access to elements 0 through numberUsed - 1.

    PFArrayD& operator =(const PFArrayD& rightSide);

    ~PFArrayD();
private:
    double* a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.

};

/*class OutOfRange
Class to test the exception if the index is out of range.
Contains the index and an error message as private members.
*/

class OutOfRange
{
public:
    OutOfRange(int Int, string String) :varInt(Int), varString(String) {}
    int index(void) const { return varInt; }
    string err(void) const { return varString; }
private:
    int varInt;
    string varString;
};

void testException(void);

/*
main function calls testPFArrayD
*/

int main(int argc, char* argv[])
{
    testException();
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do
    {
        testPFArrayD();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));
    return 0;
}

/*
void testPFArrayD()
Tests the functions in the PFArrayD class.
*/

void testPFArrayD()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full()))
    {
        temp.addElement(next);
        cin >> next;
    }
    cout << "You entered the following "
        << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

/*
PFArrayD::PFArrayD()
default constructor
*/

PFArrayD::PFArrayD() :capacity(50), used(0)
{
    a = new double[capacity];
}

/*
PFArrayD::PFArrayD(int capacityValue)
capacityValue constuctor
*/

PFArrayD::PFArrayD(int capacityValue) : capacity(capacityValue), used(0)
{
    a = new double[capacity];
}

/*
PFArrayD::PFArrayD(const PFArrayD& pfaObject)
copy constructor
*/

PFArrayD::PFArrayD(const PFArrayD& pfaObject):capacity(pfaObject.getCapacity()),
used(pfaObject.getNumberUsed())
{
    a = new double[capacity];
    for (int i = 0; i < used; i++) {
        a[i] = pfaObject.a[i];
    }
}

/*
void PFArrayD::addElement(double element)
Adds an element, checks to see if the array is full.
*/

void PFArrayD::addElement(double element)
{
    try {
        if (used >= capacity) {
            throw OutOfRange(element, "The array is full, attempted to add element: ");
        }
        a[used] = element;
        used++;
    }
    catch (OutOfRange Err) {
        cout << Err.err() << Err.index() << endl;
    }
}

/*
double& PFArrayD::operator[](int index)
Overloaded [] operator to return the element at the index,
checks to see if the index is out of range.
*/

double& PFArrayD::operator[](int index)
{
    try {
        if (index < 0) {
            throw OutOfRange(index, "Index is negative. The negative index is: ");
        }
        else if (index >= used) {
            throw OutOfRange(index, "Index is out of range. The out of range index is: ");
        }
        return a[index];
    }
    catch (OutOfRange Err) {
        cout << Err.err() << Err.index() << endl;
    }
}

/*
PFArrayD& PFArrayD::operator=(const PFArrayD& rightSide)
overloaded = operator
*/

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
    if (capacity != rightSide.capacity) {
        delete[]a;
        a = new double(rightSide.capacity);
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++) {
        a[i] = rightSide.a[i];
    }
    return *this;
}

/*
PFArrayD::~PFArrayD()
destructor
*/

PFArrayD::~PFArrayD()
{
    delete[] a;
}

/*
void testException(void)
Tests the exceptions from the functions that add an element and
retrieve a value from an index.
*/

void testException(void)
{
    cout << "Test exception:\nUsing default constructor. ";
    PFArrayD Arr;
    cout << "Filling up array." << endl;
    for (int i = 0; i < 50; i++) {
        Arr.addElement(i);
    }
    cout << "Attempting to add another element. Enter an element: ";
    int userEl;
    cin >> userEl;
    Arr.addElement(userEl);
    cout << "Attempting to access element at index 50." << endl;
    double El = Arr[50];
    cout << "Attempting to access element at index -1." << endl;
    El = Arr[-1];
    cout << "The capacity of the array was: " << Arr.getCapacity() << endl;
}