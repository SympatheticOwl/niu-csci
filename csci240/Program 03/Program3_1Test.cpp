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
	if(toss >= 0){
		choice = 1;
		for(int i = 0; i < toss; i++){
			flip = rand()%2;
			if(flip == 0){heads++;}
			if(flip == 1){tails++;}
		}
	cout << setiosflags(ios::fixed) << setprecision(2);
	headsP = (double)heads/toss;
	tailsP = (double)tails/toss;
	cout << "\nHeads: " << heads << endl;
	cout << "Tails: " << tails << endl << endl;
	cout << "Heads Percent: " << headsP*100 << endl;
	cout << "Tails Percent: " << tailsP*100 << endl;
	}
	else{
		cout << "Please enter a positive whole number ";
		cin >> toss;
	}
	cout << "\nWould you like to toss again? Yes or No? ";
	cin >> choice;
	cout << endl;
	heads = 0;
	tails = 0;
	}while(choice == "Yes");
	cout << "Have a nice day";
	return 0;	
}
