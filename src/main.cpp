#include "hiker_management/hiker.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include "identity_management/utility.hpp"
#include "identity_management/NamedValue.hpp"

int main()
{
    std::vector<Hiker> hikerCollection;

    std::unique_ptr<Equipment> equipment1 = std::make_unique<Equipment>("Helmet", 25.2);
    Hiker hiker1("Adrian", "adrian@student.ro", 4, std::move(equipment1));
    hikerCollection.push_back(hiker1);

    std::unique_ptr<Equipment> equipment2 = std::make_unique<Equipment>("Shoes", 31.1);
    Hiker hiker2("Tudor", "tudor@student.ro", 8, std::move(equipment2));
    hikerCollection.push_back(hiker2);

    std::unique_ptr<Equipment> equipment3 = std::make_unique<Equipment>("Sunglasses", 31.11);
    Hiker hiker3("Albert", "albert@student.ro", 9, std::move(equipment3));
    hikerCollection.push_back(hiker3);

    std::unique_ptr<Equipment> equipment4 = std::make_unique<Equipment>("Backpack", 31.0);
    Hiker hiker4("John", "john@student.ro", 7, std::move(equipment4));
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

    NamedValue<int> hiker1Experience(hiker1.getName(), hiker1.getExperienceLevel());
    NamedValue<int> hiker2Experience(hiker2.getName(), hiker2.getExperienceLevel());
    NamedValue<int> hiker3Experience(hiker3.getName(), hiker3.getExperienceLevel());
    NamedValue<int> hiker4Experience(hiker4.getName(), hiker4.getExperienceLevel());

    std::vector<NamedValue<int>> hikerExperiences = {hiker1Experience, hiker2Experience, hiker3Experience, hiker4Experience};
    NamedValue<double> equipment1Price(hiker1.getEquipment()->getName(), hiker1.getEquipment()->getPrice());

    std::cout << "Highest experience: " << findMax(hikerExperiences).getName() << " " << findMax(hikerExperiences).getValue() << std::endl;

    std::unique_ptr<Equipment> equipmentToMove = std::make_unique<Equipment>("Helmet", 25.2);
    std::cout << "Equipment 1 before losing ownership: " << equipmentToMove << std::endl;
    Hiker newHiker("Adrian", "adrian@student.ro", 4, std::move(equipmentToMove));
    std::cout << "Equipment 1 after: " << equipmentToMove << std::endl;

    if (equipmentToMove == nullptr)
    {
        std::cout << "Equipment 1 lost its ownership" << std::endl;
    }

    return 0;
}
