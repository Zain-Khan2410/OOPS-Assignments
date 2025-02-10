#include <iostream>
using namespace std;
class Glass
{
private:
    int LiquidLevel = 200;
public:
    void Drink(int millilitres){
         LiquidLevel = LiquidLevel - millilitres;
    }
    void Refill(){
        if(LiquidLevel<100){
            LiquidLevel = 200;
            cout<<"Glass has been refilled"<<endl;
        }

    }
};
int main(){
    Glass g;
    int millilitres = 0;
    while(millilitres!= -1){
        cout <<"Enter millilitres drink(-1 for exit): "<<endl;
        cin>>millilitres;
        g.Drink(millilitres);
        g.Refill();
    }
}

