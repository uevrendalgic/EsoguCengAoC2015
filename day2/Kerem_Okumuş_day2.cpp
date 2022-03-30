#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void algor(string input, int* paper, int* ribbon)
{
	int smol_first_part;
	int smol_second_part;
	int a = 0;
	string numbers[3];
	string number = "";

	for (auto x : input)
	{
		if (x == 'x')
		{
			numbers[a] = number;
			number = "";
			a++;
		}

		else
		{
			number = number + x;
		}
	}

	numbers[a] = number;

	int num0 = stoi(numbers[0]);
	int num1 = stoi(numbers[1]);
	int num2 = stoi(numbers[2]);

	int area = 2 * num0 * num1 + 2 * num0 * num2 + 2 * num1 * num2;

	int multiply = num0 * num1 * num2;

	if (num0 * num1 <= num0 * num2 && num0 * num1 <= num1 * num2)
	{
		smol_first_part = num0 * num1;
		smol_second_part = num0 + num1;
	}
	else if (num0 * num2 <= num0 * num1 && num0 * num2 <= num1 * num2)
	{
		smol_first_part = num0 * num2;
		smol_second_part = num0 + num2;
	}
	else if (num1 * num2 <= num0 * num1 && num1 * num2 <= num0 * num2)
	{
		smol_first_part = num1 * num2;
		smol_second_part = num1 + num2;
	}

	*paper = smol_first_part + area;
	*ribbon = 2 * smol_second_part + multiply;
}

int main()
{
	fstream file;
	string input;
	int final_paper = 0;
	int final_ribbon = 0;
	int paper;
	int ribbon;

	file.open("input2.txt");

	for (int i = 0; i < 1000; i++)
	{
		getline(file, input);
		algor(input, &paper, &ribbon);
		final_paper = final_paper + paper;
		final_ribbon = final_ribbon + ribbon;
	}

	cout << "Paper: " << final_paper << endl;
	cout << "Ribbon: " << final_ribbon << endl;

	return 0;
}