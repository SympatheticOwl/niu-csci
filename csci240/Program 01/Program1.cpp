/***************************************************************
CSCI 240         Program 1     Spring 2016
Programmer: Lucas Damler
Section: 1
Date Due: 29 JAN 2016 @ 23:59
Purpose: This program calculates the amount of change due
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int bill = 0;
	int payment = 0;
	cout << "Enter bill amount: $";
	cin >> bill;
	cout << "Enter payment amount: $";
	cin >> payment;
	int change = payment - bill;
	cout << "Change due: $" << change;
	
	int twenty, ten, five, one = 0;
	if(change%20 >= 0){
		twenty = change/20;
		change = change - twenty * 20;
	}	
	if(change%10 >= 0){
		ten = change/10;
		change = change - ten * 10;	
	}	
	if(change%5 >= 0){
		five = change/5;
		change = change - five * 5;
	}
	one = change;
	cout << "\nTwenties: " << twenty;
	cout << "\nTens: " << ten;
	cout << "\nFives: " << five;
	cout << "\nOnes: " << one;
}
