#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Constructor with real part
    Complex(double r) : real(r), imag(0) {}

    // Constructor with real and imaginary parts
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw runtime_error("Division by zero impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Display
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        // R = 10 ohms, XL = 20 ohms, XC = 10 ohms
        Complex R(10);
        Complex L(0, 20);
        Complex C(0, -10);

        // Series RLC impedance
        Complex series = R + L + C;

        cout << "Series Impedance: " << series << endl;
        cout << "Series Magnitude: "
             << series.magnitude() << endl;

        // Parallel RLC impedance
        Complex parallel1 = (R * L) / (R + L);
        Complex parallel = (parallel1 * C) / (parallel1 + C);

        cout << "\nParallel Impedance: "
             << parallel << endl;

        cout << "Parallel Magnitude: "
             << parallel.magnitude() << endl;

        // Division by zero test
        Complex zero(0, 0);
        Complex result = R / zero;
    }
    catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
