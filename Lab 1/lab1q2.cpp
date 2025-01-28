#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    int sum = 0;
    int* ptr = arr;

    for (int i = 0; i < size; ++i) {
        sum += *(ptr + i);
    }
    cout<<"\nThe sum of the array elements is: "<<sum;
}
