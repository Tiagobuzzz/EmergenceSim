#include "map.hpp"

std::vector<std::string> emotions = {
    "Esperança", "Luto", "Medo", "Raiva", "Euforia", "Silêncio"
};

std::vector<std::string> symbols = {
    "Pedra Rachada", "Som Perdido", "Ruína Queimada", "Nome Apagado", "Estátua Chorada"
};

Map::Map() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    generateMap();
}

void Map::generateMap() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            grid[y][x].emotion = emotions[std::rand() % emotions.size()];
            grid[y][x].symbol = symbols[std::rand() % symbols.size()];
            grid[y][x].hasCivilization = false;
        }
    }
}

void Map::printMap() const {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            std::cout << "[" << grid[y][x].emotion << " | " << grid[y][x].symbol << "] ";
        }
        std::cout << "\n";
    }
}

void Map::detectCivilizationBirths() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            Cell& cell = grid[y][x];
            if (!cell.hasCivilization && cell.emotion == "Luto" && cell.symbol == "Nome Apagado") {
                cell.hasCivilization = true;
                cell.age = 0;
                std::cout << "Nasce uma civilização em (" << x << "," << y << ")\n";
            }
        }
    }
}

void Map::ageCivilizations() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            Cell& cell = grid[y][x];
            if (cell.hasCivilization) {
                cell.age++;
                if (cell.age > CIV_COLLAPSE_AGE) {
                    cell.hasCivilization = false;
                    cell.age = 0;
                    std::cout << "Civilização colapsa em (" << x << "," << y << ")\n";
                }
            }
        }
    }
}

void Map::expandCivilizations() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            Cell& cell = grid[y][x];
            if (cell.hasCivilization && cell.age >= CIV_EXPANSION_AGE) {
                int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
                // try to find an empty adjacent cell
                for (auto& d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (nx >=0 && nx < MAP_WIDTH && ny >=0 && ny < MAP_HEIGHT) {
                        Cell& neighbor = grid[ny][nx];
                        if (!neighbor.hasCivilization) {
                            neighbor.hasCivilization = true;
                            neighbor.age = 0;
                            std::cout << "Civilização se expande para (" << nx << "," << ny << ")\n";
                            break;
                        }
                    }
                }
            }
        }
    }
}
