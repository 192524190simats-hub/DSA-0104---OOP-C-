#include <iostream>
using namespace std;

// Returns reference to the highest mark
int& highestMark(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Returns a copy of the highest mark
int highestMarkCopy(int marks[], int size)
{
    int max = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
        }
    }

    return max;
}

// Returns a const reference
const int& highestMarkConst(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

int main()
{
    int marks[5] = {75, 89, 92, 80, 85};

    cout << "Highest Mark: " << highestMark(marks, 5) << endl;

    highestMark(marks, 5) += 2;

    cout << "After Moderation: "
         << highestMark(marks, 5) << endl;

    cout << "Returned Copy: "
         << highestMarkCopy(marks, 5) << endl;

    cout << "Const Reference: "
         << highestMarkConst(marks, 5) << endl;

    return 0;
}
