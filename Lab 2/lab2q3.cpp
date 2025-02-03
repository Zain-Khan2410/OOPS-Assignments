#include <iostream>
using namespace std;

void resize(int*& arr, int& oldSize, int newSize) {
    int* newArr = new int[newSize];

    for (int i = 0; i < oldSize; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    oldSize = newSize;
}

int main() {
    int maxSize = 5;
    int count = 0;  
    int* numbers = new int[maxSize];

    cout << "Enter numbers (enter -1 to stop): " << endl;
    int num;
    
    while (true) {
        cin >> num;
        if (num == -1) break;

        if (count >= 2 * maxSize) {
            resize(numbers, maxSize, maxSize * 2);
        }

        numbers[count++] = num;
    }
    resize(numbers, maxSize, count);

    cout << "Final array: ";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }

    delete[] numbers;
    
}
