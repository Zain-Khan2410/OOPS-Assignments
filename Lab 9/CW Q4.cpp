#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Passenger;

class Flight {
private:
    string flightNumber;
    string departure;
    string destination;
    int maxSeats;
    int occupied = 0;
    unordered_set<string> registeredIDs;

public:
    Flight(const string& code, const string& from, const string& to, int seats)
        : flightNumber(code), departure(from), destination(to), maxSeats(seats) {}

    bool bookSeat(const Passenger& p);
    bool cancelSeat(const Passenger& p);
    bool upgradeSeat(const Passenger& p);
    void showDetails() const;

private:
    bool isRegistered(const string& pid) const {
        return registeredIDs.find(pid) != registeredIDs.end();
    }
};

class Passenger {
private:
    string passengerID;
    string fullName;

public:
    Passenger(const string& pid, const string& name) : passengerID(pid), fullName(name) {}

    string getID() const { return passengerID; }

    void bookFlight(Flight& f) {
        if (f.bookSeat(*this)) {
            cout << fullName << " has been booked successfully.\n";
        } else {
            cout << fullName << " booking unsuccessful.\n";
        }
    }

    void cancelBooking(Flight& f) {
        if (f.cancelSeat(*this)) {
            cout << fullName << "'s booking was canceled.\n";
        } else {
            cout << "Cancellation failed for " << fullName << ".\n";
        }
    }

    void upgradeRequest(Flight& f) {
        if (f.upgradeSeat(*this)) {
            cout << fullName << " received an upgrade.\n";
        } else {
            cout << fullName << " is not eligible for an upgrade.\n";
        }
    }
};

bool Flight::bookSeat(const Passenger& p) {
    if (occupied >= maxSeats || isRegistered(p.getID())) {
        return false;
    }
    registeredIDs.insert(p.getID());
    occupied++;
    return true;
}

bool Flight::cancelSeat(const Passenger& p) {
    if (!isRegistered(p.getID())) {
        return false;
    }
    registeredIDs.erase(p.getID());
    occupied--;
    return true;
}

bool Flight::upgradeSeat(const Passenger& p) {
    return isRegistered(p.getID());
}

void Flight::showDetails() const {
    cout << "Flight Code: " << flightNumber << " | From: " << departure 
         << " | To: " << destination << " | Seats: " << occupied << "/" << maxSeats << endl;
}

int main() {
    Flight dubaiFlight("EK303", "Lahore", "Dubai", 2);
    Flight berlinFlight("LH909", "Rome", "Berlin", 1);

    Passenger sam("U01", "Samantha");
    Passenger leo("U02", "Leonard");
    Passenger nina("U03", "Nina");

    dubaiFlight.showDetails();
    sam.bookFlight(dubaiFlight);
    leo.bookFlight(dubaiFlight);
    nina.bookFlight(dubaiFlight);
    dubaiFlight.showDetails();

    sam.upgradeRequest(dubaiFlight);
    nina.upgradeRequest(dubaiFlight);

    leo.cancelBooking(dubaiFlight);
    dubaiFlight.showDetails();

    nina.bookFlight(dubaiFlight);
    dubaiFlight.showDetails();

    return 0;
}
