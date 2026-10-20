#ifndef USER_H
#define USER_H

#include <string>

enum class Role
{
    ADMIN,
    REGULAR
};

class User
{
private:
    std::string username;
    Role role;

public:
    User(const std::string& username, Role role);

    std::string getUsername() const;
    Role getRole() const;
    bool isAdmin() const;
};

#endif
