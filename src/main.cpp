#include "hiker.hpp"

int main()
{
    Hiker hiker1("Adrian", "adrian@student.ro", 4);
    Hiker hiker2("Tudor", "tudor@student.ro", 2);

    Hiker hiker3 = hiker1;

    Hiker hiker4("Albert", "albert@student.ro", 5);
    hiker4 = hiker2;

    hiker1.displayHikerInfo();
    hiker2.displayHikerInfo();
    hiker3.displayHikerInfo();
    hiker4.displayHikerInfo();

    return 0;
}
