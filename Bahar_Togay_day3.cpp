#include <iostream>
#include <fstream>
#define ROW 300
#define COL 300
using namespace std;

int main()
{
	ifstream file("/Users/tr/Desktop/advent_of_code/2015/2015day3/input.txt");
	char check;
	int arr[ROW][COL] = {0};
	int santa_counter = 0;
	int control = 3;
	int s_row = 150, s_col = 150;
	int s_s_row = 150, s_s_col = 150;

	while (1)
	{
		file >> check;
		if (!file)
		{
			break;
		}
		else if (check == '^')
		{
			if (control % 2 == 0)
			{
				s_s_row++;
				arr[s_s_row][s_s_col] += 1;
				control++;
			}
			else if(control % 2 != 0)
			{
				s_row++;
				arr[s_row][s_col] += 1;
				control++;
			}
		}
		else if (check == '>')
		{
			if (control % 2 == 0)
			{
				s_s_col++;
				arr[s_s_row][s_s_col] += 1;
				control++;
			}
			else if(control % 2 != 0)
			{
				s_col++;
				arr[s_row][s_col] += 1;
				control++;
			}
		}
		else if (check == '<')
		{
			if (control % 2 == 0)
			{
				s_s_col--;
				arr[s_s_row][s_s_col] += 1;
				control++;
			}
			else if(control % 2 != 0)
			{
				s_col--;
				arr[s_row][s_col] += 1;
				control++;
			}
		}
		else if (check == 'v')
		{
			if (control % 2 == 0)
			{
				s_s_row--;
				arr[s_s_row][s_s_col] += 1;
				control++;
			}
			else if(control % 2 != 0)
			{
				s_row--;
				arr[s_row][s_col] += 1;
				control++;
			}
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] > 0)
			{
				santa_counter++;
			}
		}
	}
	cout << santa_counter<< "\n";

	system("pause");
	return 0;
}
