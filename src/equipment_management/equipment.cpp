#include "equipment.hpp"

Equipment::Equipment(const std::string &name, double price) : name(name), price(price) {}

const std::string &Equipment::getName() const
{
    return name;
}

double Equipment::getPrice() const
{
    return price;
}

bool Equipment::operator>(const Equipment &other) const
{
    return price > other.price;
}
