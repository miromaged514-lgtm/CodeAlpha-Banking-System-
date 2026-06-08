#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

class BankAccount
{
private:
    string customerName;
    int accountNumber;
    double balance;
    vector<string> history;
    bool isCreated = false;

public:

    BankAccount()
    {
        balance = 0;
        accountNumber = 0;
    }

    void createAccount()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        isCreated = true;
        history.push_back("Account Created");

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit()
    {
        if (!isCreated)
        {
            cout << "Please create account first!\n";
            return;
        }

        double amount;
        cout << "Enter Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid Amount!\n";
            return;
        }

        balance += amount;

        stringstream ss;
        ss << "Deposited: " << amount;
        history.push_back(ss.str());

        cout << "Deposit Successful!\n";
    }

    void withdraw()
    {
        if (!isCreated)
        {
            cout << "Please create account first!\n";
            return;
        }

        double amount;
        cout << "Enter Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid Amount!\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;

        stringstream ss;
        ss << "Withdrawn: " << amount;
        history.push_back(ss.str());

        cout << "Withdrawal Successful!\n";
    }

    void checkBalance()
    {
        if (!isCreated)
        {
            cout << "Please create account first!\n";
            return;
        }

        cout << "\nCurrent Balance: " << balance << endl;
    }

    void accountDetails()
    {
        if (!isCreated)
        {
            cout << "Please create account first!\n";
            return;
        }

        cout << "\nCustomer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void showHistory()
    {
        if (!isCreated)
        {
            cout << "Please create account first!\n";
            return;
        }

        cout << "\n===== Transaction History =====\n";

        if (history.empty())
        {
            cout << "No Transactions Found.\n";
            return;
        }

        for (int i = 0; i < history.size(); i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
};

int main()
{
    BankAccount account;
    int choice;

    do
    {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Account Details\n";
        cout << "6. Transaction History\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: account.createAccount(); break;
        case 2: account.deposit(); break;
        case 3: account.withdraw(); break;
        case 4: account.checkBalance(); break;
        case 5: account.accountDetails(); break;
        case 6: account.showHistory(); break;
        case 7: cout << "\nThank You!\n"; break;
        default: cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
