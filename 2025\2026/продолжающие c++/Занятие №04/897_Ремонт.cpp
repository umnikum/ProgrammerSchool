#include <iostream> 
#include <math.h>
using namespace std;

int main(){
	float L, W, H;
	cin >> L >> W >> H;
	cout << ceil((L*H + W*H)/8);
} 
