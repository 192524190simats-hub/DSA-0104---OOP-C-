#include <iostream>
#include <string>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

// Weight in grams
double charge(int grams)
{
    cout << "Integer function selected: ";
    return grams * 0.05;
}

// Weight in kilograms
double charge(double kg,
              bool express = false,
              bool insured = false)
{
    cout << "Double function selected: ";

    double cost = kg * 50;

    if (express)
        cost += 30;

    if (insured)
        cost += 20;

    return cost;
}

// Parcel object
double charge(const Parcel& p)
{
    cout << "Parcel function selected: ";

    double cost = p.weight * 50;

    if (p.express)
        cost += 30;

    if (p.insured)
        cost += 20;

    return cost;
}

int main()
{
    cout << "Call 1: ";
    cout << charge(500) << endl;

    cout << "Call 2: ";
    cout << charge(2) << endl;

    cout << "Call 3: ";
    cout << charge(2.0) << endl;

    cout << "Call 4: ";
    cout << charge(2.0f) << endl;

    cout << "Call 5: ";
    cout << charge(2.0, true) << endl;

    Parcel p = {3.0, true, true};

    cout << "Call 6: ";
    cout << charge(p) << endl;

    return 0;
}
