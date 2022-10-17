#include <iostream>

using namespace std;

int main() {
    string op;
    int option;
    float a, b, answer;
    cout << "Enter 2 Numbers: " << endl;
    cin >> a >> b;
    cout << "Which Arithematic Operation Do You Want To Do?\n";
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Division" << endl;
    cout << "4. Multiplication" << endl;
    cin >> option;
    
    switch(option) {
        case 1:
            op = " + ";
            answer = a + b;
            break;
        case 2:
            op = " - ";
            answer = a - b;
            break;
        case 3:
            op = " / ";
            answer = a / b;
            break;
        case 4:
            op = " * ";
            answer = a * b;
            break;
        default:
            cout << "\t**Invalid Option**\n";
            return 0;
            break;
    }
    
    cout << a << op << b << " = " << answer << endl;
    return 0;
}

