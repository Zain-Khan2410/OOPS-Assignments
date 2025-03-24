#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int id;
    string address;
    string cellno;
    string email;

public:
    Person(string n, int i, string add, string phoneno, string mail)
        : name(n), id(i), address(add), cellno(phoneno), email(mail) {}

    string getname() { return name; }
    int getid() { return id; }
    string getaddress() { return address; }
    string getcellno() { return cellno; }
    string getemail() { return email; }

    virtual void displayinfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone Number: " << cellno << endl;
        cout << "Email: " << email << endl;
    }

    void updateinfo(string newAddress, string newPhone, string newEmail) {
        address = newAddress;
        cellno = newPhone;
        email = newEmail;
    }
};

class Student : public Person {
private:
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int i, string add, string phoneno, string mail, string enrolled, double g, int year)
        : Person(n, i, add, phoneno, mail), coursesEnrolled(enrolled), GPA(g), enrollmentYear(year) {}

    void displayinfo() override {
        Person::displayinfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, int i, string add, string phoneno, string mail, string dept, string courses, double sal)
        : Person(n, i, add, phoneno, mail), department(dept), coursesTaught(courses), salary(sal) {}

    void displayinfo() override {
        Person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, int i, string add, string phoneno, string mail, string dept, string pos, double sal)
        : Person(n, i, add, phoneno, mail), department(dept), position(pos), salary(sal) {}

    void displayinfo() override {
        Person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course {
private:
    int courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(int id, string name, int credit, string prof, string sched)
        : courseId(id), courseName(name), credits(credit), instructor(prof), schedule(sched) {}

    void registerStudent(Student s) {
        cout << "Student " << s.getname() << " has been registered for " << courseName << endl;
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main() {
    Student s1("Zain", 838, "North Nazimabad,Karachi", "03211234567", "zain@gmail.com", "OOP, DSA", 3.5, 2023);
    Professor p1("Sir Monis", 201, "Gulshan,Karachi", "03001112222", "monis@uni.edu", "CS", "OOP", 120000);
    Staff staff1("Mr. Khan", 301, "Clifton, karachi", "03451110000", "khan@admin.com", "Admin", "Clerk", 50000);
    Course c1(1002, "Object Oriented Programming", 3, "Sir Monis", "Mon-Wed 10AM-12PM");

    cout << "\n--- University Management System ---\n";
    
    cout << "\nStudent Details:\n";
    s1.displayinfo();

    cout << "\nProfessor Details:\n";
    p1.displayinfo();

    cout << "\nStaff Details:\n";
    staff1.displayinfo();

    cout << "\nCourse Details:\n";
    c1.displayCourseInfo();

    cout << "\nRegistering Student:\n";
    c1.registerStudent(s1);

    return 0;
}

