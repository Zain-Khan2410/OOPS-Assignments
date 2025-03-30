#include <iostream>

using namespace std;

class Number {
private:
    int value;
    int originalValue; 

public:
    Number(int v) : value(v), originalValue(v) {}

    Number& operator--() {
        value *= 4;  
        return *this;
    }

    Number operator--(int) {
        Number temp(originalValue / 4); 
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(16);

    cout << "Original ";
    num.display();

    --num;
    cout << "After Prefix (--num): ";
    num.display();

    Number result = num--; 
    cout << "After Postfix (num--): ";
    result.display(); 

    return 0;
}
