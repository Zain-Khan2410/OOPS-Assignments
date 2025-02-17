#include<iostream>
using namespace std;

class Circle{
    private:
    double radius;

    public:
    Circle(double r){
        radius = r;
    }

    double getArea(){
        return 3.142 * radius * radius; 
    }

    double getPeri(){
        return 2 * 3.142 * radius;
    }
};
int main(){
    Circle c(6);
    cout<<"Area: "<<c.getArea()<<endl;
    cout<<"Perimeter: "<<c.getPeri()<<endl;

}
