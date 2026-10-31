#include <iostream>
using namespace std;

class SavingsAccount
{
private:

    int accountNumber;
    double balance;

    static const int SIZE = 10;

    double transactions[SIZE];

    int count;
    int start;

public:

    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
        start = 0;
    }

    void addTransaction(double amount)
    {
        int index;

        if (count < SIZE)
        {
            index = (start + count) % SIZE;
            count++;
        }
        else
        {
            index = start;
            start = (start + 1) % SIZE;
        }

        transactions[index] = amount;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit\n";
            return;
        }

        balance += amount;

        addTransaction(amount);
    }

    void withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
        {
            cout << "Invalid withdrawal\n";
            return;
        }

        balance -= amount;

        addTransaction(-amount);
    }

    void miniStatement()
    {
        cout << "\nMini Statement\n";

        cout << "Account Number: "
             << accountNumber << endl;

        cout << "Recent Transactions:\n";

        for (int i = 0; i < count; i++)
        {
            int index = (start + i) % SIZE;

            if (transactions[index] > 0)
            {
                cout << "Deposit: "
                     << transactions[index] << endl;
            }
            else
            {
                cout << "Withdrawal: "
                     << -transactions[index] << endl;
            }
        }

        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    SavingsAccount account(101, 5000);

    for (int i = 1; i <= 12; i++)
    {
        account.deposit(i * 100);
    }

    account.miniStatement();

    return 0;
}
