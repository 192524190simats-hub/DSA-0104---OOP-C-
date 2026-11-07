#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    Prescription(int count) {
        n = count;
        medicines = new string[n];
    }

    void set(int i, string m) {
        medicines[i] = m;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << medicines[i] << " ";
        cout << endl;
    }

    ~Prescription() {
        delete[] medicines;
    }
};

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;  // Shallow copy

    q.set(1, "Cetirizine");

    p.display();
    q.display();

    return 0;
}
