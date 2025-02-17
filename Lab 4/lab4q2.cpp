#include<iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            balance = 0;
            cout<< "Initial balance was invalid. Set to 0." <<endl;
        }
    }
    void credit(double amount) {
        balance += amount;
    }
    void debit(double amount) {
        if (amount > balance)
            cout<<"Debit amount exceeded account balance." <<endl;
        else
            balance -= amount;
    }
    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc(2000.0);
    cout<< "Initial Balance: " << acc.getBalance() <<endl;
    
    acc.credit(1200.0);
    cout<< "Balance after credit: " << acc.getBalance() <<endl;
    
    acc.debit(300.0);
    cout<< "Balance after debit: " << acc.getBalance() <<endl;
    
    acc.debit(150.0);
    cout<< "Final Balance: " << acc.getBalance() <<endl;
}
