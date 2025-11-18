#include <iostream>

using namespace std;

int main(){
	string line;
	cin >> line;
	int x=line[0]-'A', y=line[1]-'0';
	int x1=x-2, y1=y-1;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	y1=y+1;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	x1=x+2; y1=y-1;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	y1=y+1;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	x1=x-1; y1=y-2;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	y1=y+2;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	x1=x+1; y1=y-2;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	y1=y+2;
	if(x1 < 0 or y1 < 0 or x1 > 7 or y1 > 7) cout << ('A'+x1) << "\t" << y1 << "\n";
	return 0;
}
