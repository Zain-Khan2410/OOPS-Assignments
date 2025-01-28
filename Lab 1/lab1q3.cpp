#include <iostream>
using namespace std;
int main(){
    string name;
    float total;
    int units;
    float cperunit;
    int customerid;
    float surcharge;
    float bill;

    cout<<"Enter Consumer ID: ";
    cin>>customerid;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter units: ";
    cin>>units;
    if(units<=199){
        cperunit = 16.20;
    }else if(units>=200 && units<300){
        cperunit = 20.10;
    }else if(units>=300 && units< 500){
        cperunit =  27.10;
    }else if(units >= 500){
        cperunit = 35.90;
    } 
    total = cperunit * units;
    if (total > 18000) {
        surcharge = total * 0.15;
    }
    bill = total + surcharge;

    cout<<"\nCustomer ID: "<<customerid;
    cout<<"\nCustomer Name: "<<name;
    cout<<"\nUnits Consumed: "<<units;
    cout<<"\nAmout Charges @Rs."<<cperunit<<" per unit: "<<total;
    cout<<"\nSurcharge Amout: "<<surcharge;
    cout<<"\nNet Amout paid by the customer: "<<bill;
}
