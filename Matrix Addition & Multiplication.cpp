#include <iostream>

using namespace std;

class Matrix {
    private:
        int row, col, *A;
    public:
        Matrix(int r, int c) {
            row = r;
            col = c;
            int *p = new int[row * col]; //A[y*rows + x]
            A = p;
        }
        
        void getMatrix() {
            cout << endl <<  "Enter Matrix: " << endl;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << "Row : " << i + 1 << ", Element : " << j + 1 << " = ";
                    cin >> A[j * row + i];
                }
            }
        }
        
        void displayMatrix(int n) {
            cout << "\nMatrix M" << n << ":\n";
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << "\t" << A[j * row + i];
                }
                cout << endl;
            }
        }
        
        Matrix addMatrix(const Matrix &M2) {
            Matrix M3(row, col);
            int* M = M3.A;
            int* b = M2.A;
            for (int i = 0; i < row; i++) {
                for (int j= 0; j < col; j++) {
                    M[j * row + i] = A[j * row + i] + b[j * row + i];
                }
            }
            return M3;
        }
        
        Matrix Product(const Matrix &M2) {
            if (row == M2.col) {
                Matrix M3(col, M2.row);
                int* M = M3.A;
                int* b = M2.A;
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        M[j * row + i] = (A[j * row + i] * b[j * row + i]) + (A[(j + 1) * row + i] * b[j * row + (i + 1)]);
                    }
                }
                return M3;
            }
            else {
                cout << "Matrix Multiplication Is Not Possible!" << endl;
            }
        }
};

int* getOrder(int n = 0) {
    int *order = new int[2];
    
    cout << "Matrix Order For Matrix" << n << "\n\n";
    cout << "No. of Rows = ";
    cin >> order[0];
    cout << "No. of Columns = ";
    cin >> order[1];
    
    return order;
}
        
int main() {
    int row, col, *R;
    int option;
    cout << "Enter you choice:\n";
    cout << "1. Matrix Addition\n";
    cout << "2. Matrix Multiplication\n";
    cin >> option;
    
    if (option == 1) {
        R = getOrder();
        row = R[0];
        col = R[1];
        
        Matrix a(row, col);
        Matrix b(row, col);
        Matrix c(row, col);
        
        a.getMatrix();
        a.displayMatrix(1);
        
        b.getMatrix();
        b.displayMatrix(2);
        
        c = a.addMatrix(b);
        cout << endl << "Sum of The above Matrices, M1 + M2 = M3";
        c.displayMatrix(3);
    }
    else if (option == 2) {
        cout << endl << "Matrix Multiplication\n\n";
        
        R = getOrder(1);
        row = R[0];
        col = R[1];
        Matrix m(row, col);
        m.getMatrix();
        m.displayMatrix(1);
        
        R = getOrder(2);
        row = R[0];
        col = R[1];
        Matrix n(row, col);
        n.getMatrix();
        n.displayMatrix(2);
        
        Matrix p = m.Product(n);
        cout << endl << "Product of The above Matrices, M1 * M2 = M3";
        p.displayMatrix(3);
    }
    else {
        cout << "\t**Invalid Option** Bye!\n";
    }
    return 0;
}
