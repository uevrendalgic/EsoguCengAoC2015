#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void calculate(int lengthsFunc[])
{
    int side1 = lengthsFunc[0] * 2 * lengthsFunc[1];
    int side2 = lengthsFunc[0] * 2 * lengthsFunc[2];
    int side3 = lengthsFunc[1] * 2 * lengthsFunc[2];

    lengthsFunc[3] += side1 + side2 + side3;

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (lengthsFunc[i] > lengthsFunc[j])
                swap(lengthsFunc[i], lengthsFunc[j]);
        }
    }

    lengthsFunc[3] += lengthsFunc[0] * lengthsFunc[1];
}

int main()
{
    string line;
    int lengths[4] = {0, 0, 0, 0};

    ifstream myInput("input.txt");

    while (getline(myInput, line))
    {
        stringstream ss(line);
        for (int j = 0, i; ss >> i; j++)
        {
            lengths[j] = i;
            if (ss.peek() == 'x')
                ss.ignore();
            if (j == 2)
            {
                j = -1;
                calculate(lengths);
            }
        }
    }
    myInput.close();

    cout << lengths[3];
}

// Part 2 Main =>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void calculate(int lengthsFunc[])
{
    int side1 = lengthsFunc[0] * lengthsFunc[2] * lengthsFunc[1];

    lengthsFunc[3] += side1;

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (lengthsFunc[i] > lengthsFunc[j])
                swap(lengthsFunc[i], lengthsFunc[j]);
        }
    }

    lengthsFunc[3] += (lengthsFunc[0] * 2) + (2 * lengthsFunc[1]);
}

int main()
{
    string line;
    int lengths[4] = {0, 0, 0, 0};

    ifstream myInput("input.txt");

    while (getline(myInput, line))
    {
        stringstream ss(line);
        for (int j = 0, i; ss >> i; j++)
        {
            lengths[j] = i;
            if (ss.peek() == 'x')
                ss.ignore();
            if (j == 2)
            {
                j = -1;
                calculate(lengths);
            }
        }
    }
    myInput.close();

    cout << lengths[3];
}