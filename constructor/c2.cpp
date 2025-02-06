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

        if (accounts[i].getBalance() > maxBalance) {
            maxBalance = accounts[i].getBalance();
            richestPerson = accounts[i].getName();
        }
    }
    cout << richestPerson << endl;

    return 0;
}
