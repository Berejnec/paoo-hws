#ifndef HIKER_HPP
#define HIKER_HPP

#include <string>

class Hiker
{
public:
    Hiker(const std::string &name, const std::string &email, int experienceLevel);

    Hiker(const Hiker &other);

    Hiker &operator=(const Hiker &other);

    ~Hiker();

    std::string getName() const;
    std::string getEmail() const;
    int getExperienceLevel() const;
    std::string getHikingDifficulty() const;
    void displayHikerInfo() const;

private:
    std::string *name;
    std::string *email;
    int *experienceLevel;

    std::string calculateHikingDifficulty() const;
};

#endif
