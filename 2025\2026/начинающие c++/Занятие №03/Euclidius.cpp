#include <iostream>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	do{
		if(a<b) swap(a,b);
		a = (a%b)? a%b : b;
	}while(a>b);
	cout << a;
}
