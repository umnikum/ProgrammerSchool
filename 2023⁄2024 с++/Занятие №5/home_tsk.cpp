#include <iostream>
using namespace std;

int main() {
    int array[100], array0[100], length;
    bool availability = false;
    bool availability0 = false;
    int count = 0;
    cout << "Please enter array length: ";
    cin >> length;
    for(int i=0; i<length; ++i) {
        /*вообще можно сразу проверить вводил ли пользаватель
        это число раньше, но я решил пойти более честным путём*/
        cin >> array[i];
    }
    for(int i=0; i<length; ++i) {
        for(int k=0; k<count; ++k) {
            if (array[i] == array0[k]) {
                availability0 = true;
            }
            //cout << availability << endl;
        }
        for(int j=0; j<length; ++j) {
            if (array[i]==array[j] and i != j) {
                availability = true;
            }
        }
        if (availability == false and availability0 == false) {
            array0[count] = array[i];
            ++count;
        }
        availability = false;
        availability0 = false;
    }
    for(int j=0; j<count; ++j) {
        cout << array0[j] << "\t";
    }

    return 0;
}
