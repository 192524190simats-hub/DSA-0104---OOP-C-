#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title;
    string author;
    int copies;

public:

    // Default constructor
    Book() : Book("Unknown", "Unknown", 0) {}

    // Constructor with title only
    Book(string t) : Book(t, "Unknown", 0) {}

    // Parameterized constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(c) {

        if (c < 0)
            throw invalid_argument("Copies cannot be negative");
    }

    void display() {
        cout << "Title: " << title
             << ", Author: " << author
             << ", Copies: " << copies << endl;
    }
};

int main() {

    Book b1;
    Book b2("C++ Programming");
    Book b3("Python", "Guido", 10);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}
