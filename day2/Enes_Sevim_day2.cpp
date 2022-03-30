#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

void splitx(string a, int length[], int width[], int height[], int* i, int* j, int* k) {
	char c = 'x';
	stringstream(a) >> length[*i] >> c >> width[*j] >> c >> height[*k];
	++* i;
	++* j;
	++* k;
}
int wrappingpaper(int l, int w, int h) {
	int lw = l * w;
	int wh = w * h;
	int hl = h * l;
	int min = 0;
	if (lw < wh && lw < hl)
		min = lw;
	else if (wh < hl)
		min = wh;
	else
		min = hl;
	return 2 * lw + 2 * wh + 2 * hl + min;
}
int ribbon(int l, int w, int h) {
	int lw = l + w;
	int wh = w + h;
	int hl = h + l;
	int min = 0;
	if (lw < wh && lw < hl)
		min = lw;
	else if (wh < hl)
		min = wh;
	else
		min = hl;
	int bow = l * w * h;
	return bow + 2 * min;
}
int main() {

	string inputs;
	fstream newfile;
	int length[1000], width[1000], height[1000];
	int i = 0, j = 0, k = 0;
	int total = 0;
	int feet_of_ribbon = 0;
	newfile.open("input.txt", ios::in);
	if (newfile.is_open()) {
		while (getline(newfile, inputs)) {
			splitx(inputs, length, width, height, &i, &j, &k);
		}
	}
	newfile.close();

	for (int s = 0; s < 1000; s++) {
		total += wrappingpaper(length[s], width[s], height[s]);
	}
	cout << "total square feet of wrapping paper is : " << total << endl;

	for (int s = 0; s < 1000; s++) {
		feet_of_ribbon += ribbon(length[s], width[s], height[s]);
	}
	cout << "total feet of ribbon is : " << feet_of_ribbon << endl;
	cout << endl;
	system("pause");
	return 0;
}