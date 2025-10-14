#include <iostream> 
using namespace std;

int main(){
	int start, finish;
	cin >> start >> finish;
	cout << ((start < finish)? finish-start : finish+12 - start);
}
