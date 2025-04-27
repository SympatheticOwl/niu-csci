#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

//1
int weight(double weight){
	int cost;
	if(weight <= 1){
		cost = 33;
	}
	else if(weight > 1 && weight <= 1.5){
		cost = 40;
	}
	else if(weight > 1.5 && weight <= 2){
		cost = 50;
	}
	else{
		cost = weight*30;
	}
	return cost;
}

//2
char getAns(){
	char choice;
	int loop = 1;
	cout << "Enter a letter between 'a' and 'd': ";
	cin >> choice;
	do{
		
		if(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd'){
			cout << "ERROR. Try again: ";
			cin >> choice;
		}
		else{
			loop = 0;
		}
	}while(loop == 1);
	return choice;
}

//3
cout << getAns();

//4
int GetIntegerRange(int max){
	int choice;
	
	cout << "Enter a value between 0 and " << max << " (0 to quit): ";
	cin >> choice;
	do{
		cout << "ERROR. Try again: ";
		cin >> choice;
	}while(choice > max || choice < max || choice == 0);
	return choice;
}

//6
for(int i = 0; i < 45; i+=2){
	cout << AR[i];
}

//7
int temp;
temp = AR[0];
AR[0] = AR[9];
AR[9] = temp;

//8
int ar[500] = {2, 4};

//9
void squareShit(doube ar[], int n){
	for(int i = 0; i < n; i++){
		ar[i] *= ar[i];
	}
}

//10
double nElements(double ar[], int n){
	double sum;
	for(int i = 0; i < n; i++){
		sum += ar[i];
	}
	return sum;
}












