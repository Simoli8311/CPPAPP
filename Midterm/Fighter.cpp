#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter() {
    id = 0;
    name = "Unknown";
    health = 100;
    attackPower = 10;
}

Fighter::Fighter(int fighterID, string fighterName, int fighterHealth, int fighterAttack) {
    id = fighterID;
    name = fighterName;
    health = fighterHealth;
    attackPower = fighterAttack;
}

int Fighter::getID() const {
    return id;
}

string Fighter::getName() const {
    return name;
}

int Fighter::getHealth() const {
    return health;
}

int Fighter::getAttackPower() const {
    return attackPower;
}

void Fighter::setHealth(int newHealth) {
    health = newHealth;
}

void Fighter::display() const {
    cout << "ID: " << id
         << " | Name: " << name
         << " | Health: " << health
         << " | Attack: " << attackPower << endl;
}
