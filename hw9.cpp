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
Date: 11/12/20
Name: Elijah Miles
*/

/***********************************************
Author: <Elijah Miles>
Date: <11/12/20>
Purpose: <To play the guessing game with class objects, using
derived human and computer player classes.>
Sources of Help: <None.>
Time Spent: <4 hours>
***********************************************/

#include <iostream>
#include <ctime>

using namespace std;

/*
class Player
virtual getGuess used for HumanPlayer and ComputerPlayer
virtual setters and getters for lower and upper bounds of
ComputerPlayer
*/

class Player
{
public:
    virtual int getGuess(void) const;
    virtual int getLower(void) const;
    virtual int getUpper(void) const;
    virtual void setLower(int Lower);
    virtual void setUpper(int Upper);
private:
};

/*
class HumanPlayer : public Player
Has the same functions as Player
*/

class HumanPlayer : public Player
{
public:
    int getGuess(void)const;
    int getLower(void) const;
    int getUpper(void) const;
    void setLower(int Lower);
    void setUpper(int Upper);
private:
};

/*
class ComputerPlayer: public Player
Constructor sets lowerBound to 0 and upperBound to 99
Has the same functions as Player
Private members for lower and upper bound
*/

class ComputerPlayer : public Player
{
public:
    ComputerPlayer();
    int getGuess(void)const;
    int getLower(void) const;
    int getUpper(void) const;
    void setLower(int Lower);
    void setUpper(int Upper);
private:
    int lowerBound;
    int upperBound;
};

bool checkForWin(int guess, int answer);
void play(Player& player1, Player& player2);
void clear_keyboard_buffer(void);
void reset(Player& player1, Player& player2);
void tooHigh(Player& player1, Player& player2,int Guess);
void tooLow(Player& player1, Player& player2,int Guess);

/*
main
tests three cases
*/

int main(int argc, char* argv[])
{
    HumanPlayer A, B;
    ComputerPlayer C;
    play(A, B);
    play(A, C);
    play(C, C);
	return 0;
}

/*
Player virtual functions
*/

int Player::getGuess(void) const
{
    return 0;
}

int Player::getLower(void) const
{
    return 0;
}

int Player::getUpper(void) const
{
    return 0;
}

void Player::setLower(int Lower)
{
    return;
}

void Player::setUpper(int Upper)
{
    return;
}

/*
int HumanPlayer::getGuess(void) const
Gets a number from the user
*/

int HumanPlayer::getGuess(void) const
{
    int number;
    while (!(cin >> number)) {
        clear_keyboard_buffer();
        cout << "That's not a number." << endl;
    }
    return number;
}

/*
HumanPlayer lower bound is 99
*/

int HumanPlayer::getLower(void) const
{
    return 99;
}

/*
Upper bound is 0
*/

int HumanPlayer::getUpper(void) const
{
    return 0;
}

/*
HumanPlayer class setLower and setUpper functions do nothing
*/

void HumanPlayer::setLower(int Lower)
{
    return;
}

void HumanPlayer::setUpper(int Upper)
{
    return;
}

/*
Computer Player lower and upper bounds
*/

ComputerPlayer::ComputerPlayer()
{
    lowerBound = 0;
    upperBound = 99;
}

/*
int ComputerPlayer::getGuess(void) const
Gets a random number, if it is not in the range, keep getting
a random number until it's in the range.
*/

int ComputerPlayer::getGuess(void) const
{
    int number;
    number= (rand() % 100);
    while (number<=lowerBound || number>=upperBound) {
        number = (rand() % 100);
    }
    cout << "The computer guesses " << number << endl;
    return number;
}

/*
Computer Player getter functions
*/

int ComputerPlayer::getLower(void) const
{
    return lowerBound;
}

int ComputerPlayer::getUpper(void) const
{
    return upperBound;
}

/*
Computer Player setter functions
*/

void ComputerPlayer::setLower(int Lower)
{
    lowerBound = Lower;
}

void ComputerPlayer::setUpper(int Upper)
{
    upperBound = Upper;
}

/*
clears keyboard buffer
*/

void clear_keyboard_buffer(void)
{
    cin.clear();
    cin.ignore(10000, '\n');
}

/*
void play(Player& player1, Player& player2)
Takes two Player class references
Gets a random answer and keeps calling the functions getGuess
and checkForWin until checkforWin returns true.
Each time checkForWin is called, it updates the lower and upper bounds for
both players accordingly.
*/

void play(Player& player1, Player& player2) {
    int answer = 0, guess = 0;
    srand(static_cast<unsigned>(time(NULL)));
    answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        cout << "Player 1's turn to guess: ";
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win) {
            reset(player1, player2);
            return;
        }
        else if (answer < guess) {
            tooHigh(player1, player2,guess);
        }
        else {
            tooLow(player2, player2, guess);
        }
        cout << "Player 2's turn to guess: ";
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
        if (win) {
            reset(player1, player2);
            return;
        }
        else if (answer < guess) {
            tooHigh(player1, player2, guess);
        }
        else {
            tooLow(player2, player2, guess);
        }
    }
}

/*
bool checkForWin(int guess,int answer,Player& Player1,Player& Player2)
Tells the user if their guess is correct, too high or too low.
*/

bool checkForWin(int guess, int answer)
{
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess is too high." << endl;
    }
    else {
        cout << "Your guess is too low." << endl;
    }
    return false;
}

/*
void reset(Player& player1, Player& player2)
resets lower and upper bounds after the answer is guessed
*/

void reset(Player& player1, Player& player2)
{
    player1.setLower(0);
    player1.setUpper(99);
    player2.setLower(0);
    player2.setUpper(99);
}

/*
void tooHigh(Player& player1, Player& player2,int Guess)
Resets in the case that guess is too high
*/

void tooHigh(Player& player1, Player& player2,int Guess)
{
    if (Guess < player1.getUpper()) {
        player1.setUpper(Guess);
    }
    if (Guess < player2.getUpper()) {
        player2.setUpper(Guess);
    }
}

/*
void tooLow(Player& player1, Player& player2,int Guess)
resets in the case that guess is too low
*/

void tooLow(Player& player1, Player& player2,int Guess)
{
    if (Guess > player1.getLower()) {
        player1.setLower(Guess);
    }
    if (Guess > player2.getLower()) {
        player2.setLower(Guess);
    }
}