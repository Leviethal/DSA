#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name = "", int number = 0, double initialBalance = 0.0)
    {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    void displayAccountDetails() const
    {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    double rich_guy()
    {
        return balance;
    }
    string rich_name()
    {
        return accountHolderName;
    }
};

int main()
{
    const int NUM_ACCOUNTS = 5;
    BankAccount accounts[NUM_ACCOUNTS];

    for (int i = 0; i < NUM_ACCOUNTS; i++)
    {
        string x;
        cin >> x;

        int accountNumber = 1000 + i;
        double initialBalance = 1000.0 + (i % 2 * 500);

        accounts[i] = BankAccount(x, accountNumber, initialBalance);
    }

    for (int i = 0; i < NUM_ACCOUNTS; i++)
    {
        cout << "Account " << i + 1 << " details:" << endl;
        accounts[i].displayAccountDetails();
        cout << endl;
    }

    cout << "Performing transactions on the first account:\n";
    accounts[0].deposit(500.0);
    accounts[0].withdraw(300.0);
    accounts[0].withdraw(1500.0);
    accounts[0].displayAccountDetails();

    double money[5];
    string name[5];
    for (int i = 0; i < 5; i++)
    {
        money[i] = accounts[i].rich_guy();
        name[i] = accounts[i].rich_name();
    }
    double max = 0;
    string rich = name[0];
    for (int i = 0; i < 5; i++)
    {
        if (money[i] > max)
        {
            max = money[i];
            rich = name[i];
        }
    }
    cout << rich;
    for (int i = 0; i < 5; i++)
        cout << money[i] << " ";
    return 0;
}
