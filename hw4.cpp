/***********************************************
Author: <Elijah Miles>
Date: <9/28/20>
Purpose: <To take a five digit integer or
27 digit string in 7421 code and convert it
to the corresponding result.>
Sources of Help: <UML tutoring>
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
Date: 9/28/20
Name: Elijah Miles
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

/*
class ZipCode
Has the default constructor, the constructor that inits the string,
the constructor that inits the integer number, and the two functions to return
the integer and the string.
In the private section, it has the integer and the string.
*/
class ZipCode
{
public:
    ZipCode();
    ZipCode(string initZip);
    ZipCode(int initZip);
    int getZipCode(void);
    string getBarCode(void);
private:
    string stringCode;
};

/*
main function is given in the homework assignment
*/
int main(int argc, char* argv[]) {
    ZipCode zip(99504),
        zip2("100101010011100001100110001"),
        zip3(12345),
        zip4(67890);
    cout << zip.getZipCode() << "'s bar code is '"
        << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
        << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
        << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
        << zip4.getBarCode() << "'" << endl;

    cout << endl;

    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
            << z1_barcode << "'";

        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
    { "100101010011100001100110000", "bad start/end character" },
    { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] <<
            endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}

/*
ZipCode()
default constructor, sets the string and integer,
takes nothing, returns nothing
*/
ZipCode::ZipCode()
{
    stringCode = "100000000000000000000000001";
}

/*
ZipCode(string initZip)
constructor that takes the string, returns nothing.
*/
ZipCode::ZipCode(string initZip)
{
    //test for bad start/end character and bad digit
    int i;
    if (initZip.length() != 27) {
        cout << "Wrong string length. The string must have 27 characters." << endl;
    }
    if (initZip[0] != '1' || initZip[26] != '1') {
        cout << "Wrong start/end character in the barcode!" << endl;
    }
    for (i = 0; i < 27; i++) {
        if (initZip[i] != '0' && initZip[i] != '1') {
            cout << "Wrong barcode! A barcode can only contain '0' and '1'." << endl;
        }
    }
    stringCode = initZip;
}

/*
ZipCode(int initZip)
Constructor that takes the integer and gets the corresponding string.
Returns nothing.
*/
ZipCode::ZipCode(int initZip)
{
    int i, j;
    int arr[5] = { 0 };
    int coded74210[5] = { 0 };
    /*
    "i" is the index for arr[]
    -Get each integer into arr[]
    */
    for (i = 4; i >= 0; i--) {
        arr[i] = initZip % 10;
        initZip /= 10;
    }
    //start with a 1
    stringCode = '1';
    /*
    "j" is the index for arr[]
    -Make the 7421 code for all five numbers
    */
    for (j = 0; j < 5; j++) {
        if (arr[j] == 0) {
            coded74210[0] = 1;
            coded74210[1] = 1;
            coded74210[2] = 0;
            coded74210[3] = 0;
            coded74210[4] = 0;
        }
        if (arr[j] == 1) {
            coded74210[0] = 0;
            coded74210[1] = 0;
            coded74210[2] = 0;
            coded74210[3] = 1;
            coded74210[4] = 1;
        }
        if (arr[j] == 2) {
            coded74210[0] = 0;
            coded74210[1] = 0;
            coded74210[2] = 1;
            coded74210[3] = 0;
            coded74210[4] = 1;
        }
        if (arr[j] == 3) {
            coded74210[0] = 0;
            coded74210[1] = 0;
            coded74210[2] = 1;
            coded74210[3] = 1;
            coded74210[4] = 0;
        }
        if (arr[j] == 4) {
            coded74210[0] = 0;
            coded74210[1] = 1;
            coded74210[2] = 0;
            coded74210[3] = 0;
            coded74210[4] = 1;
        }
        if (arr[j] == 5) {
            coded74210[0] = 0;
            coded74210[1] = 1;
            coded74210[2] = 0;
            coded74210[3] = 1;
            coded74210[4] = 0;
        }
        if (arr[j] == 6) {
            coded74210[0] = 0;
            coded74210[1] = 1;
            coded74210[2] = 1;
            coded74210[3] = 0;
            coded74210[4] = 0;
        }
        if (arr[j] == 7) {
            coded74210[0] = 1;
            coded74210[1] = 0;
            coded74210[2] = 0;
            coded74210[3] = 0;
            coded74210[4] = 1;
        }
        if (arr[j] == 8) {
            coded74210[0] = 1;
            coded74210[1] = 0;
            coded74210[2] = 0;
            coded74210[3] = 1;
            coded74210[4] = 0;
        }
        if (arr[j] == 9) {
            coded74210[0] = 1;
            coded74210[1] = 0;
            coded74210[2] = 1;
            coded74210[3] = 0;
            coded74210[4] = 0;
        }
        //for each 7421 coded number, add the numbers to the string
        for (i = 0; i < 5; i++) {
            if (coded74210[i] == 0) {
                stringCode += '0';
            }
            else {
                stringCode += '1';
            }
        }
    }
    //end with a 1
    stringCode += '1';
    //test for bad start/end character and bad digit
    if (stringCode.length() != 27) {
        cout << "Wrong string length. The string must have 27 characters." << endl;
    }
    if (stringCode[0] != '1' || stringCode[26] != '1') {
        cout << "Wrong start/end character in the barcode!" << endl;
    }
    for (i = 0; i < 27; i++) {
        if (stringCode[i] != '0' && stringCode[i] != '1') {
            cout << "Wrong barcode! A barcode can only contain '0' and '1'." << endl;
        }
    }
}

/*
int getZipCode(void)
function gets and returns the integer code, takes nothing
*/
int ZipCode::getZipCode(void)
{
    int arr[5] = { 0 };
    int i, temp, n, j;
    int num;
    /*
   "i" is the index for stringCode from 1 to 25.
   "temp" is the temporary value of the digit
   currently being made from the 7421 code.
   "n" is the place of the digit from the string
   -For each 7421 coded number in the string, convert
   it to decimal and put it in arr[].
   */
    for (i = 1, temp = 0, j = 0, n = 0; i < 26; i++, n++) {
        if (n == 0) {
            temp += ((stringCode[i] - 48) * 7);
        }
        if (n == 1) {
            temp += ((stringCode[i] - 48) * 4);
        }
        if (n == 2) {
            temp += ((stringCode[i] - 48) * 2);
        }
        if (n == 3) {
            temp += ((stringCode[i] - 48) * 1);
        }
        if (n == 4) {
            temp += ((stringCode[i] - 48) * 0);
            n = -1;
            arr[j] = temp;
            temp = 0;
            j++;
        }
    }
    /*
    "num" is the integer number from the string code
    "i" is the index for arr[]
    "n" is the number of that you raise 10 to the power of
    when calculating num.
    -Put the five numbers from arr[] into one number in order.
    That number is the integer code.
    */
    for (num = 0, i = 0, n = 4; i < 5; i++, n--) {
        if (arr[i] != 11) {
            num += (arr[i] * pow(10, n));
        }
    }
    return num;
}


/*
string getBarCode(void)
function returns the string, takes nothing.
*/
string ZipCode::getBarCode(void)
{
    return stringCode;
}