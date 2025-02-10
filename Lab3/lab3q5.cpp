#include <iostream>
using namespace std;

class Book {
private:
    string Bookname;
    string ISBNno;  
    string Authorname;
    string Publisher;

public:
    void setBookDetails(string Bookname, string ISBNno, string Authorname, string Publisher) {
        this->Bookname = Bookname;
        this->ISBNno = ISBNno;
        this->Authorname = Authorname;
        this->Publisher = Publisher;
    }

    string getBookname() {
        return this->Bookname;
    }

    string getISBNno() {  
        return this->ISBNno;
    }

    string getAuthorname() {
        return this->Authorname;
    }

    string getPublisher() {
        return this->Publisher;
    }

    void Bookinfo() {
        cout << "Book Name: " << Bookname << endl;
        cout << "ISBN number: " << ISBNno << endl;
        cout << "Author Name: " << Authorname << endl;
        cout << "Publisher: " << Publisher << endl;
        cout << endl;
    }
};

int main() {
    Book books[5];

    
    books[0].setBookDetails("Rich Dad Poor Dad", "90874562148", "Robert Kiyosaki", "123publishers");
    books[1].setBookDetails("King Henry V", "9457147852365", "William Shakespeare", "21stCEpublishers");
    books[2].setBookDetails("Lord of the Rings", "98564561238526", "J.R.R. Tolkien", "BestPublishers");
    books[3].setBookDetails("Harry Potter", "93442357864", "J.K. Rowling", "123publishers");
    books[4].setBookDetails("Diary of a Wimpy Kid", "97897539874", "Jeff Kinney", "xyzpublishers");

    for (int i = 0; i < 5; i++) {
        books[i].Bookinfo();
    }

    return 0;
}
