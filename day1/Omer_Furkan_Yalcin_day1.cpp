#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int floor = 0, check = 0, first_time;
    fstream file;
    file.open("q1.txt", ios::in);
    if (file.is_open())
    {
        string line;
        getline(file, line);
        for (int i = 0; i < line.size() - 1; i++)
        {
            if (line[i] == '(')
            {
                floor++;
            }
            else if (line[i] == ')')
            {
                floor--;
            }
            if (floor == -1 && check == 0)
                check = 1, first_time = i + 1;
        }
    }
    cout << floor << endl;
    cout << first_time << endl;
}