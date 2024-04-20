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
Date: 10/6/20
Name: Elijah Miles
*/

/***********************************************
Author: <Elijah Miles>
Date: <10/14>
Purpose: <To create a rational class that can perform
basic operations.>
Sources of Help: <None.>
Time Spent: <6 hours>
***********************************************/

#include <iostream>

using namespace std;

/*class rational
includes constructors, setters, getters, normalization function,
has numerator and denominator.*/
class rational{
public:
	rational();
	rational(int WholeNumber);
	rational(int Numerator, int Denominator);
	int get_numerator(void) const;
	int get_denominator(void) const;
	void set_num(int new_num);
	void set_den(int new_den);
	void display(void) const;
	void normalize(void);
private:
	int numerator;
	int denominator;
};

void clear_keyboard_buffer(void);
bool operator==(const rational& leftOp, const rational& rightOp);
bool operator<(const rational& leftOp, const rational& rightOp);
bool operator<=(const rational& leftOp, const rational& rightOp);
bool operator>(const rational& leftOp, const rational& rightOp);
bool operator>=(const rational& leftOp, const rational& rightOp);
const rational operator+(const rational& leftOp, const rational& rightOp);
const rational operator-(const rational& leftOp, const rational& rightOp);
const rational operator*(const rational& leftOp, const rational& rightOp);
const rational operator/(const rational& leftOp, const rational& rightOp);
int lcm(int a, int b);
ostream& operator<<(ostream& out, const rational r);
istream& operator>>(istream& in, rational &r);
int gcd(int a, int b);

int main(int argc, char* argv[])
{
	rational r1, r2(5), r3(2, 3), r4, r5;
	cout << "Default constructor r1 = ";
	r1.display();
	cout << "Whole number r2 = ";
	r2.display();
	cout << "(2,3) r3 = ";
	r3.display();
	cout << "Numerator of r3 = " << r3.get_numerator() << endl;
	cout << "Denominator of r3 = " << r3.get_denominator() << endl;
	cout << "Setting r3 numerator to 5 ..." << endl;
	r3.set_num(5);
	cout << "Numerator of r3 = " << r3.get_numerator() << endl;
	cout << "Setting r3 denominator to 9 ..." << endl;
	r3.set_den(9);
	cout << "Denominator of r3 = " << r3.get_denominator() << endl;
	cout << "r3 = ";
	r3.display();
	cout << "Setting r3 to (100/-20) ..." << endl;
	r3.set_num(100);
	r3.set_den(-20);
	cout << "r3 = ";
	r3.display();
	if (r3 == r2) {
		cout << "r3 = r2" << endl;
	}
	else {
		cout << "r3 is not equal to r2" << endl;
	}
	if (r3 < r2) {
		cout << "r3 is less than r2" << endl;
	}
	else {
		cout << "r3 is greater than or equal to r2" << endl;
	}
	cout << "r2 + r3 = ";
	r4 = r2 + r3;
	r4.display();
	cout << "r4 / r3 = ";
	r5 = r4 / r3;
	r5.display();
	cin >> r5;
	cout << "r5 is " << r5 << endl;
	r1 = r5 + r3;
	cout << "r5 + r3 = " << r1<<endl;
	r1 = r5 * r3;
	cout << "r5 * r3 = " << r1 << endl;
	r1 = r5 / r3;
	cout << "r5 / r3 = " << r1<<endl;
	r1 = r5 - r3;
	cout << "r5 - r3 = " << r1<<endl;
	rational r6(2, 0);
	cout << "r6 is " << r6 << endl;
	return 0;
}

/*rational::rational()
default constructor*/
rational::rational()
{
	numerator = 0;
	denominator = 1;
}

/*rational::rational(int WholeNumber)
whole number constructor*/
rational::rational(int WholeNumber)
{
	numerator = WholeNumber;
	denominator = 1;
}

/*rational::rational(int Numerator, int Denominator)
numerator and denominator constructor*/
rational::rational(int Numerator, int Denominator)
{
	numerator = Numerator;
	if (Denominator != 0) {
		denominator = Denominator;
	}
	else {
		cout << "Can not have a denominator of 0." << endl;
		exit(1);
	}
	(*this).normalize();
}

void clear_keyboard_buffer(void)
{
	cin.clear();
	cin.ignore(10000, '\n');
}

/*bool operator==(const rational& leftOp, const rational& rightOp)
overloaded == operator, takes two const rationals,
returns 1 for equal or 0 for not equal*/
bool operator==(const rational& leftOp, const rational& rightOp)
{
	return (leftOp.get_numerator() == rightOp.get_numerator())&&
		(leftOp.get_denominator()==rightOp.get_denominator());
}

/*getter function*/
int rational::get_numerator(void) const
{
	return numerator;
}

/*getter function*/
int rational::get_denominator(void) const
{
	return denominator;
}

/*bool operator<(const rational& leftOp, const rational& rightOp)
overloaded < operator, takes two const rationals,
returns 1 for less than, 0 for greater than or equal to*/
bool operator<(const rational& leftOp, const rational& rightOp)
{
	double leftValue, rightValue;
	int temp1, temp2;
	temp1 = leftOp.get_numerator();
	temp2 = rightOp.get_numerator();
	leftValue = (static_cast<double>(temp1)) / leftOp.get_denominator();
	rightValue= (static_cast<double>(temp2)) / rightOp.get_denominator();
	return leftValue < rightValue;
}

/*bool operator<=(const rational& leftOp, const rational& rightOp)
overloaded <= operator, takes two const rationals, returns
1 for <=, 0 for >.*/
bool operator<=(const rational& leftOp, const rational& rightOp)
{
	double leftValue, rightValue;
	int temp1, temp2;
	temp1 = leftOp.get_numerator();
	temp2 = rightOp.get_numerator();
	leftValue = (static_cast<double>(temp1)) / leftOp.get_denominator();
	rightValue = (static_cast<double>(temp2)) / rightOp.get_denominator();
	return leftValue <= rightValue;
}

/*bool operator>(const rational& leftOp, const rational& rightOp)
overloaded greater than operator, takes two const rationals,
returns 1 for greater than, 0 for less than or equal to.*/
bool operator>(const rational& leftOp, const rational& rightOp)
{
	double leftValue, rightValue;
	int temp1, temp2;
	temp1 = leftOp.get_numerator();
	temp2 = rightOp.get_numerator();
	leftValue = (static_cast<double>(temp1)) / leftOp.get_denominator();
	rightValue = (static_cast<double>(temp2)) / rightOp.get_denominator();
	return leftValue > rightValue;
}

/*bool operator>=(const rational& leftOp, const rational& rightOp)
>= overloaded operator, takes two const rationals, returns 1 for
greater than or equal to, 0 for less than.*/
bool operator>=(const rational& leftOp, const rational& rightOp)
{
	double leftValue, rightValue;
	int temp1, temp2;
	temp1 = leftOp.get_numerator();
	temp2 = rightOp.get_numerator();
	leftValue = (static_cast<double>(temp1)) / leftOp.get_denominator();
	rightValue = (static_cast<double>(temp2)) / rightOp.get_denominator();
	return leftValue >= rightValue;
}

/*const rational operator+(const rational& leftOp, const rational& rightOp)
+ operator, takes two const rationals, returns a const rational that is the
sum of the two arguments.*/
const rational operator+(const rational& leftOp, const rational& rightOp)
{
	int left_numerator,right_numerator, multiple;
	multiple = lcm(leftOp.get_denominator(), rightOp.get_denominator());
	left_numerator = leftOp.get_numerator() * (multiple / leftOp.get_denominator());
	right_numerator = rightOp.get_numerator() * (multiple / rightOp.get_denominator());
	rational sum(left_numerator + right_numerator, multiple);
	sum.normalize();
	return sum;
}

/*const rational operator-(const rational& leftOp, const rational& rightOp)
overloaded - operator, takes two const rationals, returns a const rational
that is the difference of the two arguments.*/
const rational operator-(const rational& leftOp, const rational& rightOp)
{
	int left_numerator, right_numerator, multiple;
	multiple = lcm(leftOp.get_denominator(), rightOp.get_denominator());
	left_numerator = leftOp.get_numerator() * (multiple / leftOp.get_denominator());
	right_numerator = rightOp.get_numerator() * (multiple / rightOp.get_denominator());
	rational difference(left_numerator - right_numerator, multiple);
	difference.normalize();
	return difference;
}

/*const rational operator*(const rational& leftOp, const rational& rightOp)
overloaded * operator, takes two const rationals, returns a const rational that
is the product of the two arguments.*/
const rational operator*(const rational& leftOp, const rational& rightOp)
{
	rational product(leftOp.get_numerator() * rightOp.get_numerator(),
		leftOp.get_denominator() * rightOp.get_denominator());
	product.normalize();
	return product;
}

/*const rational operator/(const rational& leftOp, const rational& rightOp)
overloaded / operator, takes two const rationals, returns a const rational
that is the quotient of the two arguments.*/
const rational operator/(const rational& leftOp, const rational& rightOp)
{
	int reciprocal_num, reciprocal_den, multiple, left_numerator, right_numerator;
	rational quotient(leftOp.get_numerator() * rightOp.get_denominator(),
		leftOp.get_denominator() * rightOp.get_numerator());
	quotient.normalize();
	return quotient;
}

/*int lcm(int a, int b)
takes two integers, returns the least common multiple.*/
int lcm(int a, int b)
{
	int lcm;
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while (1) {
		if (lcm % a == 0 && lcm % b == 0) {
			break;
		}
		lcm++;
	}
	return lcm;
}

/*ostream& operator<<(ostream& out, const rational r)
overloaded << operator, takes an ostream address and
a const rational, returns the ostream address. The function
overloads standard output for displaying a rational number.*/
ostream& operator<<(ostream& out, const rational r)
{
	out << r.get_numerator() << '/' << r.get_denominator();
	return out;
}

/*istream& operator>>(istream& in, rational &r)
overloaded input operator, takes an istream address and
a rational address. Returns the instream address.
Takes input in the form of a rational number.*/
istream& operator>>(istream& in, rational &r)
{
	int num, den;
	char slash, negative;
	in >> num >> slash >> den;
	if (in && slash == '/'&&den!=0) {
		clear_keyboard_buffer();
		rational input(num, den);
		input.normalize();
		r.set_num(input.get_numerator());
		r.set_den(input.get_denominator());
	}
	else if(den!=0){
		clear_keyboard_buffer();
		cout << "Wrong format. Enter in the format x/y" << endl;
	}
	else {
		cout << "Can not have a denominator of 0." << endl;
		exit(1);
	}
	return in;
}

/*setter*/
void rational::set_num(int new_num)
{
	numerator = new_num;
	this->normalize();
}

/*setter*/
void rational::set_den(int new_den)
{
	if (new_den != 0) {
		denominator = new_den;
	}
	else {
		cout << "Can not have a denominator of 0." << endl;
		exit(1);
	}
	this->normalize();
}

/*int gcd(int a, int b)
Takes two integers, returns the greadest common divisor.*/
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

/*void rational::display(void) const
Takes nothing, returns nothing, displays the rational class.*/
void rational::display(void) const
{
	cout << numerator << '/' << denominator << endl;
}

/*void rational::normalize(void)
Takes nothing, returns nothing, function properly sets the negative signs
and reduces the fraction by the greatest common divisor.*/
void rational::normalize(void)
{
	int g_c_d;
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
	g_c_d = gcd(numerator, denominator);
	numerator /= g_c_d;
	denominator /= g_c_d;
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
}