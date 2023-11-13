#ifndef IDENTITY_HPP
#define IDENTITY_HPP

#include <string>

namespace identity
{
    class Identity
    {
    public:
        Identity(const std::string &name, const std::string &email);

        const std::string &getName() const;
        const std::string &getEmail() const;

    private:
        std::string name;
        std::string email;
    };
}

#endif
