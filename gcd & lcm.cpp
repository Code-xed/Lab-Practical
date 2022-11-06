#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int rem;
    if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    do {
        rem = a % b;
        a = b;
        b = rem;
    }
    while(rem);
    return a;
}

int lcm(int a, int b) {
    if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    return gcd(a, a % b);
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

