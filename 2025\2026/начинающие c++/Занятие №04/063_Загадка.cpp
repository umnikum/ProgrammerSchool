#include <iostream>
#include <math.h>
 
using namespace std; 
 
int main(){
    int s, p, d;
    cin >> s >> p;
    d = (int)sqrt(s*s-4*p);
    cout << (s-d)/2 << " " << (s+d)/2;
    return 0;
} 
