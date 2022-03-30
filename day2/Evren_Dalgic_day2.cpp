#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int wrappingCalc(int l, int w, int h)
{
    int currentBase = (2 * l * w) + (2 * h * w) + (2 * l * h);
    if (l * w <= w * h && l * w <= h * l)
    {
        return currentBase + (l * w);
    }
    else if (h * w <= w * l && h * w <= h * l)
    {
        return currentBase + (h * w);
    }
    else if (l * h <= w * h && l * h <= l * w)
    {
        return currentBase + (l * h);
    }
    return -1;
    //std::min(std::min(x, y), z);
}
int ribbonCalc(int l, int w, int h)
{
    int bow = l * w * h;
    if (l >= w && l >= h)
    {
        return 2 * w + 2 * h + bow;
    }
    else if (w >= l && w >= h)
    {
        return 2 * l + 2 * h + bow;
    }
    else if (h >= w && h >= l)
    {
        return 2 * w + 2 * l + bow;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    // Read the file and put it into inputFile ifstream object.
    std::ifstream inputFile("input.txt");

    int totalWrap = 0;
    int totalRibbon = 0;

    if (inputFile.is_open())
    {
        // String array for temporarily recording string values of l, w and h
        std::string individualNumbers[3];
        int l = 0, w = 0, h = 0;
        while (true)
        {
            // If inputFile state reaches end of file break the while loop.
            if (inputFile.eof())
            {
                break;
            }

            // Get every line and read until function encounters a 'x' character except the last number because there is no x after the h.
            for (int i = 0; i < 3; i++)
            {
                if (i < 2)
                {
                    std::getline(inputFile, individualNumbers[i], 'x');
                }
                else
                {
                    std::getline(inputFile, individualNumbers[i]);
                }
            }
            // Convert string values to integer values using stoi.
            l = std::stoi(individualNumbers[0]);
            w = std::stoi(individualNumbers[1]);
            h = std::stoi(individualNumbers[2]);

            // std::cout << l << " " << w << " " << h << std::endl;
            // Calculation for part 1 and 2.
            totalWrap += wrappingCalc(l, w, h);
            totalRibbon += ribbonCalc(l, w, h);
        }
    }

    std::cout << "Total Wrap = " << totalWrap << std::endl;
    std::cout << "Total Ribbon = " << totalRibbon << std::endl;

    inputFile.close();

    std::cout << "\n\n";
    system("pause");
    return 0;
}
