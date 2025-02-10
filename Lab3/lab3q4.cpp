#include <iostream>
using namespace std;

class Employee
{
private:
    string fname;
    string lname;
    double msalary;   
public:
    void setSalary(double msalary){
        if(msalary<0){
            this->msalary = 0;
        }
        else{
            this->msalary = msalary;
        }
    }
    double yearlySalary(){
        return msalary * 12;

    }
    double Raise(){
        return msalary * 12 + msalary * 0.1;
    }


};
int main(){
    Employee e1;
    Employee e2;
    e1.setSalary(2000);
    e2.setSalary(4000);
    cout<<"Employee 1 Yearly Salary: " << e1.yearlySalary()<<endl;
    cout<<"Employee 2 Yearly Salary: " << e2.yearlySalary()<<endl;
    cout<<"After Raise:"<<endl;
    cout<<"Employee 1 Yearly Salary: " << e1.Raise()<<endl;
    cout<<"Employee 2 Yearly Salary: " << e2.Raise()<<endl;

}
