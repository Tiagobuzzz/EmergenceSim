#include "map.hpp"

int main() {
    Map worldMap;
    std::cout << "Mapa emocional de UltraWorld:\n";
    worldMap.printMap();
    worldMap.detectCivilizationBirths();
    return 0;
}
