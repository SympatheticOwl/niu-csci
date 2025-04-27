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
#include <fstream>
#include <cstdlib>

using namespace std;

bool isSpecial(char);

int main(){
	int cnt = 0; int alph = 0; int up = 0; int lo = 0; int dig = 0;
	int valid = 0; int invalid = 0;
	ifstream inputFile;
	inputFile.open("password.txt");
	
	if(inputFile.fail()){
		cout << "Failure to open";
		exit(-1);
	}
	
	char ch;
	//string gets full words/lines
	//inputFile >> ch;
	ch = inputFile.get();
	
	while(inputFile){
		
		while(!isspace(ch)){
			cout << ch;

			if(isdigit(ch)){
				dig++;
			}
			else if(isupper(ch)){
				up++;
			}
			else if(islower(ch)){
				lo++;
			}
			else if(isSpecial(ch)){
				alph++;
			}
			
			cnt++;
			ch = inputFile.get();
		}
		if(cnt >= 7 && dig > 0 && up > 0 && lo > 0){
			valid++;
			cout << " Pass" << endl;
			cnt = 0; alph = 0; up = 0; lo = 0; dig = 0;
		}
		else{
			invalid++;
			if(cnt < 7){cout << "\nToo short";}
			if(up < 1){cout << "\nMissing upper case letter";}
			if(lo < 1){cout << "\nMissing lower case letter";}
			if(alph < 1){cout << "\nMissing special character\n";}
			cnt = 0; alph = 0; up = 0; lo = 0; dig = 0;
		}
		cout << endl;
		inputFile >> ch;
	}
	cout << "\nCount: " << cnt << endl;
	cout << "\nUpper: " << up << endl;
	cout << "\nLower: " << lo << endl;
	cout << "\nSpecial: " << alph << endl;
	cout << "\nDigit: " << dig << endl;
	
	return 0;
}

bool isSpecial(char ch){
	if((int)ch == 35 || (int)ch == 36 || (int)ch == 37 || (int)ch == 42){
		return true;
	}
	else{
		return false;
	}
}
