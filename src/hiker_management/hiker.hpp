#ifndef HIKER_HPP
#define HIKER_HPP
#include "../identity_management/identity.hpp"
#include "../equipment_management/equipment.hpp"
#include "ihiker.hpp"

#include <string>

class Hiker : public identity::Identity, public IHiker
{
public:
    Hiker(const std::string &name, const std::string &email, int experienceLevel, const Equipment &equipment);

    Hiker(const Hiker &other);

    Hiker &operator=(const Hiker &other);

    bool operator>(const Hiker &other) const;

    Hiker(Hiker &&other) noexcept;

    ~Hiker();

    int getExperienceLevel() const override;
    std::string getHikingDifficulty() const override;
    Equipment *getEquipment() const override;
    void displayHikerInfo() const override;

private:
    int *experienceLevel;
    Equipment *equipment;

    std::string calculateHikingDifficulty() const;
};

#endif
