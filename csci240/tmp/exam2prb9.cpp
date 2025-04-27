#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	double ar[5] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 2; i++){
		ar[i] *= ar[i];
	}
	for(int i = 0; i < 5; i++){
		cout << ar[i] << " ";
	}
	return 0;
}
