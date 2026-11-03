#include "FightSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

FightSystem::FightSystem() {
    fighterCount = 0;
    srand(static_cast<unsigned int>(time(nullptr)));
}

void FightSystem::loadFromFile(const char* filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Could not open " << filename << endl;
        return;
    }

    fighterCount = 0;

    int id;
    string name;
    int health;
    int attackPower;

    while (fighterCount < MAX_FIGHTERS &&
           inputFile >> id >> name >> health >> attackPower) {
        fighters[fighterCount] = Fighter(id, name, health, attackPower);
        fighterCount++;
    }

    inputFile.close();
    sortByID();
}

void FightSystem::saveToFile(const char* filename) const {
    ofstream outputFile(filename);

    if (!outputFile) {
        cout << "Could not save file." << endl;
        return;
    }

    for (int i = 0; i < fighterCount; i++) {
        outputFile << fighters[i].getID() << " "
                   << fighters[i].getName() << " "
                   << fighters[i].getHealth() << " "
                   << fighters[i].getAttackPower() << endl;
    }

    outputFile.close();
}

void FightSystem::displayAll() const {
    cout << "\n--- Fighter Roster ---\n";

    for (int i = 0; i < fighterCount; i++) {
        fighters[i].display();
    }
}

void FightSystem::sortByID() {
    for (int i = 0; i < fighterCount - 1; i++) {
        for (int j = 0; j < fighterCount - i - 1; j++) {
            if (fighters[j].getID() > fighters[j + 1].getID()) {
                Fighter temp = fighters[j];
                fighters[j] = fighters[j + 1];
                fighters[j + 1] = temp;
            }
        }
    }
}

Fighter* FightSystem::binarySearch(int id) {
    int low = 0;
    int high = fighterCount - 1;

    while (low <= high) {
        int middle = (low + high) / 2;

        if (fighters[middle].getID() == id) {
            return &fighters[middle];
        }
        else if (fighters[middle].getID() < id) {
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }

    return nullptr;
}

void FightSystem::battle(Fighter* fighter1, Fighter* fighter2) {
    if (fighter1 == nullptr || fighter2 == nullptr) {
        cout << "Invalid fighter selection.\n";
        return;
    }

    if (fighter1 == fighter2) {
        cout << "A fighter cannot battle themselves.\n";
        return;
    }

    int health1 = 100;
    int health2 = 100;

    cout << "\n=== " << fighter1->getName()
         << " VS " << fighter2->getName() << " ===\n";

    while (health1 > 0 && health2 > 0) {
        int damage1 = (rand() % fighter1->getAttackPower()) + 1;
        int damage2 = (rand() % fighter2->getAttackPower()) + 1;

        health2 -= damage1;
        if (health2 < 0) {
            health2 = 0;
        }

        cout << fighter1->getName() << " hits "
             << fighter2->getName() << " for "
             << damage1 << " damage. "
             << fighter2->getName() << " HP: "
             << health2 << endl;

        if (health2 == 0) {
            break;
        }

        health1 -= damage2;
        if (health1 < 0) {
            health1 = 0;
        }

        cout << fighter2->getName() << " hits "
             << fighter1->getName() << " for "
             << damage2 << " damage. "
             << fighter1->getName() << " HP: "
             << health1 << endl;
    }

    if (health1 > 0) {
        cout << "\nWinner: " << fighter1->getName() << "!\n";
    }
    else {
        cout << "\nWinner: " << fighter2->getName() << "!\n";
    }
}

int FightSystem::getFighterCount() const {
    return fighterCount;
}
