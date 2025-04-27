#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
//5
int GetIntegerRange(int);

int main(){
	int temp, hiSum = 0, lowSum = 0, cnt = 0, sum = 0;
	int hiTemp = 0, lowTemp = 0;
	do{
		temp = GetIntegerRange(120);
		if(temp > 32){
			hiSum += temp;
			hiTemp++;
		}
		else if(temp < 32){
			lowSum += temp;
			lowTemp++;
		}
		else{
			sum += temp;
			cnt++;
		}
	}while(temp != 0);
	
	cout << "Avg below 32: " << lowSum/lowTemp << endl;
	cout << "Amount below 32: " << lowTemp << endl;
	cout << "Avg above 32: " << hiSum/hiTemp << endl;
	cout << "Amount above 32: " << hiTemp << endl;
	cout << "Avg 32: " << sum/cnt << endl;
	cout << "32: " << cnt;
	
	return 0;
}

int GetIntegerRange(int max){
	int choice;
	cout << "Enter a value between 0 and " << max << " (0 to quit): ";
	cin >> choice;
	while(choice > max && choice < max && choice == 0){
		cout << "ERROR. Try again: ";
		cin >> choice;
	}
	
	return choice;
}
