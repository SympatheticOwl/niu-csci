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
	string wrd;
	int cnt = 0; int alph = 0; int up = 0; int lo = 0; int dig = 0;
	ifstream infile;
	c = infile.get();
	infile.open("password.txt");

	if(infile.fail()){
		cout << "input file did not open" << endl;
		exit(-1);
	}
	else{
		//int alph = 0; int up = 0; int lo = 0; int dig = 0;
		while(infile){
			//infile >> wrd;
			//cout << wrd << endl;
			while(c != 12){
				//infile >> wrd;
				//cout << wrd;
				//cout << wrd;
				//cout << c << endl;
				infile >> c;
				cout << c;
				
				if(isdigit(c)){
					dig++;
				}
				else if(isupper(c)){
					up++;
				}
				else if(islower(c)){
					lo++;
				}
				cnt++;
				exit(-1);
			}
			//wrd = infile.get();
			if(dig > 0 && up > 0 && lo > 0 && cnt >= 7){
					cout << "wrd" << endl;
				}
				else{
					cout << "No wrd" << endl;
				}	
		}
		
	}
	infile.close();
	
	cout << "\nCount: " << cnt << endl;
	cout << "\nUpper: " << up << endl;
	cout << "\nLower: " << lo << endl;
	cout << "\nSpecial: " << alph << endl;
	cout << "\nDigit: " << dig << endl;
	
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

			/*//c = infile.get();
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
			*/
