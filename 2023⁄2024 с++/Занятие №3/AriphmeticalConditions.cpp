#include <iostream>

using namespace std;

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	//Базовые математические условия
	if(n1 == n2)
		cout << n1 << " == " << n2 << endl;
	if(n1 != n2)
		cout << n1 << " != " << n2 << endl;
	if(n1 > n2)
		cout << n1 << " > " << n2 << endl;
	if(n1 < n2)
		cout << n1 << " < " << n2 << endl;
	if(n1 >= n2)
		cout << n1 << " >= " << n2 << endl;
	if(n1 <= n2)
		cout << n1 << " <= " << n2 << endl;
	return 0;
}
