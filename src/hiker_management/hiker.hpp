#ifndef HIKER_HPP
#define HIKER_HPP
#include "../identity_management/identity.hpp"
#include "../equipment_management/equipment.hpp"
#include "ihiker.hpp"
#include <memory>

#include <string>

class Hiker : public identity::Identity, public IHiker
{
public:
    Hiker(const std::string &name, const std::string &email, int experienceLevel, std::shared_ptr<std::string> drinkBottle, std::unique_ptr<Equipment> equipment);

    Hiker(const Hiker &other);

    Hiker &operator=(const Hiker &other);

    bool operator>(const Hiker &other) const;

    Hiker(Hiker &&other) noexcept;

    ~Hiker();

    int getExperienceLevel() const override;
    std::string getHikingDifficulty() const override;
    std::unique_ptr<Equipment> getEquipment() const override;
    void displayHikerInfo() const override;
    std::shared_ptr<std::string> getDrinkBottle() const override;

    // setters
    void setExperienceLevel(int level);
    void setEquipment(std::unique_ptr<Equipment> newEquipment);

private:
    int *experienceLevel;
    std::unique_ptr<Equipment> equipment;
    std::shared_ptr<std::string> drinkBottle;

    std::string calculateHikingDifficulty() const;
};

#endif
