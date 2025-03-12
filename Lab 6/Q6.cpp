#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNumber;

public:
    void setStudentDetails(string n, int r) {
        name = n;
        rollNumber = r;
    }

    void displayStudentDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Marks : public Student {
protected:
    int marks[3];

public:
    void setMarks(int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void displayMarks() {
        cout << "Maths Marks: " << marks[0] << endl;
        cout << "English Marks: " << marks[1] << endl;
        cout << "Science Marks: " << marks[2] << endl;
    }

    int* getMarks() {
        return marks;
    }
};

class Result : public Marks {
public:
    int getTotalMarks() {
        return marks[0] + marks[1] + marks[2];
    }

    void displayResult() {
        int total = getTotalMarks();
        float average = total / 3.0;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    Result studentResult;
    studentResult.setStudentDetails("Zain Khan", 838);
    studentResult.setMarks(85, 90, 78);

    cout << "--- Student Details ---" << endl;
    studentResult.displayStudentDetails();

    cout << "\n--- Marks Obtained ---" << endl;
    studentResult.displayMarks();

    cout << "\n--- Result ---" << endl;
    studentResult.displayResult();

    return 0;
}

