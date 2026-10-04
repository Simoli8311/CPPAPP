#include <iostream>
#include <vector>
#include "Flight.h"

using namespace std;

int main() {
    vector<Flight> flights;
    int choice;

    do {
        cout << "\nFlight Record Menu\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Calculate Average Delay\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addRecord(flights);
        }
        else if (choice == 2) {
            displayRecords(flights);
        }
        else if (choice == 3) {
            cout << "Average Delay: "
                 << calculateAverageDelay(flights)
                 << " minutes\n";
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}