#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int calculate(int l, int w, int h) {
	int answer = 2 * l * w + 2 * w * h + 2 * l * h;
	int min = l * w;
	if (w * h < min) {
		min = w * h;
	}
	if (l * h < min) {
		min = l * h;
	}
	return answer + min;
}

int feet_of_ribbon(int l,int w,int h){
	int anstwo = 0;
	int max = l;
	if (w > max) {
		max = w;
	}
	if (h > max) {
		max = h;
	}

	if (max == l) {
		anstwo = (2 * w) + (2 * h) + (l * w * h);
	}
	if (max == w) {
		anstwo = (2 * l) + (2 * h) + (l * w * h);
	}
	if (max == h) {
		anstwo = (2 * w) + (2 * l) + (l * w * h);
	}
	return anstwo;
}
int main() {
	fstream file("/Users/tr/Desktop/advent_of_code/2015day2/input.txt");
	int l = 0, w = 0, h = 0, answer = 0, anstwo = 0;;

	while (file) {
		if (file.eof()) {
			break;
		}
		else {
			string line;
			getline(file, line, 'x');
			l = stoi(line);
			getline(file, line, 'x');
			w = stoi(line);
			getline(file, line, '\n');
			h = stoi(line);

			cout << l << " " << w << " " << h << endl;

			answer += calculate(l, w, h);
			anstwo += feet_of_ribbon(l, w, h);
		}
	}
	
	cout << answer << endl;
	cout << anstwo << endl;


	file.close();
	system("pause");
	return 0;
}
