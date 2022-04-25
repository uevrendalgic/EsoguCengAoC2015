#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("inputday3.txt");

	int field[300][300];	
	int currentx = 150, currenty = 150;
	int evilcurrentx = 150, evilcurrenty = 150;
	int presentCounter = 0;
	field[currenty][currentx] = 1;
	
	string a;

	while (infile)
	{
		if (infile.eof())
		{
			break;
		}
		
		getline(infile, a);

	}

	infile.close();

	for (int i = 0; i < a.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (a[i] == '<')
			{
				currentx++;
				field[currenty][currentx] = 1;
			}
			else if (a[i] == '>')
			{
				currentx--;
				field[currenty][currentx] = 1;
			}
			else if (a[i] == '^')
			{
				currenty++;
				field[currenty][currentx] = 1;
			}
			else if (a[i] == 'v')
			{
				currenty--;
				field[currenty][currentx] = 1;
			}
		}

		else
		{
			if (a[i] == '<')
			{
				evilcurrentx++;
				field[evilcurrenty][evilcurrentx] = 1;
			}
			else if (a[i] == '>')
			{
				evilcurrentx--;
				field[evilcurrenty][evilcurrentx] = 1;
			}
			else if (a[i] == '^')
			{
				evilcurrenty++;
				field[evilcurrenty][evilcurrentx] = 1;
			}
			else if (a[i] == 'v')
			{
				evilcurrenty--;
				field[evilcurrenty][evilcurrentx] = 1;
			}
		}	
	}

	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			if (field[i][j] == 1)
			{
				presentCounter++;
			}
		}
	}

	cout << presentCounter << endl;

	system("pause");
}