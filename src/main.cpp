#include "hiker_management/hiker.hpp"
#include <iostream>
#include <vector>
#include "utility.hpp"
#include "genericitem.hpp"

int main()
{
    std::vector<Hiker> hikerCollection;

    Hiker hiker1("Adrian", "adrian@student.ro", 4, Equipment("Helmet", 25.2));
    hikerCollection.push_back(hiker1);

    Hiker hiker2("Tudor", "tudor@student.ro", 8, Equipment("Shoes", 31.1));
    hikerCollection.push_back(hiker2);

    Hiker hiker3("Albert", "albert@student.ro", 5, Equipment("Sunglasses", 30.5));
    hikerCollection.push_back(hiker3);

    Hiker hiker4("John", "john@student.ro", 3, Equipment("Backpack", 31.0));
    hikerCollection.push_back(hiker4);

    for (const Hiker &hiker : hikerCollection)
    {
        hiker.displayHikerInfo();
    }

    std::vector<Equipment> equipmentCollection = {
        *hiker1.getEquipment(),
        *hiker2.getEquipment(),
        *hiker3.getEquipment(),
        *hiker4.getEquipment(),
    };

    try
    {
        Equipment mostExpensiveEquipment = findMax(equipmentCollection);
        std::cout << "Most Expensive Equipment: " << mostExpensiveEquipment.getName() << " (Price: $" << mostExpensiveEquipment.getPrice() << ")" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    GenericItem<int> hiker1Experience(hiker1.getName(), hiker1.getExperienceLevel());
    GenericItem<int> hiker2Experience(hiker2.getName(), hiker2.getExperienceLevel());
    GenericItem<int> hiker3Experience(hiker3.getName(), hiker3.getExperienceLevel());
    GenericItem<int> hiker4Experience(hiker4.getName(), hiker4.getExperienceLevel());

    std::vector<GenericItem<int>> hikerExperiences = {hiker1Experience, hiker2Experience, hiker3Experience, hiker4Experience};
    GenericItem<double> equipment1Price(hiker1.getEquipment()->getName(), hiker1.getEquipment()->getPrice());

    std::cout << "Highest experience: " << findMax(hikerExperiences).getName() << " " << findMax(hikerExperiences).getValue() << std::endl;

    return 0;
}
