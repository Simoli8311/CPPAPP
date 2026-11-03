#include <iostream>
#include "FightSystem.h"
using namespace std;

int main() {
    FightSystem game;
    game.loadFromFile("fighters.txt");

    int choice;

    do {
        cout << "\n===== FIGHT SYSTEM =====\n";
        cout << "1. Display all fighters\n";
        cout << "2. Search for fighter\n";
        cout << "3. Start a fight\n";
        cout << "4. Show data type sizes\n";
        cout << "5. Save and exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            game.displayAll();
        }
        else if (choice == 2) {
            int id;
            cout << "Enter fighter ID: ";
            cin >> id;

            Fighter* found = game.binarySearch(id);

            if (found != nullptr) {
                cout << "\nFighter found:\n";
                found->display();
            }
            else {
                cout << "Fighter not found.\n";
            }
        }
        else if (choice == 3) {
            int id1, id2;

            cout << "Enter first fighter ID: ";
            cin >> id1;

            cout << "Enter second fighter ID: ";
            cin >> id2;

            Fighter* fighter1 = game.binarySearch(id1);
            Fighter* fighter2 = game.binarySearch(id2);

            game.battle(fighter1, fighter2);
        }
        else if (choice == 4) {
            cout << "\n--- Data Type Sizes ---\n";
            cout << "int: " << sizeof(int) << " bytes\n";
            cout << "double: " << sizeof(double) << " bytes\n";
            cout << "char: " << sizeof(char) << " byte\n";
            cout << "Fighter: " << sizeof(Fighter) << " bytes\n";
        }
        else if (choice == 5) {
            game.saveToFile("fighters.txt");
            cout << "Fighter data saved. Goodbye!\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
