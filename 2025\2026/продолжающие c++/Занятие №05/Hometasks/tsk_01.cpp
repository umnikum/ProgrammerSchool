#include <iostream>

using namespace std;

int main(){
	int numbers[10], counter=0;
	for(int i=0; i<10; ++i){
		cin >> numbers[i];
		if(numbers[i] < 0) counter++;
	}
	cout << counter;
	return 0;
}

