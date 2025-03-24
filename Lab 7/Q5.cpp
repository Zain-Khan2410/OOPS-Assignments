#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isAvailable;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isAvailable(true) {}

    virtual void displayInfo() {
        cout << "Title           : " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID       : " << uniqueID << endl;
        cout << "Publisher       : " << publisher << endl;
        cout << "Availability    : " << (isAvailable ? "Available" : "Checked Out") << endl;
    }

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem() {
        if (!isAvailable) {
            isAvailable = true;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
    string getPublisher() { return publisher; }
    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author          : " << author << endl;
        cout << "ISBN            : " << ISBN << endl;
        cout << "Pages           : " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director, rating;
    int duration;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director        : " << director << endl;
        cout << "Duration (min)  : " << duration << endl;
        cout << "Rating          : " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist          : " << artist << endl;
        cout << "Tracks          : " << numberOfTracks << endl;
        cout << "Genre           : " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, int issue)
        : Media(t, pubDate, id, pub), issueNumber(issue) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number    : " << issueNumber << endl;
    }
};

class Library {
private:
    Media* mediaCollection[10];
    int mediaCount;

public:
    Library() : mediaCount(0) {}

    void addMedia(Media* m) {
        if (mediaCount < 10) {
            mediaCollection[mediaCount++] = m;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void displayAll() {
        for (int i = 0; i < mediaCount; i++) {
            mediaCollection[i]->displayInfo();
            cout << "--------------------------" << endl;
        }
    }

    void searchByTitle(string t) {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getTitle() == t) {
                cout << "Media Found (Title):" << endl;
                mediaCollection[i]->displayInfo();
                return;
            }
        }
        cout << "Media not found by title: " << t << endl;
    }

    void searchByPublisher(string p) {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getPublisher() == p) {
                cout << "Media Found (Publisher):" << endl;
                mediaCollection[i]->displayInfo();
                return;
            }
        }
        cout << "Media not found by publisher: " << p << endl;
    }

    void searchByPublicationYear(string year) {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getPublicationDate() == year) {
                cout << "Media Found (Publication Year):" << endl;
                mediaCollection[i]->displayInfo();
                return;
            }
        }
        cout << "Media not found for publication year: " << year << endl;
    }
};

int main() {
    Library library;

    Book b("Calculus", "2024", "B001", "GoodPress", "Howard Anton", "1234567890", 350);
    DVD d("The Dark Knight Rises", "2012", "D001", "WB", "Christopher Nolan", 148, "PG-13");
    CD c("Abbey Road", "1969", "C002", "Apple Records", "The Beatles", 17, "Rock");
    Magazine m("Time", "2023", "M002", "Time Inc.", 250);

    library.addMedia(&b);
    library.addMedia(&d);
    library.addMedia(&c);
    library.addMedia(&m);

    library.displayAll();
    cout<<"------------Searching by title---------------"<<endl;
    library.searchByTitle("The Dark Knight Rises");
    cout<<"------------Searching by Pulisher------------"<<endl;
    library.searchByPublisher("Apple Records");
    cout<<"------------Searching by Publication Year------------"<<endl;
    library.searchByPublicationYear("2020");

    b.checkOut();
    b.checkOut();
    b.returnItem();
    b.returnItem();

    return 0;
}
