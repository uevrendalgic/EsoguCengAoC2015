#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myInput("Part-1-input.txt");

    string inst;
    int floor = 0;

    getline(myInput, inst);
    myInput.close();

    for (char item : inst)
    {
        if (item == '(')
            floor++;
        else
            floor--;
    }

    cout << floor;
}

// Part 2 Main =>

int main()
{
    ifstream myInput("Part-2-input.txt");

    string inst;
    int floor = 0, i = 0;

    getline(myInput, inst);
    myInput.close();

    for (char item : inst)
    {
        if (item == '(')
            floor++;
        else
            floor--;

        i++;

        if (floor < 0)
            break;
    }

    cout << i;
}