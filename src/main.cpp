#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>

enum class Emotion { Hope, Fear, Rage, Grief };

struct Cell {
    Emotion emotion;
    std::string symbol;
    int civilizationId = -1;
};

struct Civilization {
    std::string name;
    std::string belief;
    int age = 0;
    bool alive = true;
};

class World {
public:
    World(int w, int h) : width(w), height(h) {
        grid.resize(width * height);
        generateTerrain();
    }

    void step() {
        // aging civilizations
        for (auto& [id, civ] : civilizations) {
            if (civ.alive) {
                civ.age++;
                if (civ.age > 50) {
                    civ.alive = false;
                    std::cout << "Civilization " << civ.name << " has collapsed\n";
                }
            }
        }

        // check for emergence
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                Cell& cell = at(x, y);
                if (cell.civilizationId == -1 && !cell.symbol.empty() && cell.emotion == Emotion::Hope) {
                    createCivilization(x, y);
                }
            }
        }
    }

    void print() const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                const Cell& c = grid[y * width + x];
                if (c.civilizationId != -1) {
                    std::cout << 'C';
                } else {
                    std::cout << '.';
                }
            }
            std::cout << '\n';
        }
    }

private:
    int width, height;
    std::vector<Cell> grid;
    std::map<int, Civilization> civilizations;
    int nextCivId = 0;
    std::mt19937 rng{std::random_device{}()};

    Cell& at(int x, int y) { return grid[y * width + x]; }

    void generateTerrain() {
        std::uniform_int_distribution<int> emotionDist(0, 3);
        std::uniform_int_distribution<int> symbolDist(0, 10);
        for (auto& cell : grid) {
            cell.emotion = static_cast<Emotion>(emotionDist(rng));
            if (symbolDist(rng) == 0) {
                cell.symbol = "ancient stone";
            }
        }
    }

    void createCivilization(int x, int y) {
        int id = nextCivId++;
        Civilization civ;
        civ.name = "Civ" + std::to_string(id);
        civ.belief = "Belief" + std::to_string(id);
        civilizations[id] = civ;
        Cell& cell = at(x, y);
        cell.civilizationId = id;
        std::cout << "New civilization arises at (" << x << "," << y << ") named " << civ.name << "\n";
    }
};

int main() {
    World world(20, 10);
    for (int i = 0; i < 100; ++i) {
        world.step();
    }
    world.print();
    return 0;
}

