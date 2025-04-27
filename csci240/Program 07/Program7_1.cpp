/******************************************************************************
CSCI 240    Assignment 7    Spring 2016
Programmer:	Lucas Damler (worked with Marty Minogue)
Section:	1
TA:			?
Date Due:	01 APR 2016 @ 11:59
Purpose:	This program lets the user play the lottery	against the computer	
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int const MAX_PICK = 5;
int const MAX_NUM = 10;

bool isDuplicate( int [], int, int );
int getUserNum( int );
void getWinners(int[], int);
void getChoices(int[], int);
void sortArray(int[], int);
void printWinners(int[], int[], int);


int main()
{
	int again = 1;
	do{
		srand(time(0));
		cout << "Lottery Game" << endl;			//The following lines and if statements ask the player if they want to play pick 3, 4, or 5
		cout << "3.) Pick 3" << endl << "4.) Pick 4" << endl << "5.) Pick 5" << endl << "Which game would you like to play? ";
	    int choice;
	    cin >> choice;
	    
	    int n = 0;
	    while(n != 3 && n != 4 && n != 5){
	    	if (choice == 3){
	    	    n = MAX_PICK - 2;
	    	}
			else if (choice == 4){
	        	n = MAX_PICK - 1;
	    	}
	    	else if (choice == 5){
	        	n = MAX_PICK;
	    	}
	    	else{
	    		cout << "Try again: ";
	    		cin >> choice;
			}
		}
		cout << endl;
		
		int lotAr[n]; int userAr[n];
		
		getChoices(userAr, n);		//The following functions are called to set up the arrays properly
		getWinners(lotAr, n);
		sortArray(userAr, n);
		sortArray(lotAr, n);
		printWinners(userAr, lotAr, n);
		
		cout << "\n\nEnter 1 to play again and anything else to quit. ";		//This asks if the user wants to play again
		cin >> again;
		cout << endl;
	
	}while(again == 1);

return 0;
}


/******************************************************************
Function:  bool isDuplicate( int [], int, int )

Use: This function determines if a value has already been placed
     into an array

Arguments: int []: the array holding all of the values
           int: the number of values the array holds
           int: the value to look for in the array

Returns: a boolean value that represents whether the value was or
         was not found in the array. true if the value is a
		 duplicate. false if the value is not a duplicate
******************************************************************/

bool isDuplicate( int array[], int arraySize, int searchNum )
{
//Loop through the array to determine if it is holding searchNum
//If a match is found, return true

for( int sub = 0; sub < arraySize; sub++ )
  {
  if( array[sub] == searchNum )
    return true;
  }

//At this point, no match was found in the array, so false is
//returned.

return false;
}

/******************************************************************
Function:  int getUserNum( int upperBd )

Use: This function gets a number from the user that is between 1
     and an upper bound

Arguments: int: the upper bound

Returns: an integer between 1 and the upper bound, inclusive

Note: This function will not display an initial prompt to the user.
******************************************************************/

int getUserNum( int upperBd )
{
int userNum;

//Get an integer number from the user

cin >> userNum;

//Validate the number that the user entered. If the number is invalid,
//display an error message to the user and get another number. Do this
//

while( userNum < 1 or userNum > upperBd )
    {
    cout << "The choice must be between 1 and " << upperBd << ", reenter: ";
    cin >> userNum;
	}

//Return the valid value
return userNum;
}


//getWinners takes an array and an int and fills the array with non repeating random numbers between 1 and 10
void getWinners(int ar1[], int numVal){
	ar1[numVal];
	int randnum = 0;
	for(int i = 0; i < numVal; i++){
		ar1[i] = 0;
	}
	for(int i = 0; i < numVal; i++){
		while(isDuplicate(ar1, numVal, randnum)){
			randnum = rand()%MAX_NUM + 1;
		}
		ar1[i] = randnum;
	}
	
}

//getChoices takes an array and an int and asks the user to enter int length of non repeating numbers between 1 and 10
void getChoices(int ar1[], int numVal){
	int num = 0;
	for(int i = 0; i < numVal; i++){
		ar1[i] = 0;
	}
	for(int i = 0; i < numVal; i++){
		while(isDuplicate(ar1, numVal, num)){
			cout << "User Choice " << i+1 << ": ";
			num = getUserNum(MAX_NUM);
		}
		ar1[i] = num;
	}
}

//sortArray takes an array and an int and sorts any array passed in from lowest to highest
void sortArray(int ar1[], int numVal){
	int minPos;
	int temp;

	for(int i = 0; i < numVal-1; i++){
		for(int j = i+1; j < numVal; j++){
			if(ar1[i] > ar1[j]){
				temp = ar1[i];
				ar1[i] = ar1[j];
				ar1[j] = temp;
			}
		}
	}
}

//printWinners compers two passed in arrays and decides if and how much the user won based on the user's choice of numbers
void printWinners(int userAr[], int winAr[], int numVal){
	cout << endl << "Choices: ";
	for(int i = 0; i < numVal; i++){
		cout << userAr[i] << " ";
	}
	cout << endl << "Winners: ";
	for(int i = 0; i < numVal; i++){
		cout << winAr[i] << " ";
	}
	
	int cnt = 0;
	double arDub[6] ={0.00, 1.00, 5.00, 10.00, 20.00, 25.00};
	
	for(int i = 0; i < numVal; i++){
		for(int j = 0; j < numVal; j++){
			if(userAr[i] == winAr[j]){
				cnt++;
			}
		}
		
	}
	if(arDub[cnt] == 0.00){
		cout << endl << "The house always wins ;)";
	}
	else{
		cout << endl << "User won: $" << arDub[cnt];
	}
	
}




