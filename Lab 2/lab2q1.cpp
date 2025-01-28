#include <iostream>
using namespace std;

int main(){
    int size;
    int arr[5];
    int sum = 0;
    cout << "Enter the size of array: ";
    cin>>size;
    int* ptr= arr;
    cout << "Element: ";
    for(int i =0; i<size;i++){
        cin>>*(ptr+ i);
        sum+=*(ptr+i);
    }
    cout<<"Sum: "<< sum;

}
