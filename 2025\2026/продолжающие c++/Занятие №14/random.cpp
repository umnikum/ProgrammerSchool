#include <iostream>
#include <random>

using namespace std;

int main(){
	mt19937 gen{random_device{}()};
	uniform_int_distribution<int> dist(1, 6);
	
	cout << "random 1d6 roll: " << dist(gen);
	return 0;
} 
