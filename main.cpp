//Jessica Venema (mom) is making this for her son so that he can have randomized PvZ1 challenges.

#include <iostream>
#include "pvz1_randomizer.h"

int main() {

    PvZ1_Randomizer randomizer;
    randomizer.randomize();

    std::cout << "Today's challenge:" << std::endl;
    std::cout << "  World: " << PvZ1_Randomizer::worldToString(randomizer.getWorld()) << std::endl;
    std::cout << "  Level: " << static_cast<int>(randomizer.getLevel()) << std::endl;
    std::cout << "  Plant 1: " << PvZ1_Randomizer::plantToString(randomizer.getPlant()) << std::endl;

    return 0;
}