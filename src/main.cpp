#include "map.hpp"

void runSimulation(int turns) {
    Map worldMap;
    std::cout << "Mapa emocional de UltraWorld:\n";
    worldMap.printMap();

    for (int t = 1; t <= turns; ++t) {
        std::cout << "\n--- Turno " << t << " ---\n";
        worldMap.detectCivilizationBirths();
        worldMap.ageCivilizations();
    }
}

int main() {
    runSimulation(10);
    return 0;
}
