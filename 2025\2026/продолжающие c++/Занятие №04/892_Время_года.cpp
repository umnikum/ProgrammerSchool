#include <iostream> 
using namespace std;

int main(){
	int month;
	cin >> month;
	if(month < 3 or month == 12){
		cout << "Winter";
	}else if(month < 6){
		cout << "Spring";
	}else if(month < 9){
		cout << "Summer";
	}else if(month < 12){
		cout << "Autumn";
	}else cout << "Error";
} 
