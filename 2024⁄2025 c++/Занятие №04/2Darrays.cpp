#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	double **arr = new double*[n];
	for(int i=0; i<n; ++i)
		arr[i] = new double[n];

	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << arr[i][j] << ((j == n-1)?"\n":"\t");
		}
	}
	delete [] arr;
	return 0;
}
