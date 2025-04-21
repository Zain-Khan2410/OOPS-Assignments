#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    float salary;
public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }

    virtual void displayData() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    virtual void bonus() {
        cout << "Bonus: " << (0.1 * salary) << endl;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "Enter Admin details:" << endl;
        Person::getData();
    }

    void displayData() override {
        cout << "Admin - ";
        Person::displayData();
    }

    void bonus() override {
        cout << "Admin Bonus: " << (0.15 * salary) << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        cout << "Enter Account details:" << endl;
        Person::getData();
    }

    void displayData() override {
        cout << "Account - ";
        Person::displayData();
    }

    void bonus() override {
        cout << "Account Bonus: " << (0.12 * salary) << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "Enter Master (Admin + Account) details:" << endl;
        Person::getData();
    }

    void displayData() override {
        cout << "Master - ";
        Person::displayData();
    }

    void bonus() override {
        cout << "Master Bonus: " << (0.2 * salary) << endl;
    }
};

int main() {
    Person* ptr;

    Admin a;
    ptr = &a;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << endl;

    Account acc;
    ptr = &acc;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << endl;

    Master m;
    ptr = &m;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    return 0;
}

