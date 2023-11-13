#include "hiker.hpp"
#include <iostream>

Hiker::Hiker(const std::string &name, const std::string &email, int experienceLevel, const Equipment &equipment)
    : identity::Identity(name, email), experienceLevel(new int(experienceLevel)), equipment(new Equipment(equipment.getName(), equipment.getPrice()))
{
}

Hiker::Hiker(const Hiker &other)
    : Identity(other.getName(), other.getEmail()),
      experienceLevel(new int(*(other.experienceLevel))),
      equipment(new Equipment((other.equipment->getName()), (other.equipment->getPrice())))
{
}

Hiker &Hiker::operator=(const Hiker &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (other.equipment)
    {
        if (equipment)
        {
            *equipment = Equipment(equipment->getName() + " " + other.equipment->getName(), equipment->getPrice());
        }
        else
        {
            equipment = new Equipment(*(other.equipment));
        }
    }

    return *this;
}

bool Hiker::operator>(const Hiker &other) const
{
    return *experienceLevel > *other.experienceLevel;
}

Hiker::Hiker(Hiker &&other) noexcept
    : Identity(std::move(other.getName()), std::move(other.getEmail())),
      experienceLevel(other.experienceLevel),
      equipment(std::move(other.equipment))
{
    other.experienceLevel = nullptr;
    other.equipment = nullptr;
}

Hiker::~Hiker()
{
    delete experienceLevel;
    delete equipment;
}

int Hiker::getExperienceLevel() const
{
    return *experienceLevel;
}

Equipment *Hiker::getEquipment() const
{
    return equipment;
}

std::string Hiker::getHikingDifficulty() const
{
    return calculateHikingDifficulty();
}

void Hiker::displayHikerInfo() const
{
    std::cout << "Hiker name: " << getName() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Experience Level: " << *experienceLevel << std::endl;
    std::cout << "Equipment name: " << equipment->getName() << std::endl;
    std::cout << "Equipment price: " << equipment->getPrice() << std::endl;
    std::cout << "Hiking Difficulty: " << calculateHikingDifficulty() << "\n"
              << std::endl;
}

std::string Hiker::calculateHikingDifficulty() const
{
    if (*experienceLevel <= 2)
    {
        return "Beginner";
    }
    else if (*experienceLevel <= 5)
    {
        return "Intermediate";
    }
    else
    {
        return "Advanced";
    }
}
