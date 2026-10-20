#include <iostream>
#include <vector>
#include <string>
#include "User.h"

struct Record
{
    int id;
    std::string name;
};

int binarySearchById(const std::vector<Record>& records, int targetId)
{
    int left = 0;
    int right = static_cast<int>(records.size()) - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (records[middle].id == targetId)
            return middle;

        if (records[middle].id < targetId)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

void addRecordSorted(std::vector<Record>& records, const Record& newRecord)
{
    auto it = records.begin();

    while (it != records.end() && it->id < newRecord.id)
        ++it;

    records.insert(it, newRecord);
}

void displayRecords(const std::vector<Record>& records)
{
    if (records.empty())
    {
        std::cout << "No records available.\n";
        return;
    }

    std::cout << "\nRecords:\n";
    for (const Record& record : records)
        std::cout << "ID: " << record.id << " | Name: " << record.name << '\n';
}

void searchRecord(const std::vector<Record>& records)
{
    int id;
    std::cout << "Enter record ID to search: ";
    std::cin >> id;

    int index = binarySearchById(records, id);

    if (index == -1)
        std::cout << "Record not found.\n";
    else
        std::cout << "Found: ID " << records[index].id
                  << " | Name: " << records[index].name << '\n';
}

void addRecord(std::vector<Record>& records)
{
    Record newRecord;

    std::cout << "Enter new record ID: ";
    std::cin >> newRecord.id;

    if (binarySearchById(records, newRecord.id) != -1)
    {
        std::cout << "A record with that ID already exists.\n";
        return;
    }

    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, newRecord.name);

    addRecordSorted(records, newRecord);
    std::cout << "Record added in sorted order.\n";
}

void deleteRecord(std::vector<Record>& records)
{
    int id;
    std::cout << "Enter record ID to delete: ";
    std::cin >> id;

    int index = binarySearchById(records, id);

    if (index == -1)
    {
        std::cout << "Record not found.\n";
        return;
    }

    records.erase(records.begin() + index);
    std::cout << "Record deleted.\n";
}

void runMenu(const User& user, std::vector<Record>& records)
{
    int choice = 0;

    while (choice != 5)
    {
        std::cout << "\nLogged in as: " << user.getUsername();

        if (user.isAdmin())
            std::cout << " (Admin)\n";
        else
            std::cout << " (Regular User)\n";

        std::cout << "1. Display records\n";
        std::cout << "2. Search record by ID\n";
        std::cout << "3. Add record\n";
        std::cout << "4. Delete record\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                displayRecords(records);
                break;

            case 2:
                searchRecord(records);
                break;

            case 3:
                if (user.isAdmin())
                    addRecord(records);
                else
                    std::cout << "Access denied. Admin only.\n";
                break;

            case 4:
                if (user.isAdmin())
                    deleteRecord(records);
                else
                    std::cout << "Access denied. Admin only.\n";
                break;

            case 5:
                std::cout << "Goodbye.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    }
}

int main()
{
    std::vector<Record> records =
    {
        {101, "Alice"},
        {205, "Bob"},
        {310, "Carlos"},
        {450, "Diana"}
    };

    int roleChoice;
    std::string username;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Choose role:\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Regular User\n";
    std::cout << "Choice: ";
    std::cin >> roleChoice;

    User currentUser(
        username,
        roleChoice == 1 ? Role::ADMIN : Role::REGULAR
    );

    runMenu(currentUser, records);

    return 0;
}
