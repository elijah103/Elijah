/***********************************************
Author: <Elijah Miles>
Date: <12/1/20>
Purpose: <To generate all permutations of a list of
strings that is entered by the user.>
Sources of Help: <
https://www.geeksforgeeks.org/permutations-of-a-given-string-using-stl/
https://stackoverflow.com/questions/4877504/how-can-i-remove-duplicate-values-from-a-list-in-c
https://www.cplusplus.com/reference/list/list/
>
Time Spent: <3 hours>
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
Date: 12/1/20
Name: Elijah Miles
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <sstream>

using namespace std;

list<string> generate_permutations(list<string> &InputList);
void print_permutations(list<string> &Permutations);

/*
main function can not be changed
*/

int main(int argc, char* argv[])
{
    list<string> inputList;
    string aLine, aString;
    // read in strings from stdin
    cout << "Enter strings, separated by a space:";
    getline(cin, aLine); //read a line from keyboard
    istringstream iss(aLine); //convert aLine to an istringstream obj
    //parse each string
    while (iss >> aString)
    {
        inputList.push_back(aString);
    }

    auto permutations = generate_permutations(inputList);

    // print permutations to stdout
    print_permutations(permutations);

	return 0;
}

/*
generate_permutations
Uses sort and unique to prepare the list for generating permutations,
then uses next permutation to put each permutation into a list of strings that
it returns.
*/

list<string> generate_permutations(list<string> &InputList)
{
    InputList.sort();
    InputList.unique();
    string s;
    list<string> l;
    do {
        for (const auto& p : InputList) {
            s += p + ' ';
        }
        l.push_back(s);
        s.clear();
    } while (next_permutation(InputList.begin(), InputList.end()));
    return l;
}

/*
print_permutations
Uses auto to print all of the permutations.
*/

void print_permutations(list<string> &Permutations)
{
    for (const auto& p : Permutations) {
        cout << p << endl;
    }
}