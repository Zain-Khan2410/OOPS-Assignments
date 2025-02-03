#include <iostream>
#include <cstring>

using namespace std;

struct Employee {
    int employee_id;
    char name[50];
    float salary;
};

struct Organization {
    char organisation_name[50];
    char organisation_number[20];
    Employee emp;
};

int main() {
    Organization org;

    strcpy(org.organisation_name, "NU-Fast");
    strcpy(org.organisation_number, "NUFAST123ABC");

    org.emp.employee_id = 127;
    strcpy(org.emp.name, "Linus Sebastian");
    org.emp.salary = 400000;

    cout << "The size of structure organization: " << sizeof(org) << endl;
    cout << "Organisation Name: " << org.organisation_name << endl;
    cout << "Organisation Number: " << org.organisation_number << endl;
    cout << "Employee id: " << org.emp.employee_id << endl;
    cout << "Employee name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}
