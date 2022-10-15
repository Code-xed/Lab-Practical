#include <iostream>

using namespace std;

int main() {
    float a, b, c, max;
    cout << "Enter 3 Numbers: " << endl;
    cin >> a >> b >> c;
    
    if (a > b) {
        if (a > c) {
            max = a;
        }
        else {
            max = c;
        }
    }
    else {
        if (b > c) {
            max = b;
        }
        else {
            max = c;
        }
    }
    
    cout << "Greatest Number Is: " << max << endl;
    return 0;
}

