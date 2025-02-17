#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    double price;
    int stock;

public:
    Book(string auth, string titl, string pub, double pr, int stk) {
        author = auth;
        title = titl;
        publisher = pub;
        
        if (pr > 0) {
            price = pr;
        } else {
            price = 0.0;
        }
        
        if (stk > 0) {
            stock = stk;
        } else {
            stock = 0;
        }
    }

    void displayBook() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }

    bool isAvailable(string titl, string auth) const {
        return (title == titl && author == auth);
    }

    void sellBook(int quantity) {
        if (quantity <= stock) {
            cout << "Total Cost: " << quantity * price << endl;
            stock -= quantity;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    Book b("Jeff Kinney", "Diary of a wimpy Kid", "XYZ Publishers", 25.50, 20);
    string searchTitle, searchAuthor;
    int copies;

    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter author name: ";
    getline(cin, searchAuthor);

    if (b.isAvailable(searchTitle, searchAuthor)) {
        b.displayBook();
        cout << "Enter number of copies required: ";
        cin >> copies;
        b.sellBook(copies);
    } else {
        cout << "Book not available" << endl;
    }

    return 0;
}
