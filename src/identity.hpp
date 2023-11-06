#ifndef IDENTITY_HPP
#define IDENTITY_HPP

#include <string>
#include <iostream>

namespace identity
{
    class Identity
    {
    public:
        Identity(const std::string &name, const std::string &email)
            : name(name), email(email) {}

        const std::string &getName() const
        {
            return name;
        }

        const std::string &getEmail() const
        {
            return email;
        }

    protected:
        std::string name;
        std::string email;
    };
}

#endif
