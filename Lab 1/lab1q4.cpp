#include <iostream>
using namespace std;
#include <iomanip>

int main(){
 float weightkg;
 float weightp;
  
cout <<"Enter weight in Kilograms: ";
cin>>weightkg;
weightp = weightkg * 2.2;
cout<<fixed << setprecision(2);
cout<<"\nWeight in Kiograms: "<<weightkg;
cout<<"\nWeight in Pounds: "<<weightp;
}
