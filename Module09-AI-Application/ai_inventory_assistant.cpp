#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class InventoryItem {
private:
    string name;
    int quantity;
    int weeklySales;

public:
    InventoryItem(string itemName, int itemQuantity, int itemWeeklySales) {
        name = itemName;
        quantity = itemQuantity;
        weeklySales = itemWeeklySales;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    int getWeeklySales() const {
        return weeklySales;
    }

    void display() const {
        cout << left << setw(18) << name
             << setw(14) << quantity
             << weeklySales << endl;
    }
};

struct Recommendation {
    string status;
    int orderAmount;
    string reason;
};

Recommendation mockAI(const InventoryItem& item) {
    int stock = item.getQuantity();
    int sales = item.getWeeklySales();
    int target = sales * 3;

    if (sales == 0) {
        return {"NO SALES DATA", 0, "No sales recorded for this item."};
    }

    if (stock < sales) {
        return {"URGENT", target - stock, "Less than one week of stock remains."};
    }

    if (stock < sales * 2) {
        return {"REORDER SOON", target - stock, "Less than two weeks of stock remains."};
    }

    return {"STOCK OK", 0, "Enough stock for at least two weeks."};
}

int main() {
    InventoryItem items[] = {
        InventoryItem("Notebooks", 8, 12),
        InventoryItem("Pencils", 30, 15),
        InventoryItem("Markers", 16, 12),
        InventoryItem("Erasers", 50, 5)
    };

    const int SIZE = sizeof(items) / sizeof(items[0]);

    cout << "INVENTORY SYSTEM" << endl;
    cout << left << setw(18) << "Item"
         << setw(14) << "In Stock"
         << "Sold Per Week" << endl;
    cout << string(48, '-') << endl;

    for (int i = 0; i < SIZE; i++) {
        items[i].display();
    }

    cout << "\nMOCK AI RESTOCKING ASSISTANT" << endl;
    cout << "Recommendations use sample rules, not a live AI service.\n" << endl;

    for (int i = 0; i < SIZE; i++) {
        Recommendation result = mockAI(items[i]);
        cout << items[i].getName() << ": " << result.status << endl;
        cout << "Reason: " << result.reason << endl;
        cout << "Suggested units to order: " << result.orderAmount << "\n" << endl;
    }

    return 0;
}
