#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    Car(string m = "", float p = 0.0) {
        model = m;
        price = p;
    }

    string getModel() {
        return model;
    }

    float getPrice() {
        return price;
    }

    void setModel(string m) {
        model = m;
    }

    virtual void setPrice(float p) = 0;
};

class Color : public Car {
private:
    string color;
public:
    Color(string m, float p, string c) : Car(m, p), color(c) {}

    void setColor(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    void setPrice(float p) override {
        price = p + (0.1 * p);
    }

    void display() {
        cout << "Color Car - Model: " << model << ", Color: " << color << ", Price: " << price << endl;
    }
};

class Company : public Car {
private:
    string company;
public:
    Company(string m, float p, string comp) : Car(m, p), company(comp) {}

    void setCompany(string comp) {
        company = comp;
    }

    string getCompany() {
        return company;
    }

    void setPrice(float p) override {
        price = p - (0.05 * p);
    }

    void display() {
        cout << "Company Car - Model: " << model << ", Company: " << company << ", Price: " << price << endl;
    }
};

int main() {
    Color carcolor("Civic", 30000, "Black");
    carcolor.setPrice(30000);
    carcolor.display();

    Company CarCompany("Corolla", 28000, "Toyota");
    CarCompany.setPrice(28000);
    CaeCompany.display();

    return 0;
}

