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
Date: 11/8/20
Name: Elijah Miles
*/

/***********************************************
Author: <Elijah Miles>
Date: <11/8/20>
Purpose: <To use the functions we've learned in class 
(constructors, overloading) on the three classes person,
vehicle, and truck.>
Sources of Help: <stackoverflow>
Time Spent: <5 hours>
***********************************************/

#include <iostream>
#include <string>

using namespace std;

/*
class Person
public section contains constructors, getters and setters,
overloaded assignment, extraction and insertion. Private
contains name.
*/

class Person
{
public:
    Person();
    Person(string theName);
    Person(const Person& theObject);
    string getName() const;
    void setName(string theName);
    Person& operator=(const Person& rtSide);
    friend istream& operator >>(istream& inStream, Person& personObject);
    friend ostream& operator <<(ostream& outStream, const Person&
        pObject);
private:
    string name;
};

istream& operator >>(istream& inStream, Person& personObject);
ostream& operator <<(ostream& outStream, const Person&
    pObject);

/*
class Vehicle
public section contains constructors, setters and getters,
overloaded assignment and insertion operators, protected contains
name, cylinders, owner.
*/

class Vehicle
{
public:
    Vehicle();
    Vehicle(string theName);
    Vehicle(string theName, int theCyllinders);
    Vehicle(string theName, int theCyllinders, Person Object);
    Vehicle(const Vehicle& theObject);
    string getName(void) const;
    int getCyllinders(void) const;
    Person getPerson(void) const;
    void setName(string Name);
    void setCylinders(int Cylinders);
    void setOwner(Person Owner);
    Vehicle& operator=(const Vehicle& rtSide);
    friend ostream& operator<<(ostream& outStream, const Vehicle& 
        pObject);
private:
    string name;
    int cyllinders;
    Person owner;
};

ostream& operator<<(ostream& outStream, const Vehicle&
    pObject);

/*
class Truck : public Vehicle
derived class from Vehicle. Public section contains constructors,
overloaded assignment and insertion functions. Private contains load and tow.
*/

class Truck : public Vehicle
{
public:
    Truck();
    Truck(double theLoad);
    Truck(double theLoad, int theTow);
    Truck(double theLoad, int theTow, string theName, int theCylinders, Person theOwner);
    Truck(const Truck& theObject);
    double getLoad(void) const;
    int getTow(void) const;
    Truck& operator=(const Truck& rtSide);
    friend ostream& operator<<(ostream& outStream, const Truck&
        pObject);
private:
    double load;
    int tow;
};

ostream& operator<<(ostream& outStream, const Truck&
    pObject);

/*
main function tests the member functions of the three classes.
*/

int main(int argc, char* argv[])
{
    cout << "/////////////////// Testing Person Class ////////////////////" << endl;
    cout << "Testing default constructor: the person is: ";
    Person P;
    cout << P;
    cout << "Testing constructor(string): I am: ";
    Person A("Elijah Miles");
    cout << A;
    cout << "Testing copy constructor: another me is: ";
    Person B(A);
    cout << B;
    cout << "Testing >> overloading: Enter your name: ";
    cin >> B;
    cout << "You're: " << B;
    cout << "Testing = overloading: Another you is: ";
    Person C;
    C = B;
    cout << C;
    cout << endl << endl << "//////////////////////"; 
    cout << " Testing Vehicle Class ///////////////////////" << endl;
    cout << "Testing default constructor: The vehicle is:"<<endl<<'\t';
    Vehicle car;
    cout << car;
    cout << "Testing constructor(args) for my car:"<<endl<<'\t';
    Vehicle myCar("Sedan", 8, C);
    cout << myCar;
    cout << "Testing copy constructor: My second same car:"<<endl<<'\t';
    Vehicle myCar2(myCar);
    cout << myCar2;
    cout << "Testing = overloading:" << endl<<'\t'<<"Your car is: ";
    Person pers("John Smith");
    Vehicle newCar("Toyota", 10, pers);
    cout << newCar;
    cout << "\tYourSecondCar is: ";
    Vehicle newCar2;
    newCar2 = newCar;
    cout << newCar2;
    cout << endl << endl << "//////////////////////";
    cout << " Testing Truck Class ///////////////////////" << endl;
    Truck aTruck;
    cout << "Testing default constructor: the truck is:" << endl << '\t';
    cout << aTruck;
    cout << "Testing constructor(args) for a truck:" << endl << '\t';
    Person Mike("Mike Elf");
    Truck T(250, 2000,"Mac",8,Mike);
    cout << T;
    cout << "Testing copy constructor: copied truck:" << endl << '\t';
    Truck t(T);
    cout << t;
    cout << "Testing = overloading:" << endl << '\t' << "his Truck is: ";
    Truck newTruck(200, 5000, "Toyota Truck", 8, pers);
    cout << newTruck;
    cout << "\this same Truck is: ";
    Truck hisTruck;
    hisTruck = newTruck;
    cout << hisTruck;
	return 0;
}

/*
default constructor
*/

Person::Person():name("none")
{
}

/*
string constructor
*/

Person::Person(string theName):name(theName)
{
}

/*
copy constructor
*/

Person::Person(const Person& theObject):name(theObject.name)
{
}

/*
getter
*/

string Person::getName(void) const
{
    return name;
}

/*
setter
*/

void Person::setName(string theName)
{
    name = theName;
}

/*
assignment operator
*/

Person& Person::operator=(const Person& rtSide)
{
    (*this).name = rtSide.name;
    return *this;
}

/*
overloaded insertion operator uses getline
*/

istream& operator >>(istream& inStream, Person& personObject)
{
    getline(inStream, personObject.name);
    return inStream;
}

/*
overloaded extraction operator
*/

ostream& operator <<(ostream& outStream, const Person&
    pObject)
{
    outStream << pObject.name << endl;
    return outStream;
}

/*
default constructor
*/

Vehicle::Vehicle():name("Unknown Manufactury"),cyllinders(0)
{
    owner.setName("Unkown Owner");
}

/*
string constructor
*/

Vehicle::Vehicle(string theName):name(theName),cyllinders(0)
{
    owner.setName("Unkown Owner");
}

/*
string, cyllinder constructor
*/

Vehicle::Vehicle(string theName, int theCyllinders):name(theName),cyllinders(theCyllinders)
{
    owner.setName("Unkown Owner");
}

/*
string, cyllinder, person constructor
*/

Vehicle::Vehicle(string theName, int theCyllinders, Person Object) :name(theName), cyllinders(
    theCyllinders),owner(Object)
{
}

/*
copy constructor
*/

Vehicle::Vehicle(const Vehicle& theObject):name(theObject.name),cyllinders(theObject.cyllinders),
owner(theObject.owner)
{
}

/*
getName
*/

string Vehicle::getName(void) const
{
    return name;
}

/*
getCyllinders
*/

int Vehicle::getCyllinders(void) const
{
    return cyllinders;
}

/*
getPerson
*/

Person Vehicle::getPerson(void) const
{
    return owner;
}

/*
setName
*/

void Vehicle::setName(string Name)
{
    name = Name;
}

/*
setCylinders
*/

void Vehicle::setCylinders(int Cylinders)
{
    cyllinders = Cylinders;
}

/*
setOwner
*/

void Vehicle::setOwner(Person Owner)
{
    owner = Owner;
}

/*
assignment operator
*/

Vehicle& Vehicle::operator=(const Vehicle& rtSide)
{
    (*this).name = rtSide.name;
    (*this).cyllinders = rtSide.cyllinders;
    (*this).owner = rtSide.owner;
    return *this;
}

/*
overloaded insertion
*/

ostream& operator<<(ostream& outStream, const Vehicle&
    pObject)
{
    outStream << pObject.name <<", "<< pObject.cyllinders<<
        " cylinders, belongs to: "<<
        pObject.owner.getName() << endl;
    return outStream;
}

/*
default constructor
*/

Truck::Truck():load(0),tow(0)
{
}

/*
load constructor
*/

Truck::Truck(double theLoad):load(theLoad),tow(0)
{
}

/*
load, tow constructor
*/

Truck::Truck(double theLoad, int theTow):load(theLoad),tow(theTow)
{
}

/*
copy constructor
*/

Truck::Truck(const Truck& theObject):load(theObject.load),tow(theObject.tow),
Vehicle(theObject.getName(),theObject.getCyllinders(),theObject.getPerson())
{
}

/*
getter
*/

double Truck::getLoad(void) const
{
    return load;
}

/*
getter
*/

int Truck::getTow(void) const
{
    return tow;
}

/*
overloaded assignment operator
*/

Truck& Truck::operator=(const Truck& rtSide)
{
    (*this).load = rtSide.load;
    (*this).tow = rtSide.tow;
    (*this).setName(rtSide.getName());
    (*this).setCylinders(rtSide.getCyllinders());
    (*this).setOwner(rtSide.getPerson());
    return *this;
}

/*
overloaded insertion operator
*/

ostream& operator<<(ostream& outStream, const Truck&
    pObject)
{
    outStream <<pObject.getName()<<", "<<pObject.getCyllinders()<<
        " cylinders, belongs to: "<<pObject.getPerson().getName()<<
        ", load capacity: "<< pObject.load<<", towing capacity: "<<
        pObject.tow << endl;
    return outStream;
}

/*
constructor with vehicle
*/

Truck::Truck(double theLoad, int theTow, string theName, int theCylinders,
    Person theOwner):load(theLoad),tow(theTow),Vehicle(theName, theCylinders, theOwner)
{
}