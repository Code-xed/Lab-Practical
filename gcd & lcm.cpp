#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int gcd(int a, int b) {
    int rem; 
    if (b > a) {
        swap(a, b);
    }
    //Recursive
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
    /* 
      * //Non-Recursive
    do {
        rem = a % b;
        a = b;
        b = rem;
    }
    while(rem);
    return a;
    */
    
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    cout << "Enter 2 Numbers to find their GCD & LCM:\n";
    cin >> a >> b;
    
    cout << "GCD of " << a << " & " << b;
    cout << " is = " << gcd(a, b) << endl;
    
    cout << "LCM of " << a << " & " << b;
    cout << " is = " << lcm(a, b) << endl;
    return 0;
}

