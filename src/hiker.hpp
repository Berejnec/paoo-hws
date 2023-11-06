#ifndef HIKER_HPP
#define HIKER_HPP
#include "identity.hpp"
#include "ihiker.hpp"

#include <string>

class Hiker : public identity::Identity, public IHiker
{
public:
    Hiker(const std::string &name, const std::string &email, int experienceLevel, const std::string &equipment);

    Hiker(const Hiker &other);

    Hiker &operator=(const Hiker &other);

    Hiker(Hiker &&other) noexcept;

    ~Hiker();

    int getExperienceLevel() const override;
    std::string getHikingDifficulty() const override;
    std::string getEquipment() const override;
    void displayHikerInfo() const override;

private:
    int *experienceLevel;
    std::string *equipment;

    std::string calculateHikingDifficulty() const;
};

#endif
