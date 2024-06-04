#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class vect {
public:
    static int count;
    int dim;
    vector<double> b;
    int num;

    explicit vect(int dimension) : dim(dimension), b(dimension) {
        num = ++count;
        cout << "Vector #" << num << " created" << endl;
    }

    ~vect() {
        cout << "Vector #" << num << " deleted" << endl;
    }

    vect operator+(const vect &v) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] + v.b[i];
        }
        cout << "Sum of vectors #" << num << " and #" << v.num << " = "  << endl;
        return result;
    }

    vect operator-(const vect &v) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] - v.b[i];
        }
        cout << "Substraction of vectors #" << num << " and #" << v.num << " = " << endl;
        return result;
    }

    vect operator-() const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = -b[i];
        }
        cout << "Opposite of vector #" << num << " = " << endl;
        return result;
    }

    double operator*(const vect &v) const {
        double result = 0;
        for (int i = 0; i < dim; ++i) {
            result += b[i] * v.b[i];
        }
        cout << "Multiplication of vectors #" << num << " and #" << v.num << " = " << endl;
        return result;
    }

    vect operator*(double k) const {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] * k;
        }
        cout << "Multiplication of vector #" << num << " and number " << k << " = " << endl;
        return result;
    }

    bool operator==(const vect &v) const {
        for (int i = 0; i < dim; ++i) {
            if (abs(b[i] - v.b[i]) > 1e-9) {
                return false;
            }
        }
        cout << "Comparing vectors #" << num << " and #" << v.num << " = " << endl;
        return true;
    }
    void print() const {
        for (int i = 0; i < dim; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
};

int vect::count = 0;

class matr {
public:
    static int count;
    int dim;
    vector<vector<double>> a;
    int num;

    explicit matr(int dimension) : dim(dimension), a(dimension, vector<double>(dimension)) {
        num = ++count;
        cout << "Matrix #" << num << " created " << endl;
    }

    ~matr() {
        cout << "Matrix #" << num <<" deleted" <<  endl;
    }

    matr operator+(const matr &m) const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        cout << "Sum of matrix #" << num << " and #" << m.num << " = " << endl;
        return result;
    }

    matr operator-(const matr &m) const {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = a[i][j] - m.a[i][j];
            }
        }
        cout << "Substraction of matrix #" << num << " and #" << m.num << " = " << endl;
        return result;
    }
    void print() const {
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int matr::count = 0;

int main() {
    // Создаем векторы
    vect v1(3);
    vect v2(3);

    // Заполняем векторы значениями
    v1.b[0] = 1;
    v1.b[1] = 2;
    v1.b[2] = 3;

    v2.b[0] = 4;
    v2.b[1] = 5;
    v2.b[2] = 6;

    // Складываем векторы
    vect sum = v1 + v2;
    sum.print();

    // Вычитаем векторы
    vect sub = v1 - v2;
    sub.print();

    // Создаем матрицы
    matr m1(2);
    matr m2(2);

    // Заполняем матрицы значениями
    m1.a[0][0] = 1;
    m1.a[0][1] = 2;
    m1.a[1][0] = 3;
    m1.a[1][1] = 4;

    m2.a[0][0] = 5;
    m2.a[0][1] = 6;
    m2.a[1][0] = 7;
    m2.a[1][1] = 8;

    // Складываем матрицы
    matr sum_matr = m1 + m2;
    sum_matr.print();

    return 0;
}
