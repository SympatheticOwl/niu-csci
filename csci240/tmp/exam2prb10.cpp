#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	double sum;
	double ar[] = {1.1, 2.2, 3.3, 4.4};
	for(int i = 0; i < 4; i++){
		sum += ar[i];
	}
	cout << sum;
}
