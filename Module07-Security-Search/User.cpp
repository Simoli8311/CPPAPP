#include "User.h"

User::User(const std::string& username, Role role)
    : username(username), role(role)
{
}

std::string User::getUsername() const
{
    return username;
}

Role User::getRole() const
{
    return role;
}

bool User::isAdmin() const
{
    return role == Role::ADMIN;
}
