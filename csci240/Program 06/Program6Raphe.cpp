/******************************************************************************
CSCI 240    Assignment 6    Spring 2016
Programmer:	Raphael Escobedo
Section: 2
TA:			
Date Due: March 25th, 2016
Purpose: This program will be used to validate passwords
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

bool isSpecial(char);

int main(){
	int _charCount = 0; int special = 0; int upperC = 0; int lowerC = 0; int number = 0; int _passCount = 0;
	int invalid = 0; int total_valid = 0;
	ifstream inputFile;
	inputFile.open("password.txt");
	
	if(inputFile.fail()){
		cout << "Failure to open";
		exit(-1);
	}
	
	char ch;
	ch = inputFile.get();
	
	while(inputFile){
		while(!isspace(ch))
			{
			cout << ch;
			if(isdigit(ch))
			{
				number++;
			}
			else if(isupper(ch))
			{
				upperC++;
			}
			else if(islower(ch))
			{
				lowerC++;
			}
			else if(isSpecial(ch))
			{
				special++;
			}
			_charCount++;
			ch = inputFile.get();
		}
		
        _passCount++;
        cout << endl;
    
        if (_charCount < 6)
        {
            cout << "Not enough characters\n";
            invalid++;
        }
        if (special == 0)
        {
            cout << "Missing special character\n";
            invalid++;
        }
        if (upperC == 0)
        {
            cout << "Missing uppercase letter\n";
            invalid++;
        }
        if (lowerC == 0)
        {
            cout << "Missing lowercase letter\n";
            invalid++;
        }
        if (number == 0)
        {
            cout << "Missing digit\n";
            invalid++;
        }
        if (invalid == 0)
        {
            cout << "Valid password\n";
            total_valid++;
        }
		cout << endl;
		
	_charCount = 0; special = 0; upperC = 0; lowerC = 0; number = 0; invalid = 0;
		
		inputFile >> ch;
	}
	inputFile.close();
	cout << "\nNumber of passwords: " << _passCount << endl;
	cout << "Valid passwords: " << total_valid << endl;
	cout << "Invalid passwords: " << _passCount - total_valid;
	
	return 0;
}

bool isSpecial(char ch)
{
	if(ch == '$' || ch == '%' || ch == '#' || ch == '*')
	{
		return true;
	}
	else
	{
		return false;
	}
}
