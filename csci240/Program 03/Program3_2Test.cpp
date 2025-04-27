/***************************************************************
CSCI 240         Program 3     Spring 2016
Programmer: Lucas Damler
Section: 1
Date Due: 12 FEB 2016 @ 23:59
Purpose: This program flips coins
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int heads = 0, tails = 0;
	int toss, flip;
	string choice = "Yes";
	double headsP, tailsP;
	do{
	cout << "How many times would you like to flip the coin? ";
	cin >> toss;
	cout << endl;
	srand(time(0));
	if(toss < 0){		//This handles the exception of entering a toss < 0
		cout << "Please enter a positive whole number\n" << endl;
		choice = "Yes";
	}
	else{
		for(int i = 0; i < toss; i++){		//This loop generates random numbers between 0 and 1 and counts each one into seperate counters
			flip = rand()%2;
			if(flip == 0){heads++;}
			if(flip == 1){tails++;}
		}
		cout << setiosflags(ios::fixed) << setprecision(2);
		headsP = (double)heads/toss;
		tailsP = (double)tails/toss;
		cout << "Heads: " << heads << endl;
		cout << "Tails: " << tails << endl << endl;
		cout << "Heads Percent: " << headsP*100 << endl;
		for(int i = 0; i < headsP*100; i++){cout << "*";}
		cout << "\nTails Percent: " << tailsP*100 << endl;
		for(int i = 0; i < tailsP*100; i++){cout << "*";}
		cout << "\nWould you like to toss again? Yes or No? ";
		cin >> choice;
		cout << endl;
	}
	heads = 0;
	tails = 0;
	}while(choice == "Yes");
	cout << "Have a nice day";
	return 0;	
}
