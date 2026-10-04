#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

struct Flight {
    std::string flightNumber;
    std::string airline;
    double delay;
};

void addRecord(std::vector<Flight>& flights);
void displayRecords(const std::vector<Flight>& flights);
double calculateAverageDelay(const std::vector<Flight>& flights);

#endif