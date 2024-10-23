#include <iostream>
#include <string>

using namespace std;

int fact(int N){
	if(N < 2)
		return 1;
	else
		return N * fact(N-1);
}

bool has_exclamation(string word){
	return find(word.begin(), word.end(), '!') < word.end();
}

int main(){
	int N;
	cin >> N;
	cout << N << "! = " << fact(N);
	return 0;
}
