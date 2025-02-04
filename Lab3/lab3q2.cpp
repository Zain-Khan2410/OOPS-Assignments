#include<iostream>
using namespace std;

class Dates{
    private:
    int Date;
    int Month;
    int Year;

    public:
    void setdate(int d){
        this->Date = d;
    }  
      void setMonth(int m){
        this->Month = m;
    }
      void setYear(int y){
        this->Year = y;
    } 
    
    void displayDate(){
        cout<< this->Date << "/" << this->Month << "/" << this->Year;
    }
   
};

int main(){
    Dates obj1;
    obj1.setdate(4);
    obj1.setMonth(2);
    obj1.setYear(2025);
    obj1.displayDate();
}
