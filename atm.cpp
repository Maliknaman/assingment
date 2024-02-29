#include <iostream>
#include <map>
#include <string>

using namespace std;

class Bank {
private:
    map<string, string> accounts;  
    map<string, double> balances; 

public:
    void createAccount(string userId, string password) {
        accounts[userId] = password;
        balances[userId] = 0.0;
        cout << "Thank You! Your account has been created!" << endl;
    }

    bool login(string userId, string password) {
        if (accounts.find(userId) != accounts.end() && accounts[userId] == password) {
            cout << "Access Granted!" << endl;
            return true;
        } else {
            cout << "******** LOGIN FAILED! ********" << endl;
            return false;
        }
    }

    void deposit(string userId, double amount) {
        balances[userId] += amount;
        cout << "Amount of deposit: $" << amount << endl;
    }

    void withdraw(string userId, double amount) {
        if (balances[userId] >= amount) {
            balances[userId] -= amount;
            cout << "Amount of withdrawal: $" << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void requestBalance(string userId) {
        cout << "Your balance is $" << balances[userId] << endl;
    }
};

void printIntroMenu();

void printMainMenu();

void start();

void login(Bank &bank);

void createAccount(Bank &bank);

void mainMenu(Bank &bank, string userId);

void deposit(Bank &bank, string userId);

void withdraw(Bank &bank, string userId);

void requestBalance(Bank &bank, string userId);

int main() {
    start();
    return 0;
}

void printIntroMenu() {
    cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu() {
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void start() {
    Bank bank;
    char choice;

    do {
        printIntroMenu();
        cin >> choice;

        switch (choice) {
            case 'l':
                login(bank);
                break;
            case 'c':
                createAccount(bank);
                break;
            case 'q':
                cout << "Thanks for stopping by!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 'q');
}

void login(Bank &bank) {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (bank.login(userId, password)) {
        mainMenu(bank, userId);
    }
}

void createAccount(Bank &bank) {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    bank.createAccount(userId, password);
}

void mainMenu(Bank &bank, string userId) {
    char choice;

    do {
        printMainMenu();
        cin >> choice;

        switch (choice) {
            case 'd':
                deposit(bank, userId);
                break;
            case 'w':
                withdraw(bank, userId);
                break;
            case 'r':
                requestBalance(bank, userId);
                break;
            case 'q':
                cout << "Thanks for stopping by!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 'q');
}

void deposit(Bank &bank, string userId) {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    bank.deposit(userId, amount);
}

void withdraw(Bank &bank, string userId) {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;
    bank.withdraw(userId, amount);
}

void requestBalance(Bank &bank, string userId) {
    bank.requestBalance(userId);
}
