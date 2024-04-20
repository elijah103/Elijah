/***********************************************
Author: <Elijah Miles>
Date: <9/22/2020>
Purpose: <The program opens a file for reading called "output.txt"
and outputs each word from the file to the screen with the exception
of changing all instances of the word "dislike" to "love".>
Sources of Help: <https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
uml tutoring>
Time Spent: <3 hours>
***********************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream file;
	string word;
	file.open("c:/comp3/output.txt");
	if (file.fail()) {
		cout << "Failed to open file" << endl;
		exit(1);
	}
	while (file >> word) {
		if (word != "dislike") {
			cout << word;
		}
		else {
			cout << "love";
		}
		cout << ' ';
	}
	file.close();
	return 0;
}

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
Date: 9/22/20
Name: Elijah Miles
*/