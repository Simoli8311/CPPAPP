#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
using namespace std;

class Fighter {
private:
    int id;
    string name;
    int health;
    int attackPower;

public:
    Fighter();
    Fighter(int fighterID, string fighterName, int fighterHealth, int fighterAttack);

    int getID() const;
    string getName() const;
    int getHealth() const;
    int getAttackPower() const;

    void setHealth(int newHealth);
    void display() const;
};

#endif
