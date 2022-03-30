#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string directions;
	int length = 0,floor=0,ctrl=0;
	fstream newfile;
	newfile.open("input.txt", ios::in);
	if (newfile.is_open()) {
		while (getline(newfile, directions)) {
		}
	}
	newfile.close();
	length = directions.length();
	
	for (int i = 0; i < length; i++) {
		if (directions[i] == '(')
			floor++;
		else
			floor--;
		if (floor == -1 && ctrl == 0) {
			cout << i + 1 << " is the position of causes him to enter basement" << endl; // i+1 because positions starts from 1 
			ctrl = 1; // not repeat the same progress
		}
	}
	cout <<"final position is : "<< floor << endl;


	system("pause");
	return 0;
}