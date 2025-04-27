/******************************************************************************
CSCI 240    Assignment 6    Spring 2016
Programmer:	Lucas Damler
Section:	1
TA:			?
Date Due:	25 MAR 2016 @ 11:59
Purpose:	This program checks strings in a text file and decides if they are valid passowrds			
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
		if(cnt >= 6 && dig > 0 && up > 0 && lo > 0 && alph > 0){
			valid++;
			cout << " - Pass" << endl;
			cnt = 0; alph = 0; up = 0; lo = 0; dig = 0;
		}
		else{
			invalid++;
			cout << " - Fail";
			if(cnt < 6){cout << "\nToo short";}
			if(up < 1){cout << "\nMissing upper case letter";}
			if(lo < 1){cout << "\nMissing lower case letter";}
			if(alph < 1){cout << "\nMissing special character\n";}
			cnt = 0; alph = 0; up = 0; lo = 0; dig = 0;
		}
		cout << endl;
		inputFile >> ch;
	}
	inputFile.close();
	cout << "\nNumber of passwords: " << valid+invalid << endl;
	cout << "Valid passwords: " << valid << endl;
	cout << "Invalid passwords: " << invalid;
	
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
