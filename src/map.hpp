#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

extern std::vector<std::string> emotions;
extern std::vector<std::string> symbols;

struct Cell {
    std::string emotion;
    std::string symbol;
    bool hasCivilization = false;
};

class Map {
public:
    Cell grid[MAP_HEIGHT][MAP_WIDTH];

    Map();

    void generateMap();
    void printMap() const;
    void detectCivilizationBirths();
};

#endif // MAP_HPP
