#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Dimensões do mapa (colunas x linhas)
const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;

// Idade limite para colapso de uma civilização
const int CIV_COLLAPSE_AGE = 5;
// Idade mínima para expansão de uma civilização
const int CIV_EXPANSION_AGE = 2;

extern std::vector<std::string> emotions;
extern std::vector<std::string> symbols;

struct Cell {
    std::string emotion;
    std::string symbol;
    bool hasCivilization = false;
    int age = 0;
};

class Map {
public:
    Cell grid[MAP_HEIGHT][MAP_WIDTH];

    Map();

    void generateMap();
    void printMap() const;
    void detectCivilizationBirths();
    void ageCivilizations();
    void expandCivilizations();
};

#endif // MAP_HPP
