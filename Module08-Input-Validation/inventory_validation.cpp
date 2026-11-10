#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class InventoryItem {
private:
    string name;
    int quantity;
    double price;

public:
    InventoryItem(string itemName, int itemQuantity, double itemPrice) {
        name = itemName;
        quantity = itemQuantity;
        price = itemPrice;
    }

    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
        }
    }

    void sellItem(int amount) {
        if (amount > 0 && amount <= quantity) {
            quantity -= amount;
        }
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void display() const {
        cout << left << setw(15) << name
             << setw(12) << quantity
             << "$" << fixed << setprecision(2) << price << endl;
    }
};

string getValidName() {
    string name;

    while (true) {
        cout << "Enter item name: ";
        getline(cin, name);

        if (name.find_first_not_of(" \t\r\n") != string::npos) {
            return name;
        }

        cout << "Invalid name. The name cannot be empty. Try again.\n";
    }
}

int getNonNegativeNumber(string prompt) {
    string input;
    int value;
    char extra;

    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);

        if (ss >> value && !(ss >> extra) && value >= 0) {
            return value;
        }

        cout << "Invalid quantity. Enter a whole number of 0 or more.\n";
    }
}

double getValidPrice() {
    string input;
    double price;
    char extra;

    while (true) {
        cout << "Enter item price: ";
        getline(cin, input);
        stringstream ss(input);

        if (ss >> price && !(ss >> extra) && isfinite(price) && price >= 0) {
            return price;
        }

        cout << "Invalid price. Enter a number of 0 or more.\n";
    }
}

int getPositiveNumber(string prompt) {
    int amount;

    while (true) {
        amount = getNonNegativeNumber(prompt);

        if (amount > 0) {
            return amount;
        }

        cout << "Invalid amount. Enter a number greater than 0.\n";
    }
}

int main() {
    cout << "Inventory System\n\n";

    cout << "First item\n";
    string name1 = getValidName();
    int quantity1 = getNonNegativeNumber("Enter quantity: ");
    double price1 = getValidPrice();
    InventoryItem item1(name1, quantity1, price1);

    cout << "\nSecond item\n";
    string name2 = getValidName();
    int quantity2 = getNonNegativeNumber("Enter quantity: ");
    double price2 = getValidPrice();
    InventoryItem item2(name2, quantity2, price2);

    cout << "\nInitial Inventory\n";
    cout << left << setw(15) << "Item"
         << setw(12) << "Quantity" << "Price\n";
    item1.display();
    item2.display();

    cout << "\nAdd stock to " << item1.getName() << "\n";
    int added = getPositiveNumber("Amount to add: ");
    item1.addStock(added);

    cout << "\nSell stock from " << item2.getName() << "\n";
    if (item2.getQuantity() == 0) {
        cout << "No stock available to sell.\n";
    } else {
        int sold;
        while (true) {
            sold = getPositiveNumber("Amount to sell: ");

            if (sold <= item2.getQuantity()) {
                break;
            }

            cout << "Not enough stock. Only " << item2.getQuantity()
                 << " available. Try again.\n";
        }
        item2.sellItem(sold);
    }

    cout << "\nUpdated Inventory\n";
    cout << left << setw(15) << "Item"
         << setw(12) << "Quantity" << "Price\n";
    item1.display();
    item2.display();

    return 0;
}
