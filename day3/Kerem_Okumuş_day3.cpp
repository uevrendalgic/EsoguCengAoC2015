#include <iostream>
#include <fstream>
#include <string>

int coordinate1[1000][1000];
int coordinate2[1000][1000];

using namespace std;

void algorithm(string input, int* count1, int* count2)
{
	int i = 1;
	int x = 500;
	int x2 = 500;
	int x_rob = 500;
	int y = 500;
	int y2 = 500;
	int y_rob = 500;
	
	for (int a = 0; a < size(input); a++)
	{
		coordinate1[x][y] = 1;
		coordinate2[x2][y2] = 1;
		coordinate2[x_rob][y_rob] = 1;

		if (input[a] == '^')
		{
			if (a % 2 == 0)
			{
				y++;
				y2++;
			}
			else
			{
				y++;
			}
		}
		else if (input[a] == '<')
		{
			if (a % 2 == 0)
			{
				x--;
				x2--;
			}
			else
			{
				x--;
			}
		}
		else if (input[a] == '>')
		{
			if (a % 2 == 0)
			{
				x++;
				x2++;
			}
			else
			{
				x++;
			}
		}
		else
		{
			if (a % 2 == 0)
			{
				y--;
				y2--;
			}
			else
			{
				y--;
			}
		}

		if (i < size(input))
		{
			if (input[i] == '^')
			{
				y_rob++;
			}
			else if (input[i] == '<')
			{
				x_rob--;
			}
			else if (input[i] == '>')
			{
				x_rob++;
			}
			else
			{
				y_rob--;
			}
			i = i + 2;
		}
	}

	for (int a = 0; a < 1000; a++)
	{
		for (int b = 0; b < 1000; b++)
		{
			if (coordinate1[a][b] == 1)
			{
				(*count1)++;
			}

			if (coordinate2[a][b] == 1)
			{
				(*count2)++;
			}
		}
	}

}

int main()
{
	string input;
	fstream file;
	int count1 = 0;
	int count2 = 0;

	file.open("input3.txt");

	getline(file, input);

	algorithm(input, &count1, &count2);

	cout << "Part One Result: " << count1 << endl;
	cout << "Part Two Result: " << count2 << endl;
	return 0;
}