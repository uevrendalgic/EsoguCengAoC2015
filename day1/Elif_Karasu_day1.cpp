#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("input.txt");

	int floor = 0;
	string a;

	if (infile.is_open())
	{
		while (getline(infile, a))
		{

		}
		infile.close();
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(')
		{
			floor++;
		}
		else if (a[i] == ')')
		{
			floor--;
			if (floor == -1)
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}

	system("pause");
}