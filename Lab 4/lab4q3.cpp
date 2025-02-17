#include <iostream>
#include <string>

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, double price) {
        partNumber = partNum;
        partDescription = partDesc;
        
        if (qty > 0) {
            quantity = qty;
        } else {
            quantity = 0;
        }
        
        if (price > 0) {
            pricePerItem = price;
        } else {
            pricePerItem = 0.0;
        }
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

    void displayInvoice() const {
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price Per Item: " << pricePerItem << endl;
        cout << "Total Invoice Amount: " << getInvoiceAmount() << endl;
    }
};

int main() {
    Invoice invoice("0838", "Screw", 50, 1.5);
    invoice.displayInvoice();
    return 0;
}
