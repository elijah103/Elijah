/***********************************************
Author: <Elijah Miles>
Date: <9/30/20>
Purpose: <To create a point class and test certain member
functions with a driver.>
Sources of Help: <None.>
Time Spent: <4 hours>
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
Date: 9/30/20
Name: Elijah Miles
*/

#include <iostream>

using namespace std;

/*
class point
This class point has two integer coordinate values
in the private section and two member functions to move
and rotate the point, as well as two getter functions that
return each coordinate.
*/
class point
{
public:
	point();
	void move_point(int horizontal, int vertical);
	void rotate_90(void);
	int get_x(void) const;
	int get_y(void) const;
private:
	int x_coordinate;
	int y_coordinate;
};

void clear_keyboard_buffer(void);
int do_you_wish_to_continue(void);

/*
main
main function first calls the default constructor, then
retrieves the two coordinates from the user, then puts the
point at the location specified by the user. Then it tests each
of the functions from class point.
*/
int main(int argc, char* argv[])
{
	do {
		int x = 0, y = 0;
		point Point;
		while (cout << "Enter an integer x coordinate: " && !(cin >> x)) {
			clear_keyboard_buffer();
			cout << "That's not an integer x coordinate." << endl;
		}
		while (cout << "Enter an integer y coordinate: " && !(cin >> y)) {
			clear_keyboard_buffer();
			cout << "That's not an integer y coordinate." << endl;
		}
		Point.move_point(x, y);
		for (int i = 0; i < 4; i++) {
			cout << "Rotating..." << endl;
			Point.rotate_90();
			cout << "We now have (" << Point.get_x() << "," << Point.get_y() << ")" << endl;
		}
		cout << "Moving by (1,1)..." << endl;
		Point.move_point(1, 1);
		cout << "We now have (" << Point.get_x() << "," << Point.get_y() << ")" << endl;
		cout << "Moving by (-1,-1)..." << endl;
		Point.move_point(-1, -1);
		cout << "We now have (" << Point.get_x() << "," << Point.get_y() << ")" << endl;
		cout << "Moving by (-5,4)..." << endl;
		Point.move_point(-5, 4);
		cout << "We now have (" << Point.get_x() << "," << Point.get_y() << ")" << endl;
	} while (do_you_wish_to_continue());
	return 0;
}

/*
point::point()
This function is the default constructor. It sets the two coordinates to zero.
It takes nothing and returns nothing.
*/
point::point()
{
	x_coordinate = 0;
	y_coordinate = 0;
}

/*
void point::move_point(int horizontal, int vertical)
Function moves the point indicated by the parameters
horizontal for the x value and vertical for the y value.
It returns nothing.
*/
void point::move_point(int horizontal, int vertical)
{
	x_coordinate += horizontal;
	y_coordinate += vertical;
}

/*
void point::rotate_90(void)
Function rotates the point 90 degrees. It takes nothing and
returns nothing.
*/
void point::rotate_90(void)
{
	int temp;
	if (x_coordinate >= 0 && y_coordinate >= 0) {
		temp = y_coordinate;
		y_coordinate = -x_coordinate;
		x_coordinate = temp;
	}
	else if (x_coordinate < 0 && y_coordinate >= 0) {
		temp = x_coordinate;
		x_coordinate = y_coordinate;
		y_coordinate = -temp;
	}
	else if (x_coordinate < 0 && y_coordinate < 0) {
		temp = y_coordinate;
		y_coordinate = -x_coordinate;
		x_coordinate = temp;
	}
	else if (x_coordinate >= 0 && y_coordinate < 0) {
		temp = x_coordinate;
		x_coordinate = y_coordinate;
		y_coordinate = -temp;
	}
}

/*
int point::get_x(void) const
Function is a getter function for the x coordinate.
It takes nothing and returns nothing.
*/
int point::get_x(void) const
{
	return x_coordinate;
}

/*
int point::get_y(void) const
Function is a getter function for the y coordinate.
It takes nothing and returns nothing.
*/
int point::get_y(void) const
{
	return y_coordinate;
}

/*
int do_you_wish_to_continue(void)
Function asks thte user if they wish to continue.
It takes nothing and returns 1 for yes or 0 for no.
*/
int do_you_wish_to_continue(void)
{
	char c = 'n';
	while (cout << "Continue? (y/n): " && !(cin >> c) && c != 'y' && c != 'n') {
		clear_keyboard_buffer();
		cout << "That's not y or n." << endl;
	}
	if (c == 'y')
		return 1;
	else {
		cout << "goodbye" << endl;
		return 0;
	}
}

/*
void clear_keyboard_buffer(void)
Function clears the keyboard buffer.
It takes nothing and returns nothing.
*/
void clear_keyboard_buffer(void)
{
	cin.clear();
	cin.ignore(10000, '\n');
}