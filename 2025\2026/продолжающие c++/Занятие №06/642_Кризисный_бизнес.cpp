#include <iostream>

using namespace std;

int main(){
	int N, S;
	cin >> N >> S;
	int *cars=new int[N];
	for(int i=0; i<N; ++i)
		cin >> cars[i];
	
	for(int i=1; i<N; ++i)
		for(int j=i-1; j>=0; --j)
			if(cars[j+1]<cars[j]) swap(cars[j], cars[j+1]);
			else break;
	
	int counter=0, sum=0;
	while(sum+cars[counter] <= S and counter < N){
		sum += cars[counter++];
	}
	cout << counter;
	delete [] cars;
	return 0;
} 
