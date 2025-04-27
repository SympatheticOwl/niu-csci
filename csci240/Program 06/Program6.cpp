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

int main(){
	char c;
	int cnt = 0;
	ifstream infile;
	c = infile.get();
	infile.open("password.txt");
	if(infile.fail()){
		cout << "input file did not open" << endl;
		exit(-1);
	}
	else{
		while(infile.good()){
			c = infile.get();
			cout << c;
		}
		infile.close();
	}
	//return 0;
	
	while(infile.good()){
		if(isdigit(c)){
			cnt++;
		}
		else if(isalpha(c)){
			cnt++;
		}
		else if(isupper(c)){
			cnt++;
		}
		else{
			cnt++;
		}
	}
	cout << endl << cnt << endl;
	
	for (int i = ' '; i <= 'z'; i++){
		cout << "\nThe ASCII value of " << (char) i << " is " << i;
	}
}
