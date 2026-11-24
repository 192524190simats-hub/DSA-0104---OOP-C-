
#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
#include <iomanip>
using namespace std;
using namespace chrono;

// B3.2 Virtual Function vs Switch

class Base {
public:
    virtual int calculate(int x) = 0;
    virtual ~Base() {}
};

class TypeA : public Base {
public:
    int calculate(int x) override {
        return x + 1;
    }
};

class TypeB : public Base {
public:
    int calculate(int x) override {
        return x * 2;
    }
};

int switchCalculate(int type, int x) {
    switch (type) {
        case 0: return x + 1;
        case 1: return x * 2;
        default: return x;
    }
}

double virtualTest(int n) {
    TypeA a;
    TypeB b;

    Base* objects[2] = {&a, &b};

    long long sum = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        sum += objects[i % 2]->calculate(i);
    }

    auto end = high_resolution_clock::now();

    if (sum == -1) cout << sum;

    return duration<double, milli>(end - start).count();
}

double switchTest(int n) {
    long long sum = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        sum += switchCalculate(i % 2, i);
    }

    auto end = high_resolution_clock::now();

    if (sum == -1) cout << sum;

    return duration<double, milli>(end - start).count();
}

// B3.3 Return Codes vs Exceptions

int validateReturn(int i, int invalidPercent) {
    if (i % 100 < invalidPercent)
        return -1;

    return 0;
}

int validateException(int i, int invalidPercent) {
    if (i % 100 < invalidPercent)
        throw runtime_error("Invalid claim");

    return 0;
}

double returnCodeTest(int n, int invalidPercent) {
    int errors = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        if (validateReturn(i, invalidPercent) != 0)
            errors++;
    }

    auto end = high_resolution_clock::now();

    if (errors == -1) cout << errors;

    return duration<double, milli>(end - start).count();
}

double exceptionTest(int n, int invalidPercent) {
    int errors = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        try {
            validateException(i, invalidPercent);
        }
        catch (const exception&) {
            errors++;
        }
    }

    auto end = high_resolution_clock::now();

    if (errors == -1) cout << errors;

    return duration<double, milli>(end - start).count();
}

int main() {
    cout << fixed << setprecision(3);

    // B3.2
    cout << "B3.2 Virtual function vs switch (compile with -O2)" << endl;
    cout << "Bills,Virtual_ms,Switch_ms" << endl;

    int sizes[] = {1000, 1000000, 100000000};

    for (int n : sizes) {
        double v = virtualTest(n);
        double s = switchTest(n);

        cout << n << "," << v << "," << s << endl;
    }

    cout << endl;

    // B3.3
    cout << "B3.3 Return codes vs exceptions for 1,000,000 claims" << endl;
    cout << "Invalid%,ReturnCodes_ms,Exceptions_ms" << endl;

    int percentages[] = {0, 1, 50};

    for (int p : percentages) {
        double r = returnCodeTest(1000000, p);
        double e = exceptionTest(1000000, p);

        cout << p << "," << r << "," << e << endl;
    }

    cout << endl;
    cout << "--------------------------------" << endl;

    return 0;
}

