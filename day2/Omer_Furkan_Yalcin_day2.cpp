#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file;
    long long int result = 0;
    file.open("q2.txt", ios::in);
    if (file.is_open())
    {

        int count = 0;
        int l, w, h;
        string line;
        string number;
        while (getline(file, line))
        {
            number = "";
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == 'x')
                {
                    count++;
                    number = "";
                }
                else
                {
                    number += line[i];
                    if (count == 0)
                        l = stoi(number);
                    else if (count == 1)
                        w = stoi(number);
                    else if (count == 2)
                        h = stoi(number);
                }
            }
            count = 0;
            int biggest = l;
            int smallest, secondSmallest;
            if (w > biggest)
                biggest = w;
            if (h > biggest)
                biggest = h;
            if (biggest == l)
                smallest = w, secondSmallest = h;
            else if (biggest == w)
                smallest = l, secondSmallest = h;
            else
                smallest = l, secondSmallest = w;
            // part1
            //  result += 2 * l * w + 2 * w * h + 2 * h * l + smallest * secondSmallest;
            // part2
            result += 2 * (smallest + secondSmallest) + l * w * h;
        }
        file.close();
    }
    cout << result << endl;
}