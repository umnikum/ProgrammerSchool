#include <iostream>

using namespace std;

int main(){
	int l_1, w_1, h_1, l_2, w_2, h_2;
	cin >> l_1 >> w_1 >> h_1 >> l_1 >> w_1 >> h_1;
	if(l_1 < w_1) swap(l_1, w_1);
	if(l_1 < h_1) swap(l_1, h_1);
	if(w_1 < h_1) swap(w_1, h_1);
	
	if(l_2 < w_2) swap(l_2, w_2);
	if(l_2 < h_2) swap(l_2, h_2);
	if(w_2 < h_2) swap(w_2, h_2);
	
	if(l_1 < l_2){
		swap(l_1, l_2);
		swap(w_1, w_2);
		swap(h_1, h_2);
	}
	
	if(l_1 >= l_2 and w_1 >= w_2 and h_1 >= h_2)
		cout >> "yes";
	else cout >> "no";
	return 0;
}
