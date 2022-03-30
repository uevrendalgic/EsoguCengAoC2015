#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void algorithm(string input, int* time, int* floor)
{
	bool is_saved = false;
	int time_save = 0;
	for (int i = 0; i < size(input); i++)
	{
		if (input[i] == '(')
		{
			(*floor)++;
			time_save++;
		}
		else if (input[i] == ')')
		{
			(*floor)--;
			time_save++;
			if (*floor == -1 && is_saved == false)
			{
				*time = time_save;
				is_saved = true;
			}
		}
	}
}

int main()
{
	int time;
	int floor = 0;
	fstream file;
	string input;

	file.open("input.txt");

	getline(file, input);

	algorithm(input, &time, &floor);
	cout << "Floor: " << floor << endl;
	cout << "Position: " << time << endl;

	return 0;
}
