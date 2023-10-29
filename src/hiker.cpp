#include "hiker.hpp"
#include <iostream>

Hiker::Hiker(const std::string &name, const std::string &email, int experienceLevel, const std::string &equipment)
    : name(new std::string(name)),
      email(new std::string(email)),
      experienceLevel(new int(experienceLevel)),
      equipment(new std::string(equipment))
{
}

Hiker::Hiker(const Hiker &other)
    : name(new std::string(*(other.name))),
      email(new std::string(*(other.email))),
      experienceLevel(new int(*(other.experienceLevel))),
      equipment(new std::string(*(other.equipment)))
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
            *equipment = *equipment + " " + *other.equipment;
        }
        else
        {
            equipment = new std::string(*(other.equipment));
        }
    }

    std::cout << *this->name << " got the equipment " << *other.equipment << " from " << *other.name << std::endl;

    return *this;
}

Hiker::~Hiker()
{
    delete name;
    delete email;
    delete experienceLevel;
    delete equipment;
}

std::string Hiker::getName() const
{
    return *name;
}

std::string Hiker::getEmail() const
{
    return *email;
}

int Hiker::getExperienceLevel() const
{
    return *experienceLevel;
}

std::string Hiker::getEquipment() const
{
    return *equipment;
}

std::string Hiker::getHikingDifficulty() const
{
    return calculateHikingDifficulty();
}

void Hiker::displayHikerInfo() const
{
    std::cout << "Name: " << *name << std::endl;
    std::cout << "Email: " << *email << std::endl;
    std::cout << "Experience Level: " << *experienceLevel << std::endl;
    std::cout << "Equipment: " << *equipment << std::endl;
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
