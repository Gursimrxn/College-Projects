#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class ATM {
private:
    vector<pair<int, int>> Credentials; // Store user credentials
    vector<pair<int, double>> Balances;  // Store user balances

    void printIntroMenu() {
        char choice;
        cout << "Please select an option from below: " << endl << endl;
        cout << "l -> Login" << endl
             << "c -> Create New Account" << endl
             << "q -> Quit" << endl;
        cin >> choice;
        switch (choice) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                cout << "Thanks for stopping by!";
                exit(0);
            default:
                cout << "Invalid Choice!" << endl << endl;
                printIntroMenu();
                break;
        }
    }

    void deposit(int userId) {
        double amount;
        cout << "Enter Amount of Deposit: ";
        cin >> amount;

        // Update the balance for the given user ID
        for (auto& balance : Balances) {
            if (balance.first == userId) {
                balance.second += amount;
                cout << "Deposit Successful" << endl << endl;
                printMainMenu(userId);
                return;
            }
        }
        cout << "User not found!" << endl << endl;
        printMainMenu(userId);
    }

    void withdraw(int userId) {
        double amount;
        cout << "Enter Amount of Withdrawal: ";
        cin >> amount;

        // Update the balance for the given user ID
        for (auto& balance : Balances) {
            if (balance.first == userId) {
                if (balance.second >= amount) {
                    balance.second -= amount;
                    cout << "Withdrawal Successful" << endl << endl;
                } else {
                    cout << "Insufficient balance!" << endl << endl;
                }
                printMainMenu(userId);
                return;
            }
        }
        cout << "User not found!" << endl << endl;
        printMainMenu(userId);
    }

    void requestBal(int userId) {
        // Display the balance for the given user ID
        for (const auto& balance : Balances) {
            if (balance.first == userId) {
                cout << "Your balance is " << balance.second << "$." << endl << endl;
                printMainMenu(userId);
                return;
            }
        }
        cout << "User not found!" << endl << endl;
        printMainMenu(userId);
    }

    void printMainMenu(int userId) {
        char choice;
        cout << "d -> Deposit Money" << endl
             << "w -> Withdraw Money" << endl
             << "r -> Request Balance" << endl
             << "o -> LogOut" << endl;
        cin >> choice;
        switch (choice) {
            case 'd':
                deposit(userId);
                break;
            case 'w':
                withdraw(userId);
                break;
            case 'r':
                requestBal(userId);
                break;
            case 'o':
                cout << "You have been Logged Out!" << endl << endl;
                printIntroMenu();
                break;
            default:
                cout << "Invalid Choice!" << endl << endl;
                printMainMenu(userId);
                break;
        }
    }

    void login() {
        int tempId, tempPass;

        cout << "Please enter your user id: ";
        cin >> tempId;
        cout << "Please enter your password: ";
        cin >> tempPass;

        // Check if entered credentials exist in the vector
        for (const auto& credential : Credentials) {
            if (credential.first == tempId && credential.second == tempPass) {
                cout << endl << "Access Granted!" << endl << endl;
                printMainMenu(tempId);
                return;
            }
        }
        cout << endl << "******** LOGIN FAILED! ********" << endl << endl;
        printIntroMenu();
    }

    void createAccount() {
        int id, pass;
        cout << "Please enter Username: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> pass;
        bool newUser = true;
        for(auto& cred : Credentials){
            if(cred.first == id){
                cout << "User Already Exists!" << endl;
                newUser = false;
            }
        }
        if(newUser){
            Credentials.push_back({id, pass});
            Balances.push_back({id, 0.0});
            cout << endl << "Thank You! Your account has been created!" << endl << endl;
            
        }
        printIntroMenu();
    }

public:
    void start() {
        cout << "Welcome to Gursimran Singh's ATM." << endl << endl;
        printIntroMenu();
    }
};

int main() {
    ATM obj;
    obj.start();
    return 0;
}
