#include <iostream>

using namespace std;

int mainM(){
	int array[100], length;
	cout << "Please enter array length: ";
	cin >> length;
	for(int i=0; i<length; ++i)
		cin >> array[i];

	int min = array[0], max = array[0];
	for(int i=1; i<length; ++i){
		if(min > array[i])
			min = array[i];
		if(max < array[i])
			max = array[i];
	}
	cout << "Array values range from: " << min << " to: " << max;
	return 0;
}
