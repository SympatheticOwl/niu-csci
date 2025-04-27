/******************************************************************************
CSCI 240    Assignment 9    Spring 2016
Programmer:	Lucas Damler (worked with Marty Minogue)
Section:	1
TA:			?
Date Due:	29 APR 2016 @ 11:59
Purpose: create a game using a class called Die
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

class Die{
	//Method prototypes
	public:	
		Die();
		void roll();		
		int getValue();
		void draw();
		
	private:
		int numSide;
		static const int NUM_SIDES;
};

const int Die::NUM_SIDES = 6;		//sets number of sides to the dice

int main(){
	srand(time(0));
	
	int dieSum, dealerPnt = 0, playerPnt = 0;
	int guess, choice;
	
	cout << "How many times would like to play? ";
	cin >> choice;
	cout << "Enter 0 for even, 1 for odd, and anything else to quit: ";
	cin >> guess;
	cout << endl;
	
	for(int i = 0; i < choice; i++){
		Die dealerDie1;
		dealerDie1.roll();
		Die dealerDie2;
		dealerDie2.roll();
		
		dieSum = dealerDie1.getValue() + dealerDie2.getValue();
		
		if(guess == 1 && dieSum%2 != 0){ 						//The following if statements decide if the player or dealer get a point
			cout << "You won a point: ";
			playerPnt++;
			cout << playerPnt;
		}
		else if(guess == 0 && dieSum%2 == 0){
			cout << "You won a point: ";
			playerPnt++;
			cout << playerPnt;
		}
		else{
			cout << "Dealer won a point: ";
			dealerPnt++;
			cout << dealerPnt;
		}
		cout << endl;
		dealerDie1.draw();
		cout << endl;
		dealerDie2.draw();
		cout << endl << "Value is: " << dieSum << endl << endl;
		
	}
	cout << "Dealer score: " << dealerPnt << endl;
	cout << "Player score: " << playerPnt << endl;
	
	if(dealerPnt > playerPnt){
		cout << "The dealer has won";
	}
	else if(dealerPnt == playerPnt){
		cout << "It's a tie";
	}
	else{
		cout << "Player has won";
	}
	
	
	return 0;
}

//constructor method. takes no arguments
//calls roll method to set initial up value
//returns nothing
Die::Die(){
	roll();
}

//takes no arguments
//sets numSide to a random number between 1 and 6
//returns nothing
void Die::roll(){
	numSide = rand()%NUM_SIDES + 1;
}

//takes no arguments
//returns the value of numSide
int Die::getValue(){
	return numSide;
}

//takes no arguments
//displays one line of the dice at a time using descion statemnts
//returns nothing
void Die::draw(){
	cout << " ----- " << endl;
	if(numSide == 1){cout << "|     |";}
	else if (numSide == 2 || numSide == 3){cout << "|o    |";}
	else{cout << "|o   o|";}
	cout << endl;
	
	if(numSide == 1 || numSide == 3 || numSide == 5){cout << "|  o  |";}
	else if(numSide == 2 || numSide == 4){cout << "|     |";}
	else{cout << "|o   o|";}
	cout << endl;
	
	if(numSide == 1){cout << "|     |";}
	else if (numSide == 2 || numSide == 3){cout << "|    o|";}
	else{cout << "|o   o|";}
	cout << endl;
	cout << " ----- ";
	
}

