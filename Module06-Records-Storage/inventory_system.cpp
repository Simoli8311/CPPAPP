#include <iostream>
#include <iomanip>
#include <string>
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

    int getQuantity() const {
        return quantity;
    }

    void display() const {
        cout << left << setw(15) << name
             << setw(12) << quantity
             << "$" << fixed << setprecision(2) << price << endl;
    }
};

int main() {
    InventoryItem item1("Notebooks", 10, 3.50);
    InventoryItem item2("Pencils", 25, 0.75);

    cout << "Initial Inventory" << endl;
    cout << left << setw(15) << "Item"
         << setw(12) << "Quantity" << "Price" << endl;
    item1.display();
    item2.display();

    item1.addStock(5);
    item2.sellItem(3);

    cout << "\nUpdated Inventory" << endl;
    cout << left << setw(15) << "Item"
         << setw(12) << "Quantity" << "Price" << endl;
    item1.display();
    item2.display();

    cout << "\nNotebooks in stock: " << item1.getQuantity() << endl;

    return 0;
}
