#include <iostream>
#include <string>
using namespace std;


class Wallet {
private:
    float balance;
    float dailyDepositTotal;
    float dailyWithdrawTotal;

    const float MAX_DAILY_DEPOSIT = 10000.0;
    const float MAX_DAILY_WITHDRAW = 5000.0;

public:
    Wallet() {
        balance = 0;
        dailyDepositTotal = 0;
        dailyWithdrawTotal = 0;
    }

    bool deposit(float amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return false;
        }
        if (dailyDepositTotal + amount > MAX_DAILY_DEPOSIT) {
            cout << "Deposit limit exceeded for the day.\n";
            return false;
        }
        balance += amount;
        dailyDepositTotal += amount;
        cout << "Deposit successful. New balance: " << balance << "\n";
        return true;
    }

    bool withdraw(float amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return false;
        }
        if (dailyWithdrawTotal + amount > MAX_DAILY_WITHDRAW) {
            cout << "Withdrawal limit exceeded for the day.\n";
            return false;
        }
        balance -= amount;
        dailyWithdrawTotal += amount;
        cout << "Withdrawal successful. New balance: " << balance << "\n";
        return true;
    }

    float getBalance() const {
        return balance;
    }
};


class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string userName) {
        userID = id;
        name = userName;
    }

    void deposit(float amount) {
        cout << name << " depositing " << amount << "...\n";
        wallet.deposit(amount);
    }

    void withdraw(float amount) {
        cout << name << " withdrawing " << amount << "...\n";
        wallet.withdraw(amount);
    }

    void checkBalance() {
        cout << name << "'s Current Balance: " << wallet.getBalance() << "\n";
    }
};

int main() {
    User user1("U101", "Zain");
    User user2("U102", "Uzair");

    user1.deposit(3000);   
    user1.deposit(8000);   
    user1.withdraw(1000);  
    user1.withdraw(6000);  
    user1.checkBalance();  

    cout << "\n";

    user2.deposit(5000);   
    user2.withdraw(2000);  
    user2.withdraw(4000);  
    user2.checkBalance();  

    return 0;
}
