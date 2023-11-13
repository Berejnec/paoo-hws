#ifndef IHIKER_HPP
#define IHIKER_HPP

#include <memory>
#include <iostream>

class IHiker
{
public:
    virtual ~IHiker() = default;

    virtual int getExperienceLevel() const = 0;
    virtual std::unique_ptr<Equipment> getEquipment() const = 0;
    virtual std::shared_ptr<std::string> getDrinkBottle() const = 0;
    virtual std::string getHikingDifficulty() const = 0;
    virtual void displayHikerInfo() const = 0;
};

#endif
