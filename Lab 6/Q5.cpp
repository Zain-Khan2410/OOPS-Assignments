#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    float vehicle_price;

public:
    void set_price(float p) {
        vehicle_price = p;
    }

    void display_price() {
        cout << "Price: $" << vehicle_price << endl;
    }
};

class Car : public Vehicle {
protected:
    int seating_capacity;
    int number_doors;
    string fuel_type;

public:
    void set_car_details(int seats, int doors, string fuel) {
        seating_capacity = seats;
        number_doors = doors;
        fuel_type = fuel;
    }

    void car_details() {
        display_price();
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Doors: " << number_doors << endl;
        cout << "Fuel Type: " << fuel_type << endl;
    }
};

class Motorcycle : public Vehicle {
protected:
    int number_cylinders;
    int number_gears;
    int number_wheels;

public:
    void set_motorcycle_details(int cylinders, int gears, int wheels) {
        number_cylinders = cylinders;
        number_gears = gears;
        number_wheels = wheels;
    }

    void motorcycle_details() {
        display_price();
        cout << "Number of Cylinders: " << number_cylinders << endl;
        cout << "Number of Gears: " << number_gears << endl;
        cout << "Number of Wheels: " << number_wheels << endl;
    }
};

class Audi : public Car {
private:
    string model_type;

public:
    void set_model_type(string model) {
        model_type = model;
    }

    void audi_details() {
        car_details();
        cout << "Model Type: " << model_type << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string make_type;

public:
    void set_make_type(string make) {
        make_type = make;
    }

    void yamaha_details() {
        motorcycle_details();
        cout << "Make Type: " << make_type << endl;
    }
};

int main() {
    Audi audi;
    audi.set_price(5000000);
    audi.set_car_details(5, 4, "Petrol");
    audi.set_model_type("A4");

    Yamaha yamaha;
    yamaha.set_price(180000);
    yamaha.set_motorcycle_details(2, 6, 2);
    yamaha.set_make_type("R1");

    cout << "--- Audi Car Details ---" << endl;
    audi.audi_details();

    cout << "\n--- Yamaha Motorcycle Details ---" << endl;
    yamaha.yamaha_details();

    return 0;
}
