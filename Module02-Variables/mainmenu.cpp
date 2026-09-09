#include <iostream>
#include <string>
#include <limits>
using namespace std;

void addService() {
    cout << "Add Service selected." << endl;
}

void viewServiceHistory() {
    cout << "View Service History selected." << endl;
}

void checkMileage() {
    cout << "Check Mileage selected." << endl;
}

void addRepair() {
    cout << "Add Repair selected." << endl;
}

void viewVehicleInfo() {
    cout << "View Vehicle Information selected." << endl;
}

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== CAR MAINTENANCE TRACKER ===" << endl;
        cout << "1. Add Service" << endl;
        cout << "2. View Service History" << endl;
        cout << "3. Check Mileage" << endl;
        cout << "4. Add Repair" << endl;
        cout << "5. View Vehicle Information" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                addService();
                break;

            case 2:
                viewServiceHistory();
                break;

            case 3:
                checkMileage();
                break;

            case 4:
                addRepair();
                break;

            case 5:
                viewVehicleInfo();
                break;

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}