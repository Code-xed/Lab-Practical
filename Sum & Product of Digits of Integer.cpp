#include <iostream>

using namespace std;

int main() {
    int a, rem, sum, product, temp;
    cout << "Enter A Number: " << endl;
    cin >> a;
    
    temp = a;
    sum = 0;
    product = 1;
    
    while(temp) {
        rem = temp % 10;
        sum += rem;
        product *= rem;
        temp = temp / 10;
    }
    
    cout << a << " --> " << "Sum of Digits: " << sum << endl;
    cout << a << " --> " << "Product of Digits: " << product << endl;
    
    return 0;
}

