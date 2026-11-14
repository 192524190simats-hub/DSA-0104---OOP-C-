#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person+ "; }
    ~Person() { cout << "Person- "; }
};

class Student : virtual public Person {
public:
    Student() { cout << "Student+ "; }
    ~Student() { cout << "Student- "; }
};

class Staff : virtual public Person {
public:
    Staff() { cout << "Staff+ "; }
    ~Staff() { cout << "Staff- "; }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant() { cout << "TA+ "; }
    ~TeachingAssistant() { cout << "TA- "; }
};

int main() {
    {
        Student s;
        cout << endl;
        Staff f;
        cout << endl;
        TeachingAssistant t;
        cout << endl;
    }
}
