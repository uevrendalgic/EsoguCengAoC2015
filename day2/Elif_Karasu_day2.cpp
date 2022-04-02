#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("inputday2.txt");

	int maxo = 0, paper = 0, ribbon = 0;
	int l = 0, w = 0, h = 0;

	string a;

	while (infile)
	{
		if (infile.eof())
		{
			break;
		}

		getline(infile, a, 'x');
		l = stoi(a);
		getline(infile, a, 'x');
		w = stoi(a);
		getline(infile, a, '\n');
		h = stoi(a);
		
		maxo = max(max(l, w), h);
		if (maxo == l)
		{
			paper = paper + 2 * l * w + 2 * w * h + 2 * h * l + w * h;
			ribbon = ribbon + 2 * w + 2 * h + l * w * h;
		}
		else if (maxo == w)
		{
			paper = paper + 2 * l * w + 2 * w * h + 2 * h * l + l * h;
			ribbon = ribbon + 2 * l + 2 * h + l * w * h;
		}
		else if (maxo == h)
		{
			paper = paper + 2 * l * w + 2 * w * h + 2 * h * l + w * l;
			ribbon = ribbon + 2 * l + 2 * w + l * w * h;
		}		
	}

	infile.close();
	
	cout << paper << endl;
	cout << ribbon << endl;

	system("pause");
}
