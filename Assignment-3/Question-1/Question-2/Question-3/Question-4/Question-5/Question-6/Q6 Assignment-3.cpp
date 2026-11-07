#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    static int copies;

    // Constructor
    Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // Copy constructor (deep copy)
    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
        copies++;
    }

    // Copy assignment operator
    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);

            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    // Concatenation operator
    Text operator+(const Text& t) const {
        Text result;
        delete[] result.data;

        result.data = new char[strlen(data) + strlen(t.data) + 1];

        strcpy(result.data, data);
        strcat(result.data, t.data);

        return result;
    }

    // Equality operator
    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    // Not equal operator
    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }
};

int Text::copies = 0;

int main() {
    Text a("Hello ");
    Text b("World");
    Text c("!");

    // Concatenation
    Text message = a + b + c;

    cout << "Message: " << message << endl;

    // Comparison
    Text x("Hello");
    Text y("Hello");

    cout << "Equal: " << boolalpha << (x == y) << endl;
    cout << "Not Equal: " << (x != y) << endl;

    // Assignment
    Text d;
    d = a;

    cout << "Assigned Message: " << d << endl;

    // Self-assignment
    d = d;

    cout << "After Self Assignment: " << d << endl;

    // Empty message
    Text empty("");
    cout << "Empty Message: [" << empty << "]" << endl;

    // Copy count
    cout << "Copies made: " << Text::copies << endl;

    return 0;
}
