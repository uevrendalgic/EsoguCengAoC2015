#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("input.txt");

	int floor = 0, control_boi = 0;	
	string a;
	
	if (infile.is_open())
	{
		while (getline(infile,a))
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
			if (floor == -1 && control_boi == 0)
			{
				control_boi = 1;
				cout << "First position to reach -1: " << i + 1 << endl;
			}
		}		
	}
	
	cout << floor << endl;

	system("pause");
}