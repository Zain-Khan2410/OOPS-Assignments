#include <iostream>
#include <windows.h>
using namespace std;
 class Blend{
    public:
    void blend(){
        cout << "Blending Fruits "<<endl;
        Sleep(5000);
        cout<<"Blending Complete "<<endl;

    }
 };
 class Grind{
    public:
    void grind(){
        cout<<"Grinding Fruits "<<endl;
        Sleep(5000);
        cout<<"Grinding Complete "<<endl;
    }

 };
 class JuiceMaker{
    public:
    Blend b;
    Grind g;
    void juicemake(){
    cout <<"Making juice"<<endl;
    b.blend();
    g.grind();
 }
};
int main(){
    JuiceMaker j;
    j.juicemake();
}
