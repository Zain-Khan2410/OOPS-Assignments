#include <iostream>
using namespace std;

class Person {
protected:
    int EmployeeID;

public:

    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> EmployeeID;
    }

    virtual void displayData() {
        cout << "Employee ID: " << EmployeeID << endl;
    }

    virtual ~Person() {}
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() override {
        Person::getData();  
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }

    double bonus() {
        return monthlyIncome * 0.05 * 12; 
    }
};

class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }

    double bonus() {
        return monthlyIncome * 0.05 * 12;
    }
};

int main() {
    Admin admin;
    Accounts accounts;

    cout << "\nEnter details for Admin Employee:\n";
    admin.getData();

    cout << "\nEnter details for Accounts Employee:\n";
    accounts.getData();

    cout << "\nDisplaying Employee Information:\n";
    cout << "\nAdmin Employee Details:\n";
    admin.displayData();

    cout << "\nAccounts Employee Details:\n";
    accounts.displayData();

    return 0;
}
