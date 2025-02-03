#include <iostream>
using namespace std;

void* sumArray(void* arr, int size) {
    int* intArr = static_cast<int*>(arr); 
    int* sum = new int(0); 

    for (int i = 0; i < size; i++) {
        *sum += intArr[i]; 
    }

    return sum; 
}

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[100];  

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int* result = static_cast<int*>(sumArray(arr, size));

    cout << "Sum of all elements: " << *result << endl;
}
