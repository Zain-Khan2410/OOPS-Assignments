#include <iostream>
using namespace std;

class Shape {
private:
    double area;

public:
    Shape(double a = 0) : area(a) {}

    Shape operator+(const Shape& other) {
        return Shape(this->area + other.area);
    }
    void display() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(25.5);
    Shape shape2(40.7);

    cout << "Shape1 ";
    shape1.display();

    cout << "Shape2 ";
    shape2.display();
    Shape shape3 = shape1 + shape2;

    cout << "After adding shape1 and shape2: ";
    shape3.display();

    return 0;
}
