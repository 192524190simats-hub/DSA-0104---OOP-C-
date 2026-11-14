#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    // TODO 1: Add item and return *this
    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    // TODO 2: Set discount using this pointer
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; i++) {
            t += prices[i];
        }

        return t * (100 - discount) / 100;
    }
};

int main() {

    // 1. Direct access using object name
    Cart c1;
    c1.add("Rice", 60).add("Dal", 120);
    cout << "Direct access: " << c1.total() << endl;

    // 2. Access using pointer
    Cart* p1 = &c1;
    p1->add("Oil", 180);
    cout << "Pointer access: " << p1->total() << endl;

    // 3. Access using reference
    Cart& r1 = c1;
    r1.setDiscount(10);
    cout << "Reference access: " << r1.total() << endl;

    // 4. Dynamic object using new and delete
    Cart* p2 = new Cart;
    p2->add("Sugar", 100).add("Wheat", 200);
    cout << "Dynamic object: " << p2->total() << endl;

    // Array of pointers to Cart objects
    Cart c2, c3;

    c2.add("Milk", 150).add("Bread", 100);
    c3.add("Fruits", 200).add("Vegetables", 250);

    Cart* carts[3] = { &c1, &c2, &c3 };

    // Find cart with highest total
    int highest = 0;

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > carts[highest]->total()) {
            highest = i;
        }
    }

    cout << "Highest cart total: "
         << carts[highest]->total() << endl;

    delete p2;

    return 0;
}
