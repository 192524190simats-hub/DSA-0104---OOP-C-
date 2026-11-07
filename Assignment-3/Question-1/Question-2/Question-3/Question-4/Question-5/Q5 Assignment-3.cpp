#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:

    Time(int h = 0, int m = 0, int s = 0)
        : hours(h), minutes(m), seconds(s) {}

    // Prefix increment
    Time& operator++() {
        seconds++;

        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }

        if (minutes == 60) {
            minutes = 0;
            hours++;
        }

        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    // Equality operator
    bool operator==(const Time& t) const {
        return hours == t.hours &&
               minutes == t.minutes &&
               seconds == t.seconds;
    }

    // Less than operator
    bool operator<(const Time& t) const {
        if (hours != t.hours)
            return hours < t.hours;

        if (minutes != t.minutes)
            return minutes < t.minutes;

        return seconds < t.seconds;
    }

    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

class Playlist {
    string tracks[5];
    int size;

public:

    Playlist() : tracks{"Song1", "Song2", "Song3",
                        "Song4", "Song5"}, size(5) {}

    // Non-constant subscript
    string& operator[](int i) {
        if (i < 0 || i >= size)
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }

    // Constant subscript
    const string& operator[](int i) const {
        if (i < 0 || i >= size)
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }
};

int main() {

    Time t(0, 0, 5);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "Current time = ";
    t.display();

    Playlist p;

    cout << "Playing: " << p[0] << endl;
    cout << "Playing: " << p[1] << endl;

    return 0;
}
