#include<iostream>
using namespace std;

class Engine{
    public:
    void start(){
        cout<<"Engine Started"<<endl;
    }
    void stop(){
        cout<<"Engine stopped"<<endl;
    }

};
class Car
{
private:
    Engine engine;
public:
    void startCar(){
        engine.start();
    }
    void stopCar(){
        engine.stop();
    }
};

int main(){
    Car obj;
    obj.startCar();
    obj.stopCar();

}

