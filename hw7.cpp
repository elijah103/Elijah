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
Date: 11/5/20
Name: Elijah Miles
*/

/***********************************************
Author: <Elijah Miles>
Date: <11/5/20>
Purpose: <To use maps in order to store the name and rating
of a movie, then output the movies and their average ratings.>
Sources of Help: <Tutoring, stack overflow>
Time Spent: <4 hours>
***********************************************/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

/*
main function declares 1 map for # of reviews and 1 map for sum of reviews.
For each name from the file the function searches the map for the name and either
adds the new movie or increments the # of reviews and sum of reviews.
*/
int main(int argc, char* argv[])
{
	ifstream File;
	File.open("c:/comp3/movies.txt");
	int num;
	File >> num;
	char c;
	File.get(c);
	map<string, int>map1;
	map<string, int>map2;
	string name;
	int rate;
	for (int i = 0; i < num; i++) {
		getline(File, name);
		File >> rate;
		File.get(c);
		map<string, int>::iterator p= map1.find(name);
		if (p != map1.end()) {
			map1[name] ++;
			map2[name] += rate;
		}
		else {
			map1.insert(pair<string, int>(name, 1));
			map2.insert(pair<string, int>(name, rate));
		}
	}
	map<string, int>::iterator b = map2.begin();
	for (map<string, int>::iterator a = map1.begin(); a != map1.end(); a++,b++) {
		if ((*a).second > 1) {
			cout << setprecision(2) << (*a).first << ": " << (*a).second << " reviews, average of " <<
				static_cast<double>((*b).second) / (*a).second << " / 5" << endl;
		}
		else {
			cout << setprecision(2) << (*a).first << ": " << (*a).second << " review, average of " <<
				static_cast<double>((*b).second) / (*a).second << " / 5" << endl;
		}
	}
	return 0;
}