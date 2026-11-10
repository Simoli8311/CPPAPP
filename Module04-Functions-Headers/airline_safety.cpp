#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 8;

    string selectedAirlines[SIZE] = {
        "Aer Lingus",
        "Aeroflot*",
        "Air Canada",
        "Air France",
        "Air India*",
        "Air New Zealand*",
        "Alaska Airlines*",
        "Alitalia"
    };

    string airlines[SIZE];
    int incidents[SIZE] = {0};
    int fatalities[SIZE] = {0};
    bool found[SIZE] = {false};
    int foundCount = 0;

    fstream file("airline_safety_sample.csv", ios::in);

    if (!file.is_open()) {
        cout << "Error opening airline_safety_sample.csv" << endl;
        return 1;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream record(line);
        string columns[8];
        bool validRow = true;

        for (int i = 0; i < 8; i++) {
            if (!getline(record, columns[i], ',')) {
                validRow = false;
                break;
            }
        }

        if (!validRow) {
            continue;
        }

        for (int i = 0; i < SIZE; i++) {
            if (columns[0] == selectedAirlines[i] && !found[i]) {
                airlines[i] = columns[0];
                incidents[i] = stoi(columns[5]);
                fatalities[i] = stoi(columns[7]);
                found[i] = true;
                foundCount++;
                break;
            }
        }
    }

    file.close();

    if (foundCount != SIZE) {
        cout << "Error: Some airlines were not found in the CSV file." << endl;
        return 1;
    }

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
