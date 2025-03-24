#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    int posx, posy;
    string color;

public:
    Shape(int x, int y, string c) : posx(x), posy(y), color(c) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(int x, int y, double r, string c) : Shape(x, y, c), radius(r) {}

    void draw() override {
        cout << "Drawing Circle at (" << posx << ", " << posy << ") with radius " << radius << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double height, width;

public:
    Rectangle(int x, int y, string c, double w, double h) 
        : Shape(x, y, c), width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle with top-left corner at (" << posx << ", " << posy 
             << "), width " << width << " and height " << height << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(int x, int y, string c, double A, double B, double C) 
        : Shape(x, y, c), a(A), b(B), c(C) {}

    void draw() override {
        cout << "Drawing Triangle at (" << posx << ", " << posy << ") with sides " 
             << a << ", " << b << ", " << c << endl;
    }

    double calculateArea() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculatePerimeter() override {
        return a + b + c;
    }
};

class Polygon : public Shape {
private:
    int numSides;
    double* sideLengths;

public:
    Polygon(int x, int y, string c, int sides) 
        : Shape(x, y, c), numSides(sides) {
        sideLengths = new double[numSides];
        cout << "Enter " << numSides << " side lengths: ";
        for (int i = 0; i < numSides; i++) {
            cin >> sideLengths[i];
        }
    }

    ~Polygon() {
        delete[] sideLengths;
    }

    void draw() override {
        cout << "Drawing Polygon at (" << posx << ", " << posy << ") with " << numSides << " sides\n";
    }

    double calculatePerimeter() override {
        double perimeter = 0;
        for (int i = 0; i < numSides; i++) {
            perimeter += sideLengths[i];
        }
        return perimeter;
    }

    double calculateArea() override {
        if (numSides < 3) return 0;
        double s = sideLengths[0]; 
        return (numSides * s * s) / (4 * tan(M_PI / numSides));
    }
};

int main() {

    Circle c(10, 20, 5, "Red"); // This tells that the coordiantes are 10 and 20 with radius 5
    c.draw();
    cout << "Area: " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;
    cout<<"------------------------------------------------------"<<endl;
    
    Rectangle r(5, 10, "Blue", 8, 6);//this tells that coordinates are 5 and 10 with width 8 and height 6
    r.draw();
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;
    cout<<"------------------------------------------------------"<<endl;
    
    Triangle t(3, 4, "Green", 3, 4, 5); // this tells that the coordinates for triangle is 3,4 with sides 3,4,5
    t.draw();
    cout << "Area: " << t.calculateArea() << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << endl;
    cout<<"------------------------------------------------------"<<endl;
    
    Polygon p(0, 0, "Yellow", 4);  // this 4 tells that user will input 4 sides
    p.draw();
    cout << "Area: " << p.calculateArea() << endl;
    cout << "Perimeter: " << p.calculatePerimeter() << endl;
    

    return 0;
}
