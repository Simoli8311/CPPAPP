#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int SIZE = 8;

    string airlines[SIZE] = {
        "Aer Lingus",
        "Aeroflot*",
        "Air Canada",
        "Air France",
        "Air India*",
        "Air New Zealand*",
        "Alaska Airlines*",
        "Alitalia"
    };

    int incidents[SIZE] = {0, 6, 2, 6, 4, 5, 5, 4};
    int fatalities[SIZE] = {0, 88, 0, 337, 158, 7, 88, 0};

    cout << left << setw(20) << "Airline"
         << setw(20) << "Incidents (2000-14)"
         << "Fatalities (2000-14)" << endl;

    cout << string(62, '-') << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(20) << airlines[i]
             << setw(20) << incidents[i]
             << fatalities[i] << endl;
    }

    int* valuePointer = &fatalities[5];

    cout << "\nPointer example:" << endl;
    cout << "Fatalities for " << airlines[5] << ": " << *valuePointer << endl;

    return 0;
}
