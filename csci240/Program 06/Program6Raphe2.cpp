/******************************************************************************
CSCI 240    Assignment 6    Spring 2016
Programmer:	
Section:	
TA:			
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
	int _passCount = 0; int special = 0; int upperC = 0; int lowerC = 0; int number = 0;
	int valid = 0; int total_valid = 0;
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
			_passCount++;
			ch = inputFile.get();
		}
		if (_passCount < 6)
        {
            cout << "Not enough characters\n";
            valid++;
        }
        if (special == 0)
        {
            cout << "Missing alphabetic character\n";
            valid++;
        }
        if (upperC == 0)
        {
            cout << "Missing uppercase letter\n";
            valid++;
        }
        if (lowerC == 0)
        {
            cout << "Missing lowercase letter\n";
            valid++;
        }
        if (number == 0)
        {
            cout << "Missing digit\n";
            valid++;
        }
        if (special == 0)
        {
            cout << "Missing special character\n";
            valid++;
        }
        if (valid == 0)
        {
            cout << "Valid password\n";
            total_valid++;
        }
			_passCount = 0; special = 0; upperC = 0; lowerC = 0; number = 0;
		}
		cout << endl;
		inputFile >> ch;
		
		inputFile.close();
	cout << "\nNumber of passwords: " << total_valid << endl;
	cout << "Valid passwords: " << valid << endl;
	cout << "Invalid passwords: " << total_valid - valid;
	
	return 0;
	
	}
//	

bool isSpecial(char ch)
{
	if((int)ch == 35 || (int)ch == 36 || (int)ch == 37 || (int)ch == 42)
	{
		return true;
	}
	else
	{
		return false;
	}
}
