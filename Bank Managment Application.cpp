#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Bank Account Class
class BankAccount {
private:
    int accountNumber;
    string name;
    float balance;

public:

    // Create Account
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        saveToFile();

        cout << "\nAccount Created Successfully!\n";
    }

    // Save Account Data
    void saveToFile() {
        ofstream file("bank.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    // Deposit Money
    void deposit() {
        int acc;
        float amount;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> acc;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        ifstream inFile("bank.txt");
        ofstream outFile("temp.txt");

        int accNo;
        string custName;
        float bal;

        while (inFile >> accNo) {

            inFile.ignore();
            getline(inFile, custName);
            inFile >> bal;

            if (accNo == acc) {
                bal += amount;
                found = true;

                cout << "\nAmount Deposited Successfully!\n";
                cout << "Updated Balance: " << bal << endl;
            }

            outFile << accNo << endl;
            outFile << custName << endl;
            outFile << bal << endl;
        }

        inFile.close();
        outFile.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (!found) {
            cout << "Account Not Found.\n";
        }
    }

    // Withdraw Money
    void withdraw() {
        int acc;
        float amount;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> acc;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        ifstream inFile("bank.txt");
        ofstream outFile("temp.txt");

        int accNo;
        string custName;
        float bal;

        while (inFile >> accNo) {

            inFile.ignore();
            getline(inFile, custName);
            inFile >> bal;

            if (accNo == acc) {

                if (amount > bal) {
                    cout << "\nInsufficient Balance.\n";
                } else {
                    bal -= amount;

                    cout << "\nWithdrawal Successful!\n";
                    cout << "Remaining Balance: " << bal << endl;
                }

                found = true;
            }

            outFile << accNo << endl;
            outFile << custName << endl;
            outFile << bal << endl;
        }

        inFile.close();
        outFile.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (!found) {
            cout << "Account Not Found.\n";
        }
    }

    // Balance Check
    void checkBalance() {
        int acc;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> acc;

        ifstream file("bank.txt");

        int accNo;
        string custName;
        float bal;

        while (file >> accNo) {

            file.ignore();
            getline(file, custName);
            file >> bal;

            if (accNo == acc) {

                cout << "\n===== ACCOUNT DETAILS =====\n";
                cout << "Account Number : " << accNo << endl;
                cout << "Customer Name  : " << custName << endl;
                cout << "Balance        : " << bal << endl;

                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "Account Not Found.\n";
        }
    }
};

// Main Function
int main() {

    BankAccount bank;
    int choice;

    do {

        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "0. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bank.createAccount();
            break;

        case 2:
            bank.deposit();
            break;

        case 3:
            bank.withdraw();
            break;

        case 4:
            bank.checkBalance();
            break;

        case 0:
            cout << "\nThank You for Using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}
