#include<iostream>
#include<vector>
using namespace std;

class Car {
private:
    int id;
    string name;

public:
    Car(int x, string n) : id(x), name(n) {}

    string get_name() const {
        return name;
    }

    int get_id() const {
        return id;
    }
};

class Garage {
private:
    vector<Car*> cars;

public:
    void parkCar(Car* e) {
        cars.push_back(e);
    }

    void listCars() const {
        for (Car* c : cars) {
            cout  << c->get_id() <<". "<< c->get_name() << '\n';
        }
    }
};

int main() {
    Car c1(245, "Toyota");
    Car c2(717, "Nissan");
    Garage g1;
    g1.parkCar(&c1);
    g1.parkCar(&c2);
    g1.listCars();

    return 0;
}

