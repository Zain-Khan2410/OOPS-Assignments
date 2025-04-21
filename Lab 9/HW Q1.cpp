#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float getArea() override {
        return length * width;
    }
};
class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() 
    Rectangle r(8.0, 3.0);
    cout << "Area of Rectangle: " << rect.getArea() << endl;

    Triangle t(10.0, 20.0);
    cout << "Area of Triangle: " << tri.getArea() << endl;

    return 0;
}

