#include <iostream>
#include <cmath>

using namespace std;

void addition(double a, double b) {
    cout << "Result: " << a + b << endl;
}
void subtraction(double a, double b) {
    cout << "Result: " << a - b << endl;
}
void multiplication(double a, double b) {
    cout << "Result: " << a * b << endl;
}
void division(double a, double b) {
    if (b != 0) {
        cout << "Result: " << a / b << endl;
    } else {
        cout << "Error" << endl;
    }
}
void power(long double a, double b) {
    cout << " Result: " << pow(a, b) << endl;
}


int main() {

    char operation;
    double a, b;
    int choice;
    int n;

    cout << "Choose operation type:" << '\n' << "Mathematical operation - 1" << '\n'
         << "Factorial calculation - 2" << '\n' << "Sum of matrix - 3" << '\n';
    cin >> choice;

while (choice == 1) {
    cout << "Enter math expression: ";
    cin >> a >> operation >> b;
    switch (operation) {
        case '+':
            addition(a, b);
            break;
        case '-':
            subtraction(a, b);
            break;
        case '*':
            multiplication(a, b);
            break;
        case '/':
            division(a, b);
            break;
        case '^':
            power(a, b);
            break;
        default:
            cout << "Error" << endl;
    }
}
while (choice == 2) {
    cout << "Factorial calculation: " << endl;
    cin >> a;
    unsigned long long int f = 1;
    for (long int i = 1; i <= a; i++) {
        f = f * i;
    }
    cout << "Result: " << f << "\n";
    break;
}
while (choice == 3) {
    int matrix1[3][3];
    int matrix2[3][3];

    cout << "Enter first matrix:" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> n;
            matrix1[i][j] = n;
        }
    }
    cout << "First matrix:" << '\n';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix1[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "Enter second matrix:" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> n;
            matrix2[i][j] = n;
        }
    }

    cout << "Second matrix:" << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix2[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "Sum of matrix: " << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix1[i][j] + matrix2[i][j] << "\t";
        }
        cout << "\n";
    }
    break;
}
return 0;
}