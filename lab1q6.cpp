#include <iostream>
using namespace std;

int main(){
    float marks[5];
    string name;
    float total = 0;
    float average = 0;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter marks: ";
    for(int i=0; i<5;i++){
        cin>>marks[i];
        total += marks[i];
    }
    average = total / 5;
    cout <<"Name: "<<name;
    cout<<"\nTest Scores: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout <<"\nAverage Marks: " << average;
}
