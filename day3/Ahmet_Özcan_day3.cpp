#include <iostream>
#include <fstream>
using namespace std;

int neighborhood[300][300];

int main()
{
    ifstream myInput("input.txt");

    string directions;
    int gifts = 0, i = 150, j = 150;
    neighborhood[150][150] = 1;

    getline(myInput, directions);
    myInput.close();

    for (char item : directions)
    {
        if (item == '^')
            i++;
        if (item == '<')
            j--;
        if (item == '>')
            j++;
        if (item == 'v')
            i--;

        neighborhood[i][j]++;
    }

    for (int a = 0; a < 300; a++)
    {
        for (int b = 0; b < 300; b++)
        {
            if (neighborhood[a][b] > 0)
                gifts++;
        }
    }

    cout << gifts;

    return 0;
}

// Part 2 Main =>

int main()
{
    ifstream myInput("input.txt");

    string directions;
    int gifts = 0, i = 150, j = 150, i1 = 150, j1 = 150;
    neighborhood[150][150] = 2;

    getline(myInput, directions);
    myInput.close();

    for (int c = 0; c < 8192; c += 2)
    {
        if (directions[c] == '^')
            i++;
        if (directions[c] == '<')
            j--;
        if (directions[c] == '>')
            j++;
        if (directions[c] == 'v')
            i--;

        neighborhood[i][j]++;
    }

    for (int d = 1; d < 8192; d += 2)
    {
        if (directions[d] == '^')
            i1++;
        if (directions[d] == '<')
            j1--;
        if (directions[d] == '>')
            j1++;
        if (directions[d] == 'v')
            i1--;

        neighborhood[i1][j1]++;
    }

    for (int a = 0; a < 300; a++)
    {
        for (int b = 0; b < 300; b++)
        {
            if (neighborhood[a][b] > 0)
                gifts++;
        }
    }

    cout << gifts;

    return 0;
}