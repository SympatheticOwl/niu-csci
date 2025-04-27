/*


*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int const MAX_PICK = 5;
int const MAX_NUM = 10;

//function prototypes

bool isDuplicate( int [], int, int );
int getUserNum( int );
void getWinners(int[], int);
void getChoices(int[], int);
void sortArray(int[], int);
void printWinners(int[], int[], int);


int main()
{
	srand(time(0));
	int lotAr[MAX_PICK]; int userAr[MAX_PICK];
	
	getChoices(userAr, MAX_PICK);
	getWinners(lotAr, MAX_PICK);
	sortArray(userAr, MAX_PICK);
	sortArray(lotAr, MAX_PICK);
	printWinners(userAr, lotAr, MAX_PICK);

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

void getWinners(int ar1[], int numVal){
	ar1[numVal];
	int num;
	for(int i = 0; i < numVal; i++){
		while(isDuplicate(ar1, numVal, num)){
			num = rand()%(MAX_NUM + 1);
		}
		ar1[i] = num;
	}
	
}

void getChoices(int ar1[], int numVal){
	int num;
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
	cout << endl << "User won: $" << arDub[cnt];
}




