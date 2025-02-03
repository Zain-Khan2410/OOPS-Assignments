#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int id;
    string name;
};

bool compareById(const Person &a, const Person &b) {
    return a.id < b.id;
}

bool compareByName(const Person &a, const Person &b) {
    return a.name[0] < b.name[0];
}

int main() {
    int N;
    cout << "Enter the number of structures: ";
    cin >> N;

    vector<Person> persons(N);

    for (int i = 0; i < N; i++) {
        cout << "Enter ID and Name for person " << i + 1 << ": ";
        cin >> persons[i].id >> persons[i].name;
    }

    sort(persons.begin(), persons.end(), compareById);
    cout << "\nSorted by ID:" << endl;
    for (const auto &p : persons) {
        cout << "ID: " << p.id << ", Name: " << p.name << endl;
    }

    sort(persons.begin(), persons.end(), compareByName);
    cout << "\nSorted by first character of Name:" << endl;
    for (const auto &p : persons) {
        cout << "ID: " << p.id << ", Name: " << p.name << endl;
    }
    
    return 0;
}
