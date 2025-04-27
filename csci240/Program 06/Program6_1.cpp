/******************************************************************************
CSCI 240    Assignment 6    Spring 2016
Programmer:	Lucas Damler
Section:	1
TA:			?
Date Due:	
Purpose:				
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <fstream>

using namespace std;

bool isSpecial(char);

int main(){
	char c;
	int cnt = 0;
	int alph = 0; int up = 0; int lo = 0; int dig = 0;
	ifstream infile;
	c = infile.get();
	infile.open("password.txt");

	if(infile.fail()){
		cout << "input file did not open" << endl;
		exit(-1);
	}
	else{
		while(infile.good()){
			//c = infile.get();
			cout << c << endl;
			infile >> c;
			if(isdigit(c)){
				dig++;
			}
			else if(isupper(c)){
				up++;
			}
			else if(islower(c)){
				lo++;
			}
			else if(isSpecial(c)){
				cout << (int)c << c << " ";
				alph++;
			}
			cnt++;
		}
		//if()
	}
/*	infile.close();
	cout << "\nCount: " << cnt << endl;
	cout << "\nUpper: " << up << endl;
	cout << "\nLower: " << lo << endl;
	cout << "\nSpecial: " << alph << endl;
	cout << "\nDigit: " << dig << endl;*/
	//for (int i = ' '; i <= 'z'; i++){
		//cout << "\nThe ASCII value of " << (char) i << " is " << i;
	//}
}

bool isSpecial(char c){
	/*int x = (int)(c);
	if(x = 36 || x = 37 || x = 35 || x = 42){
		return true;
	}
	else{
		return false;
	}*/
}
