#include <iostream>
#include "Flight.h"

using namespace std;

void addRecord(vector<Flight>& flights) {
    Flight newFlight;

    cout << "Enter flight number: ";
    cin >> newFlight.flightNumber;

    cout << "Enter airline: ";
    cin >> newFlight.airline;

    cout << "Enter delay in minutes: ";
    cin >> newFlight.delay;

    flights.push_back(newFlight);

    cout << "Flight added.\n";
}

void displayRecords(const vector<Flight>& flights) {
    if (flights.empty()) {
        cout << "No flight records available.\n";
        return;
    }

    for (int i = 0; i < flights.size(); i++) {
        cout << "\nFlight " << i + 1 << endl;
        cout << "Flight Number: " << flights[i].flightNumber << endl;
        cout << "Airline: " << flights[i].airline << endl;
        cout << "Delay: " << flights[i].delay << " minutes" << endl;
    }
}

double calculateAverageDelay(const vector<Flight>& flights) {
    if (flights.empty()) {
        return 0;
    }

    double total = 0;

    for (int i = 0; i < flights.size(); i++) {
        total += flights[i].delay;
    }

    return total / flights.size();
}