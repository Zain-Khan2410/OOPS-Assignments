#include <iostream>
using namespace std;

int main() {
    float arr[20];
    float *ptr = arr;

    cout << "Enter 20 float numbers: ";
    for (int i = 0; i < 20; i++) {
        cin >> *(ptr + i);
    }

    float highest = *ptr;
    float secondhighest;

    for (int i = 1; i < 20; i++) {
        if (*(ptr + i) > highest) {
            secondhighest = highest;
            highest = *(ptr + i);
        } else if (*(ptr + i) > secondhighest && *(ptr + i) < highest) {
            secondhighest = *(ptr + i);
        }
    }
        cout << "The second highest number is: " << secondhighest << endl;
} 
