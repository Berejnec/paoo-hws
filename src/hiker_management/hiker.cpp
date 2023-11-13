#include "hiker.hpp"
#include <memory>
#include <iostream>

Hiker::Hiker(const std::string &name, const std::string &email, int experienceLevel, std::shared_ptr<std::string> drinkBottle, std::unique_ptr<Equipment> equipment)
    : identity::Identity(name, email), experienceLevel(new int(experienceLevel)), drinkBottle(std::move(drinkBottle)), equipment(std::move(equipment))
{
}

Hiker::Hiker(const Hiker &other)
    : Identity(other.getName(), other.getEmail()),
      experienceLevel(new int(*(other.experienceLevel))),
      drinkBottle(std::shared_ptr<std::string>(other.drinkBottle)),
      equipment(std::make_unique<Equipment>(*(other.equipment)))
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
            equipment = std::make_unique<Equipment>(equipment->getName() + " " + other.equipment->getName(), equipment->getPrice());
        }
        else
        {
            equipment = std::make_unique<Equipment>(*other.equipment);
        }
    }
    else
    {
        equipment.reset();
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
}

int Hiker::getExperienceLevel() const
{
    return *experienceLevel;
}

std::unique_ptr<Equipment> Hiker::getEquipment() const
{
    return std::make_unique<Equipment>(*equipment);
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

std::shared_ptr<std::string> Hiker::getDrinkBottle() const
{
    return std::shared_ptr<std::string>(drinkBottle);
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

void Hiker::setExperienceLevel(int level)
{
    *experienceLevel = level;
}

void Hiker::setEquipment(std::unique_ptr<Equipment> newEquipment)
{
    equipment = std::move(newEquipment);
}
