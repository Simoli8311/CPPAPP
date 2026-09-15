#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userName = "Filippo De Angelis";
    string appName = "Information App";
    double versionNumber = 1.0;
    int releaseYear = 2026;
    char status = 'A';
    bool active = true;

    cout << "==================================" << endl;
    cout << "      WELCOME TO MY APPLICATION   " << endl;
    cout << "==================================" << endl;

    cout << "User: " << userName << endl;
    cout << "Application: " << appName << endl;
    cout << "Version: " << versionNumber << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Status: " << status << endl;
    cout << "Active: " << active << endl;

    cout << "==================================" << endl;
    cout << "Welcome, " << userName << "!" << endl;

    return 0;
}