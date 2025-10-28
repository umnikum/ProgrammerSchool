#include <iostream>

using namespace std;

int main(){
	int numbers[10], median, index=0;
	for(int i=0; i<10; ++i)
		cin >> numbers[i];
	
	for(int i=1; i<10; ++i)
		for(int j=i-1; j>=0; --j)
			if(numbers[j+1]<numbers[j]) swap(numbers[j], numbers[j+1]);
			else break;
	
	cout << numbers[5];
	return 0;
}
 
