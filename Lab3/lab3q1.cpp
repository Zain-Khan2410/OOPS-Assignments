#include<iostream>
using namespace std;

class User{
    public:
    string Name;
    int age;
    
   
};
int main(){
    User obj1;
    obj1.Name= "Zain Khan";
    obj1.age= 19;
    cout<<"My name is "<<obj1.Name<<" and I'm  "<<obj1.age<<" Years old "<< endl;
    

}
