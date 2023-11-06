#include "hiker.hpp"
#include <iostream>

int main()
{
    Hiker hiker1("Adrian", "adrian@student.ro", 4, "Helmet");
    Hiker hiker2("Tudor", "tudor@student.ro", 2, "Shoes");

    Hiker hiker3(hiker1);

    Hiker hiker4("Albert", "albert@student.ro", 5, "Sunglasses");

    hiker1.displayHikerInfo();
    hiker2.displayHikerInfo();
    hiker3.displayHikerInfo();
    hiker4.displayHikerInfo();

    hiker4 = hiker2;
    hiker4 = hiker1;

    hiker4.displayHikerInfo();

    Hiker hiker5("John", "john@student.ro", 3, "Backpack");
    Hiker hiker6(std::move(hiker5));
    hiker6.displayHikerInfo();

    return 0;
}
