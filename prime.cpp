#include<iostream>

using namespace std;

int main() {
    int a, count = 0;
    cout << "Enter A Number To Check If Prime Or Not: ";
    cin >> a;
    for (int i = 1; i <= a; i ++) {
        if (a % i == 0) {
            count += 1;
        }
    }
    cout << a << " is ";
    if (count != 2) {
        cout << " not ";
    }
    cout << "a Prime Number.";
    return 0;
}

