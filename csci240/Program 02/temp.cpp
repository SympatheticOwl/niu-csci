/***************************************************************
CSCI 240         Program 2     Spring 2016
Programmer: Lucas Damler
Section: 1
Date Due: 05 FEB 2016 @ 23:59
Purpose: This program calculates the area of various shapes
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double ar[4] = {1,2,3,4};
	for(int i = 0; i < 4; i++){
		cout << ar[i];
	}
	cout << endl;
	for(int i = 0; i < 4; i++){
		ar[i] *= ar[i];
	}
	for(int i = 0; i < 4; i++){
		cout << ar[i];
	}
}
