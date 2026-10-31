#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

public:

    // Constructor
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
    }

    // Deposit function defined inside class
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount\n";
            return;
        }

        balance += amount;

        if (count == 10)
        {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            count--;
        }

        transactions[count++] = amount;

        cout << "Amount deposited: " << amount << endl;
    }

    // Function declaration
    void withdraw(double amount);

    void miniStatement();

    void displayBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }
};

// Function defined outside the class
void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal\n";
        return;
    }

    balance -= amount;

    if (count == 10)
    {
        for (int i = 0; i < 9; i++)
            transactions[i] = transactions[i + 1];

        count--;
    }

    transactions[count++] = -amount;

    cout << "Amount withdrawn: " << amount << endl;
}

// Mini statement function
void SavingsAccount::miniStatement()
{
    cout << "\nMini Statement\n";

    cout << "Account Number: "
         << accountNumber << endl;

    cout << "Last Transactions:\n";

    for (int i = 0; i < count; i++)
    {
        if (transactions[i] > 0)
            cout << "Deposit: " << transactions[i] << endl;
        else
            cout << "Withdrawal: "
                 << -transactions[i] << endl;
    }

    cout << "Balance: " << balance << endl;
}

int main()
{
    SavingsAccount account(101, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.displayBalance();

    account.miniStatement();

    return 0;
}
