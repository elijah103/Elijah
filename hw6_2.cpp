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
Date: 10/29/20
Name: Elijah Miles
*/

/***********************************************
Author: <Elijah Miles>
Date: <10/29/20>
Purpose: <To make a class of type string* that emulates the behavior
of a vector of strings.>
Sources of Help: <Office hours>
Time Spent: <4.5 hours>
***********************************************/

#include <iostream>

using namespace std;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

/*class DynamicStringArray
This lass has types string* and int as private member variables,
and in public it has the functions needed to use an
array of strings as a dynamic array.*/
class DynamicStringArray {
public:
	DynamicStringArray();
	int getSize(void) const;
	void addEntry(string push);
	Boolean deleteEntry(string pop);
	string getEntry(int index) const;
	DynamicStringArray(const DynamicStringArray& arr);
	DynamicStringArray& operator=(const DynamicStringArray& orgArr);
	~DynamicStringArray();
	void display(void) const;
	Boolean isEmpty(void) const;
private:
	string* dynamicArray;
	int size;
};

/*main function tests the functions from the DynamicStringArray class*/
int main(int argc, char* argv[])
{
	DynamicStringArray Arr;
	Arr.display();
	cout << "Add \"entry\": " << endl;
	Arr.addEntry("entry");
	Arr.display();
	cout << "Delete \"entry\": " << endl;
	Arr.deleteEntry("entry");
	Arr.display();
	cout << "Add \"entry\": " << endl;
	Arr.addEntry("entry");
	Arr.display();
	cout << "Add \"hello\": " << endl;
	Arr.addEntry("hello");
	Arr.display();
	cout << "Add \"hi\": " << endl;
	Arr.addEntry("hi");
	Arr.display();
	cout << "Delete \"hello\": " << endl;
	Arr.deleteEntry("hello");
	Arr.display();
	cout << "Get index 1: " << endl;
	cout<<Arr.getEntry(1)<<endl;
	cout << "Make new array: " << endl;
	DynamicStringArray newArr(Arr);
	newArr.display();
	DynamicStringArray Arr2;
	cout << "Arr2 = Arr" << endl;
	Arr2 = Arr;
	cout << "Arr2 = " << endl;
	Arr2.display();
	Arr.~DynamicStringArray();
	Arr2.~DynamicStringArray();
	newArr.~DynamicStringArray();
	if (Arr.isEmpty() && Arr2.isEmpty() && newArr.isEmpty()) {
		cout << "String arrays destroyed" << endl;
	}
	return 0;
}

/*Constructor*/
DynamicStringArray::DynamicStringArray()
{
	dynamicArray = nullptr;
	size = 0;
}

/*Returns size*/
int DynamicStringArray::getSize(void) const
{
	return size;
}

/*addEntry
Creates a dynamic array one element larger
than the original array, copies all of the data from the original
array to the new array, adds the new element to the new array, increases the size,
deletes the original array, and sets the original array equal to the new array.*/
void DynamicStringArray::addEntry(string push)
{
	string* newArray;
	newArray = new string [this->size + 1];
	for (int i = 0; i < this->size; i++) {
		newArray[i] = this->dynamicArray[i];
	}
	newArray[size] = push;
	this->size++;
	delete[](this->dynamicArray);
	this->dynamicArray = newArray;
}

/*deleteEntry
Finds the string identified by the parameter, decreases the size, makes a new
array and copies the correct elements in after the deletion, sets the array equal
to the new array, frees the memory from the original array.*/
Boolean DynamicStringArray::deleteEntry(string pop)
{
	int found = 0, index, i, j;
	for (i = 0; i < size; i++) {
		if (dynamicArray[i] == pop) {
			found = 1;
			index = i;
			break;
		}
	}
	if (!found) {
		return FALSE;
	}
	else {
		string* newArray;
		newArray = new string [size - 1];
		for (i = 0, j = 0; i < size, j < size - 1; i++, j++) {
			if (i == index) {
				i++;
			}
			newArray[j] = dynamicArray[i];
		}
		size--;
		delete[] dynamicArray;
		dynamicArray = newArray;
		return TRUE;
	}
}

/*getEntry
Returns the string identified by the parameter index*/
string DynamicStringArray::getEntry(int index) const
{
	if (index < size && index >= 0) {
		return dynamicArray[index];
	}
	else {
		return nullptr;
	}
}

/*Copy constructor
Makes new memory for an array, copies the elements from the original array to the 
new array, sets the calling object's array equal to the new array, sets the
calling objects size equal to thet original array's size.*/
DynamicStringArray::DynamicStringArray(const DynamicStringArray& arr)
{
	int arrSize = arr.getSize();
	if (!arr.isEmpty()) {
		string* newArray = new string [arrSize];
		for (int i = 0; i < arrSize; i++) {
			newArray[i] = arr.getEntry(i);
		}
		dynamicArray = newArray;
	}
	else {
		dynamicArray = nullptr;
	}
	size = arrSize;
}

/*Overloaded assignment operator
If the two arrays are equal, returns the calling object. Frees the memory
from the calling object. Makes a new array, sets the data equal to the original
array, sets the calling object equal to the new array, returns the
calling object.*/
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& orgArr)
{
	if (dynamicArray == orgArr.dynamicArray) {
		return *this;
	}
	if (dynamicArray != nullptr) {
		delete[]dynamicArray;
		dynamicArray = nullptr;
	}
	int arrSize = orgArr.getSize();
	if (!orgArr.isEmpty()) {
		string* newArray = new string[arrSize];
		for (int i = 0; i < arrSize; i++) {
			newArray[i] = orgArr.getEntry(i);
		}
		dynamicArray = newArray;
	}
	size = arrSize;
	return *this;
}

/*Destructor
Frees the memory from dynamicArray, sets dynamicArray to nullptr.*/
DynamicStringArray::~DynamicStringArray()
{
	delete[]dynamicArray;
	dynamicArray = nullptr;
}

/*Display
Displays the data and size of the calling object*/
void DynamicStringArray::display(void) const
{
	for (int i = 0; i < size; i++) {
		cout << dynamicArray[i] << endl;
	}
	if (size <= 0) {
		cout << endl;
	}
	cout << "Size: " << size << endl;
}

/*Checks to see if the calling object is empty.*/
Boolean DynamicStringArray::isEmpty(void) const
{
	if (dynamicArray == nullptr) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}