#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a, b;
    cout << "Enter 2 Numbers to swap(Pass-by-reference):\n";
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    
    cout << "Before Swapping:\n\t";
    cout << "A = " << a << " & B = " << b << endl;
    
    swap(a, b);
    
    cout << "After Swapping:\n\t";
    cout << "A = " << a << " & B = " << b;
    return 0;
}

