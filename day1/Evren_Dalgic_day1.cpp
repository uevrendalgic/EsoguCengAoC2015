#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::ifstream Input("input.txt");
    std::string tempText;

    int floor = 0;
    int charPos = 0;
    int finalCharPos = 0;
    bool basementFlag = true;

    char ch;
    while (1)
    {
        Input >> ch;
        if (Input.eof())
        {
            break;
        }
        if (ch == '(')
        {
            floor++;
            charPos++;
        }
        else
        {
            floor--;
            charPos++;
        }
        if (floor < 0 && basementFlag)
        {
            basementFlag = false;
            finalCharPos = charPos;
        }
    }

    std::cout << "Final floor number = " << floor << std::endl;
    std::cout << "First basement char index = " << finalCharPos << std::endl;

    Input.close();
    std::cout << "\n\n";
    system("pause");
    return 0;
}
