#include <iostream>
#include "md5.h"

int main(int argc, char const *argv[])
{
    MD5 md5;
    std::string key = "ckczppom";
    unsigned int ender = 0;

    std::string myHash;
    while (1)
    {
        myHash = md5(key + std::to_string(ender));
        if (myHash.substr(0, 6) == "000000")
        {
            break;
        }

        ender++;
    }
    std::cout << myHash << std::endl;
    std::cout << ender << std::endl;

    std::cout << "\n\n";
    system("pause");
    return 0;
}
