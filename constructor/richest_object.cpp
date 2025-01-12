#include <iostream>
#include <string>
using namespace std;

// BankAccount class definition
class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    // Method to display account details
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    // Creating an object of the BankAccount class
    BankAccount account("John Doe", 123456, 1000.0);

    // Display initial account details
    account.displayAccountDetails();

    // Deposit money
    account.deposit(500.0);

    // Withdraw money
    account.withdraw(300.0);

    // Attempt to withdraw an invalid amount
    account.withdraw(1500.0);

    // Display final account details
    account.displayAccountDetails();

    return 0;
}
