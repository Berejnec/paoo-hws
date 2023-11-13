#include "identity.hpp"

namespace identity
{
    Identity::Identity(const std::string &name, const std::string &email)
        : name(name), email(email) {}

    const std::string &Identity::getName() const
    {
        return name;
    }

    const std::string &Identity::getEmail() const
    {
        return email;
    }
}
