#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int **mines = new int*[n];
	for(int i=0; i<n; ++i)
		mines[i] = new int[n];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> mines[i][j];

	int **field = new int*[n];
	for(int i=0; i<n; ++i){
		field[i] = new int[n];
		for(int j=0; j<n; ++j)
			field[i][j] = 0;
	}

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(mines[i][j] == 1)
				for(int y=max(0, i-1); y<=min(n-1, i+1); ++y)
					for(int x=max(0, j-1); x<=min(n-1, j+1); ++x)
						if(!(x==j and y==i))
							field[y][x]++;

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j){
			if(mines[i][j]==1)
				cout << "*";
			else
				cout << field[i][j];
			cout << ((j == n-1)?"\n":"\t");
		}

	delete [] field;
	delete [] mines;
	return 0;
}
