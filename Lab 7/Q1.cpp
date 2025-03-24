#include <iostream>
using namespace std;

class Account {
protected:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    Account(string name, string number, double bal)
        : accountHolderName(name), accountNumber(number), balance(bal) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << accountHolderName << " deposited Rs. " << amount << ". New Balance: Rs. " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << accountHolderName << " withdrew Rs. " << amount << ". New Balance: Rs. " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation is account-specific." << endl;
    }

    virtual void printStatement() {
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }

    virtual void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string name, string number, double bal, double rate, double minBal)
        : Account(name, number, bal), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest of Rs. " << interest << " added. New Balance: Rs. " << balance << endl;
    }

    void withdraw(double amount) override {
        if ((balance - amount) >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw. Minimum balance requirement not met!" << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "Min. Balance   : Rs. " << minimumBalance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string name, string number, double bal)
        : Account(name, number, bal) {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Transaction successful! Rs. " << amount << " withdrawn. Remaining balance: Rs. " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Checking accounts have no interest benefits." << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(string name, string number, double bal, double rate, int maturity)
        : Account(name, number, bal), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed deposit interest: Rs. " << interest << " (Not added until maturity)" << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity!" << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Fixed Interest Rate : " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date       : " << maturityDate << " months" << endl;
    }
};

int main() {
    SavingsAccount sa("Zain", "SA123", 50000, 5.0, 2000);
    CheckingAccount ca("Ali", "CA456", 30000);
    FixedDepositAccount fda("Zaid", "FD789", 100000, 7.5, 12);

    cout << "\n=== Account Information ===" << endl;
    sa.getAccountInfo();
    cout << "-----------------------" << endl;
    ca.getAccountInfo();
    cout << "-----------------------" << endl;
    fda.getAccountInfo();

    cout << "\n=== Transactions ===" << endl;
    sa.deposit(5000);
    sa.withdraw(10000);
    sa.calculateInterest();
    cout << "-----------------------" << endl;

    ca.deposit(8000);
    ca.withdraw(15000);
    cout << "-----------------------" << endl;

    fda.calculateInterest();
    fda.withdraw(5000);

    return 0;
}

