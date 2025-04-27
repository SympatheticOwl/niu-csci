/***************************************************************
CSCI 240         Program 3     Spring 2016
Programmer: Lucas Damler
Section: 1
Date Due: 12 FEB 2016 @ 23:59
Purpose: This program counts rando numbers
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int num, set = 1;
	int ninePerm = 0, eightPerm = 0, sevenPerm = 0, sixPerm = 0, fivePerm = 0;
	string choice = "Yes";
	srand(time(0));
	do{
		int nine = 0, eight = 0, seven = 0, six = 0, five = 0;
		cout << "Set " << set << endl;
		for(int i = 0; i < 10; i++){
			num = 50+(rand()%51);
			cout << num << " ";
			if(num >= 90){nine++;}
			if(num >= 80 && num <= 89){eight++;}
			if(num >= 70 && num <= 79){seven++;}
			if(num >= 60 && num <= 69){six++;}
			if(num <= 59){five++;}
		}
		set++;
		cout << endl << "\n90's +: " << nine << " "
		 	 << "80's: " << eight << " "
		 	 << "70's: " << seven << " "
			 << "60's: " << six << " "
			 << "50's: " << five;
		ninePerm += nine; eightPerm += eight; sevenPerm += seven; sixPerm += six; fivePerm += five;
		cout << "\n\nRun again? Yes or No? ";
		cin >> choice;
		cout << endl;
	}while(choice == "Yes");
	cout << endl << "Totals"
		 << "\n90's +: " << ninePerm << endl
		 << "80's: " << eightPerm << endl
		 << "70's: " << sevenPerm << endl
		 << "60's: " << sixPerm << endl
		 << "50's: " << fivePerm;
}
