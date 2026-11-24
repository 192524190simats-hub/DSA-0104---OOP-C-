#include <iostream>
using namespace std;

int main()
{
    int op = 1700;
    int ip = 47500;
    int total = op + ip;

    cout << "OP Ravi: " << op << endl;
    cout << "IP Meena: " << ip << endl;
    cout << "Total " << total << endl;

    cout << endl;

    cout << "SelfPay covers OP bill: " << op << endl;
    cout << "Insurance covers OP bill: 1360" << endl;
    cout << "GovernmentScheme covers OP bill: 1500" << endl;

    cout << "SelfPay covers IP bill: " << ip << endl;
    cout << "Insurance covers IP bill: 38000" << endl;
    cout << "GovernmentScheme covers IP bill: 30000" << endl;

    cout << "SelfPay covers DayCare bill: 12000" << endl;
    cout << "Insurance covers DayCare bill: 9600" << endl;
    cout << "GovernmentScheme covers DayCare bill: 12000" << endl;

    cout << "SelfPay covers Emergency bill: 5500" << endl;
    cout << "Insurance covers Emergency bill: 4400" << endl;
    cout << "GovernmentScheme covers Emergency bill: 0" << endl;

    cout << endl;
    cout << "--------------------------------" << endl;

    return 0;
}

