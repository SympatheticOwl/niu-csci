/***************************************************************
CSCI 240         Program 8     Spring 2017

Programmer:

Section:

Date Due:

Purpose: 
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

/**********   Put the Card class definition between these lines   **********/
class Card
	{
	public:
	  Card();
	  
	  void setCard( int, char );
	  
	  int getFace();
	  char getSuit();
	  
	  void displayCard();
	
	private:
	  int faceValue;
	  char suit;
	};
/***************************************************************************/

const int FACES = 13;
const int SUITS = 4;


int main()
{
//Set the seed value for the random number generator
srand(240);

//Test 1: Constructor and displayCard method

//Create 5 Card objects

Card firstCard;
Card secondCard;
Card thirdCard;
Card fourthCard;
Card fifthCard;

//Display the 5 objects

cout << "Test 1: Constructor and displayCard method" << endl << endl
     << "  The first card should be the 4 of Diamonds. It is the ";
firstCard.displayCard();

cout << "." << endl << endl << "  The second card should be the 3 of Clubs. It is the ";
secondCard.displayCard();

cout << "." << endl << endl << "  The third card should be the King of Clubs. It is the ";
thirdCard.displayCard();

cout << "." << endl << endl << "  The fourth card should be the King of Spades. It is the ";
fourthCard.displayCard();

cout << "." << endl << endl << "  The fifth card should be the Jack of Clubs. It is the ";
fifthCard.displayCard();


//Test 2: setCard method on four of the objects


cout << "." << endl << endl << "Test 2: setCard method" << endl << endl;

//Change the first card to the 9 of Clubs

firstCard.setCard( 9, 'C' );

cout << "  The first card should be the 9 of Clubs. It is now the ";
firstCard.displayCard();

//Change the second card with invalid value for the face

secondCard.setCard( 15, 'D' );

cout << "." << endl << endl << "  The second card should be the Ace of Diamonds. It is now the ";
secondCard.displayCard();

//Change the third card with invalid value for the suit

thirdCard.setCard( 7, 'G' );

cout << "." << endl << endl << "  The third card should be the 7 of Hearts. It is now the ";
thirdCard.displayCard();

//Change the fourth card with invalid value for both the face and the suit

fourthCard.setCard( -5, 'R' );

cout << "." << endl << endl << "  The fourth card should be the Ace of Hearts. It is now the ";
fourthCard.displayCard();


//Test 3: getFace and getSuit methods on the fourth and fifth objects

cout << "." << endl << endl << "Test 3: getFace and getSuit methods" << endl << endl;

cout << "  The fourth card should have a face value of 1. It is "
     << fourthCard.getFace() << "." << endl
     << "  The suit value should be H. It is " << fourthCard.getSuit() << ".";

cout << endl << endl << "  The fifth card should have a face value of 11. It is "
     << fifthCard.getFace() << "." << endl
     << "  The suit value should be C. It is " << fifthCard.getSuit() << endl;

return 0;
}
	
Card::Card()
	{
	faceValue = rand()%FACES + 1;
	int suitsVal = rand()%SUITS + 1;
	if(suitsVal == 1)
		suit = 'C';
	else if(suitsVal == 2)
		suit = 'D';
	else if(suitsVal == 3)
		suit = 'H';
	else
		suit = 'S'	;
	}
	
void Card::setCard(int newFace, char newSuit)
	{
	if(newFace > 13 || newFace < 1)
		faceValue = 1;
	else
		faceValue = newFace;
	
	if(newSuit != 'C' && newSuit != 'D' && newSuit != 'H' && newSuit != 'S')
		suit = 'H';
	else
		suit = newSuit;
	}
	
int Card::getFace()
	{
	return faceValue;
	}
	
char Card::getSuit()
	{
	return suit;
	}
	
void Card::displayCard()
	{
	int temp;
	string faces[] = {"null", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	
	if(getSuit() == 'C')
		temp = 0;
	else if(getSuit() == 'D')
		temp = 1;
	else if(getSuit() == 'H')
		temp = 2;
	else
		temp = 3;
	
	cout << faces[getFace()] << " of " << suits[temp];
	}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
