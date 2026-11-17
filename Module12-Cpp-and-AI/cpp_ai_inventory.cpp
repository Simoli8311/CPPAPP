#include <iostream>
#include <string>
using namespace std;

int findItem(string items[], int size, string name) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (items[middle] == name) {
            return middle;
        }
        if (items[middle] < name) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    const int SIZE = 5;
    string items[SIZE] = {"Apple", "Bread", "Milk", "Rice", "Water"};
    int quantities[SIZE] = {10, 8, 12, 6, 15};
    int choice = 0;
    string name;
    int amount;

    while (choice != 4) {
        cout << "\nInventory System\n";
        cout << "1. View inventory\n";
        cout << "2. Search for item\n";
        cout << "3. Update item quantity\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << items[i] << ": " << quantities[i] << endl;
            }
        } else if (choice == 2) {
            cout << "Enter item name: ";
            cin >> name;
            int index = findItem(items, SIZE, name);

            if (index == -1) {
                cout << "Item not found.\n";
            } else {
                cout << name << " quantity: " << quantities[index] << endl;
            }
        } else if (choice == 3) {
            cout << "Enter item name: ";
            cin >> name;
            int index = findItem(items, SIZE, name);

            if (index == -1) {
                cout << "Item not found.\n";
            } else {
                cout << "Enter new quantity: ";
                cin >> amount;
                if (amount >= 0) {
                    quantities[index] = amount;
                    cout << "Quantity updated.\n";
                } else {
                    cout << "Quantity cannot be negative.\n";
                }
            }
        } else if (choice != 4) {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
