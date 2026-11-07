#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:

    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // TODO 1: Overload +
    Money operator+(const Money& m) const {
        return Money(0, paise + m.paise);
    }

    // Subtraction
    Money operator-(const Money& m) const {
        return Money(0, paise - m.paise);
    }

    // Addition assignment
    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    // TODO 2: Overload ==
    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    // Less than
    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    // Stream insertion
    friend ostream& operator<<(ostream& out, const Money& m) {
        out << "Rs " << m.paise / 100 << "."
            << setw(2) << setfill('0')
            << (m.paise >= 0 ? m.paise % 100 : -(m.paise % 100));

        return out;
    }

    // Stream extraction
    friend istream& operator>>(istream& in, Money& m) {
        long long r;
        int p;

        in >> r >> p;

        if (in)
            m.paise = r * 100 + p;

        return in;
    }
};

int main() {

    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    // Paise carry test
    Money x(0, 75);
    Money y(0, 50);

    cout << x + y << endl;

    return 0;
}
