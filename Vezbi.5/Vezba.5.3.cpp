#include <iostream>
#include <cmath>

using namespace std;

// Definirame pointers za 4te operacii
typedef int (*IntOperation)(int, int);
typedef float (*FloatOperation)(int, int);
typedef double (*DoubleOperation)(int, int);

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

float divide(int a, int b) {
    return static_cast<float>(a) / static_cast<float>(b);
}

double exponentiation(int a, int b) {
    return pow(static_cast<double>(a), static_cast<double>(b));
}

void calculate(int a, int b, void* operation, void* result) {
    if (operation == &add) {
        IntOperation op = reinterpret_cast<IntOperation>(operation);
        int* res = reinterpret_cast<int*>(result);
        *res = op(a, b);
    }
    else if (operation == &substract) {
        IntOperation op = reinterpret_cast<IntOperation>(operation);
        int* res = reinterpret_cast<int*>(result);
        *res = op(a, b);
    }
    else if (operation == &divide) {
        FloatOperation op = reinterpret_cast<FloatOperation>(operation);
        float* res = reinterpret_cast<float*>(result);
        *res = op(a, b);
    }
    else if (operation == &exponentiation) {
        DoubleOperation op = reinterpret_cast<DoubleOperation>(operation);
        double* res = reinterpret_cast<double*>(result);
        *res = op(a, b);
    }
}

int main() {
    const int x = 'M';
    const int y = 'P';
    int a = x, b = y;
    void* op1;
    void* op2;
    void* op3;
    int sum;
    int diff;
    float quotient;
    double power;

    IntOperation intOp1 = &add;
    IntOperation intOp2 = &substract;
    FloatOperation floatOp = &divide;
    DoubleOperation doubleOp = &exponentiation;

    op1 = reinterpret_cast<void*>(intOp1);
    op2 = reinterpret_cast<void*>(intOp2);
    op3 = reinterpret_cast<void*>(floatOp);

    calculate(a, b, op1, &sum);
    calculate(a, b, op2, &diff);
    calculate(a, b, op3, &quotient);
    power = exponentiation(a, b);

    cout << "a = " << a << ", b = " << b << endl;
    cout << "sum = " << sum << endl;
    cout << "diff = " << diff << endl;
    cout << "quotient = " << quotient << endl;
    cout << "power = " << power << endl;

    return 0;
}
//Marijana Pejchinovska
