#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    string name;
};
struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    int N, subjectCount;
    cout << "Enter the number of students: ";
    cin >> N;
    
    cout << "Enter the number of subjects per student: ";
    cin >> subjectCount;
    
    vector<Student> students(N);
    
    for (int i = 0; i < N; i++) {
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> students[i].id;
        
        students[i].subjects.resize(subjectCount);
        for (int j = 0; j < subjectCount; j++) {
            cout << "Enter subject " << j + 1 << " for student " << i + 1 << ": ";
            cin >> students[i].subjects[j].name;
        }
    }

    cout << "\nStudent Information:" << endl;
    for (const auto &student : students) {
        cout << "ID: " << student.id << "\nSubjects: ";
        for (const auto &subject : student.subjects) {
            cout << subject.name << " ";
        }
        cout << "\n";
    }
}
