#ifndef FIGHTSYSTEM_H
#define FIGHTSYSTEM_H

#include "Fighter.h"

class FightSystem {
private:
    static const int MAX_FIGHTERS = 20;
    Fighter fighters[MAX_FIGHTERS];
    int fighterCount;

    void sortByID();

public:
    FightSystem();

    void loadFromFile(const char* filename);
    void saveToFile(const char* filename) const;
    void displayAll() const;
    Fighter* binarySearch(int id);
    void battle(Fighter* fighter1, Fighter* fighter2);
    int getFighterCount() const;
};

#endif
