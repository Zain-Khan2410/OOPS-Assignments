#include <iostream>
using namespace std;

int main() {
    string movieName;
    float adultPrice, childPrice;
    int adultTickets, childTickets;
    float percentageDonated;
    float grossAmount, amountDonated, Sale;

    cout<<"Enter the movie name: ";
    cin>>movieName;
    cout<<"Enter the price of an adult ticket: ";
    cin>>adultPrice;
    cout<<"Enter the price of a child ticket: ";
    cin>>childPrice;
    cout<<"Enter the number of adult tickets sold: ";
    cin >>adultTickets;
    cout <<"Enter the number of child tickets sold: ";
    cin >>childTickets;
    cout <<"Enter the percentage of gross amount to be donated: ";
    cin >> percentageDonated;

    
    grossAmount = (adultPrice * adultTickets) + (childPrice * childTickets);
    amountDonated = grossAmount * (percentageDonated / 100);
    Sale = grossAmount - amountDonated;


    cout <<"Movie Name:                          " << movieName << endl;
    cout <<"Number of Tickets Sold:              " << (adultTickets + childTickets) << endl;
    cout <<"Gross Amount:                        $ " << grossAmount << endl;
    cout <<"Percentage of Gross Amount Donated:  " << percentageDonated << "%" << endl;
    cout <<"Amount Donated:                      $ " << amountDonated << endl;
    cout <<"Net Sale:                            $ " << Sale << endl;
}
              
