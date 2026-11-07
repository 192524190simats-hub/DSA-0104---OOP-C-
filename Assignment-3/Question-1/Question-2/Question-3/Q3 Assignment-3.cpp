#include <iostream>
using namespace std;

class Auditorium {
    int rows, seats;
    char** seatMap;
    int booked;

public:

    // Dynamic constructor
    Auditorium(int r, int s)
        : rows(r), seats(s), booked(0), seatMap(nullptr) {

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }

        cout << "Event created\n";
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'O') {

            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked\n";
        }
        else {
            cout << "Invalid or unavailable seat\n";
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'X') {

            seatMap[r][s] = 'O';
            booked--;
            cout << "Seat cancelled\n";
        }
        else {
            cout << "Seat not booked\n";
        }
    }

    // Display seat map
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++)
                cout << seatMap[i][j] << " ";

            cout << endl;
        }
    }

    // Destructor
    ~Auditorium() {

        for (int i = 0; i < rows; i++)
            delete[] seatMap[i];

        delete[] seatMap;

        cout << "Event closed. Total booked seats: "
             << booked << endl;
    }
};

int main() {

    // Stack object
    Auditorium a(2, 3);

    a.bookSeat(0, 1);
    a.bookSeat(1, 2);
    a.cancelSeat(0, 1);

    a.display();

    // Heap object
    Auditorium* b = new Auditorium(2, 2);
    b->bookSeat(0, 0);
    delete b;

    // Block scope object
    {
        Auditorium c(1, 2);
        c.bookSeat(0, 1);
    }

    return 0;
}
