#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <string>

class Equipment
{
public:
    Equipment(const std::string &name, double price);

    const std::string &getName() const;
    double getPrice() const;

    bool operator>(const Equipment &other) const;

private:
    std::string name;
    double price;
};

#endif
