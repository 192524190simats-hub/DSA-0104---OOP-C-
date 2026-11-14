#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented = false;

public:
    Vehicle(string r, double d)
        : regNo(r), dailyRate(d) {}

    virtual double charge(int days) const = 0;

    virtual void display() const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            cout << regNo << " rented successfully\n";
        } else {
            cout << "Already rented\n";
        }
    }

    void returnVehicle(int days, int lateDays) {
        if (rented) {
            double amount = charge(days) + lateDays * 100;

            cout << regNo << " returned. Total: "
                 << amount << endl;

            rented = false;
        }
    }

    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double d) : Vehicle(r, d) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Bicycle: " << regNo << endl;
    }
};

class TwoWheeler : public Vehicle {
    double fuelLevel;
    string serviceDate;

public:
    TwoWheeler(string r, double d, double f, string s)
        : Vehicle(r, d), fuelLevel(f), serviceDate(s) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "TwoWheeler: " << regNo << endl;
    }
};

class Car : public Vehicle {
    int seats;

public:
    Car(string r, double d, int s)
        : Vehicle(r, d), seats(s) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Car: " << regNo << endl;
    }
};

class ElectricCar : public Vehicle {
    double batteryCapacity;

public:
    ElectricCar(string r, double d, double b)
        : Vehicle(r, d), batteryCapacity(b) {}

    double charge(int days) const override {
        return dailyRate * days +
               batteryCapacity * 0.5;
    }

    void display() const override {
        cout << "Electric Car: " << regNo << endl;
    }
};

int main() {
    Vehicle* fleet[4];

    fleet[0] = new Bicycle("BIKE101", 100);
    fleet[1] = new TwoWheeler("TW102", 200, 5, "2027-01-01");
    fleet[2] = new Car("CAR103", 1000, 5);
    fleet[3] = new ElectricCar("EV104", 1500, 60);

    for (int i = 0; i < 4; i++) {
        fleet[i]->display();
        fleet[i]->rent();
        fleet[i]->returnVehicle(2, 1);
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
        delete fleet[i];

    return 0;
}
