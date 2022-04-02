#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int board[300][300];
int i = 150, j = 150;
int main()
{
    int count = 0;
    string line;
    fstream file;
    file.open("q3.txt", ios::in);
    getline(file, line);
    file.close();
    ///////////////////////////////////////////////////////////
    // for (int ae = 0; ae < line.size(); ae++)
    // {
    //     if (line[ae] == '^')
    //         i++;
    //     else if (line[ae] == 'v')
    //         i--;
    //     else if (line[ae] == '>')
    //         j++;
    //     else
    //         j--;
    //     board[i][j]++;
    // }
    ///////////////////////////////////////////////////////////
    for (int ae = 0; ae < line.size(); ae = ae + 2)
    {
        if (line[ae] == '^')
            i++;
        else if (line[ae] == 'v')
            i--;
        else if (line[ae] == '>')
            j++;
        else
            j--;
        board[i][j]++;
    }
    i = 150, j = 150;
    for (int ae = 1; ae < line.size(); ae = ae + 2)
    {
        if (line[ae] == '^')
            i++;
        else if (line[ae] == 'v')
            i--;
        else if (line[ae] == '>')
            j++;
        else
            j--;
        board[i][j]++;
    }
    ///////////////////////////////////////////////////////////
    for (i = 0; i < 300; i++)
    {
        j = 0;
        for (j = 0; j < 300; j++)
        {
            if (board[i][j] > 0)
                count++;
        }
    }
    cout << count << endl;
    return 0;
}