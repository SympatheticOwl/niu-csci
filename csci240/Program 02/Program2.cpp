/***************************************************************
CSCI 240         Program 2     Spring 2016
Programmer: Lucas Damler
Section: 1
Date Due: 05 FEB 2016 @ 23:59
Purpose: This program calculates the area of various shapes

Sources:
PI - http://stackoverflow.com/questions/6563810/m-pi-works-with-math-h-but-not-with-cmath-in-visual-studio
***************************************************************/

#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main(){
	float radius, base, height, lengthSemiMajor, lengthSemiMinor;
	float areaC, areaT, areaE;
	int choice;

	do{
			cout << "Enter number of area you would like to calculate: ";
		cout << "\n1.) Circle \n2.) Triangle \n3.) Ellipse \n4.) Quit" << endl;
		cin >> choice;
		cout << setiosflags(ios::fixed) << setprecision(2) << endl;
		if(choice == 1){
			cout << "Enter radius of circle: ";
			cin >> radius;
			areaC = M_PI*(radius*radius);
			cout << "Area is: " << areaC << endl << endl;
		}
		if(choice == 2){
			cout << "Enter Base: ";
			cin >> base;
			cout << "Enter Height: ";
			cin >> height;
			cout << "Area is: " << (base*height)/2 << endl << endl;
		}
		if(choice == 3){
			cout << "Enter length of semi-major axis: ";
			cin >> lengthSemiMajor;
			cout << "Enter length of semi-minor axis: ";
			cin >> lengthSemiMinor;
			areaE = M_PI*lengthSemiMajor*lengthSemiMinor;
			cout << "Area is: " << areaE << endl << endl;
		}
		if(choice == 4){
			cout << "\nI'm sorry Dave, I'm afraid I can't do that...\n";
		}
	}while(choice >= 1 && choice < 5);
	if(choice >= 5 || choice < 1){
		cout << "\nGoodbye. Have a nice day...";
		return 0;
	}
}
