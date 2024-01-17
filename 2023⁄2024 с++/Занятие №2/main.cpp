#include <iostream>

using namespace std;

int mainn(){
	cout << "Solving equation: a*x^2 + b*x + c = 0" << endl;
	float a, b, c;
	cin >> a >> b >> c;

	if(a != 0){
		float d = b*b - 4*a*c;
		if(d>0){
			cout << "there are 2 roots";
		}else if(d==0){
			cout << "there is 1 root";
		}else{
			cout << "there are no roots!";
		}
	}else{
		if(b == 0){
			if(c == 0){
				cout << "there are infinite roots!";
			}else{
				cout << "there are no roots!";
			}
		}else{
			cout << "there is 1 root";
		}
	}
	return 0;
}
