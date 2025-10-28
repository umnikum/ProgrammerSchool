#include <iostream>

using namespace std;

int main(){
	int numbers[10], num, index=0;
	for(int i=0; i<10; ++i)
		cin >> numbers[i];
	cin >> num;
	for(int i=0; i<10; ++i)
		if(num == numbers[i]){
			index=i;
			break;
		}
	cout << index;
	return 0;
}

