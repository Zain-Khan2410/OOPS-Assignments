#include <iostream>
using namespace std;

// Abstract base class
class Student {
public:
    virtual float getTuition(string status, int creditHours) = 0; // Pure virtual
    virtual ~Student() {}
};

// Derived class
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    float getTuition(string status, int creditHours) override {
        if (status == "undergraduate") {
            return 200 * creditHours;
        } else if (status == "graduate") {
            return 300 * creditHours;
        } else if (status == "doctoral") {
            return 400 * creditHours;
        } else {
            cout << "Invalid status!" << endl;
            return 0;
        }
    }
};

int main() {
    GraduateStudent grad;
    
    grad.setResearchTopic("Artificial Intelligence in Healthcare");
    cout << "Research Topic: " << grad.getResearchTopic() << endl;

    string status;
    int creditHours;

    cout << "Enter student status (undergraduate / graduate / doctoral): ";
    cin >> status;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    float tuition = grad.getTuition(status, creditHours);
    cout << "Tuition: $" << tuition << endl;

    return 0;
}

