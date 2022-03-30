#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

struct position
{
    int x;
    int y;
};

void findDuplicate(struct position &coord, std::vector<position> &houses)
{
    bool duplicateFlag = false;
    for (int i = 0; i < houses.size(); i++)
    {
        if (duplicateFlag == false && coord.x == houses[i].x && coord.y == houses[i].y)
        {
            duplicateFlag = true;
        }
    }
    if (duplicateFlag == false)
    {
        houses.insert(houses.end(), coord);
    }
}

void addPoint(struct position &coord, std::vector<position> &houses, char direction)
{
    if (direction == UP)
    {
        coord.y++;
    }
    else if (direction == DOWN)
    {
        coord.y--;
    }
    else if (direction == LEFT)
    {
        coord.x--;
    }
    else if (direction == RIGHT)
    {
        coord.x++;
    }
    findDuplicate(coord, houses);
}

int main(int argc, char const *argv[])
{
    std::ifstream inputText("input.txt");
    std::string line;

    std::getline(inputText, line);

    struct position santa = {0, 0};
    struct position roboSanta= {0, 0};
    std::vector<position> houses;

    for (int i = 0, j = 1; i < line.length(), j < line.length(); i += 2, j += 2)
    {
        addPoint(santa, houses, line[i]);
        addPoint(roboSanta, houses, line[j]);
    }

    std::cout << houses.size() << std::endl;

    std::cout << "\n\n";
    system("pause");
    return 0;
}
