#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string directions;
	int i = 1, j = 1;
	int santa_x = 0;
	int robo_santa_x = 0;
	int robo_santa_y = 0;
	int santa_y = 0;
	int santa_xb[8193];
	int santa_yb[8193];
	int present = 1, length = 0, ctrl = 0;
	fstream newfile;
	newfile.open("input.txt", ios::in);
	if (newfile.is_open()) {
		while (getline(newfile, directions)) {
		}
	}
	newfile.close();
	length = directions.length();
	santa_xb[0] = 0;
	santa_yb[0] = 0;
	for (int k = 0; k < length; k++) {
		if (directions[k] == '^') {
			if (k % 2 == 0) {
				santa_y++;
				for (int l = 0; l < k; l++) {
					if (santa_x == santa_xb[l] && santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = santa_x;
				santa_yb[i++] = santa_y;
			}
			else {
				robo_santa_y++;
				for (int l = 0; l < k; l++) {
					if (robo_santa_x == santa_xb[l] && robo_santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = robo_santa_x;
				santa_yb[i++] = robo_santa_y;
			}
		}
		else if (directions[k] == 'v') {
			if (k % 2 == 0) {
				santa_y--;
				for (int l = 0; l < k; l++) {
					if (santa_x == santa_xb[l] && santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = santa_x;
				santa_yb[i++] = santa_y;
			}
			else {
				robo_santa_y--;
				for (int l = 0; l < k; l++) {
					if (robo_santa_x == santa_xb[l] && robo_santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = robo_santa_x;
				santa_yb[i++] = robo_santa_y;
			}
		}
		else if (directions[k] == '>') {
			if (k % 2 == 0) {
				santa_x++;
				for (int l = 0; l < k; l++) {
					if (santa_x == santa_xb[l] && santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = santa_x;
				santa_yb[i++] = santa_y;
			}
			else {
				robo_santa_x++;
				for (int l = 0; l < k; l++) {
					if (robo_santa_x == santa_xb[l] && robo_santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = robo_santa_x;
				santa_yb[i++] = robo_santa_y;
			}
		}
		else if (directions[k] == '<') {
			if (k % 2 == 0) {
				santa_x--;
				for (int l = 0; l < k; l++) {
					if (santa_x == santa_xb[l] && santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = santa_x;
				santa_yb[i++] = santa_y;
			}
			else {
				robo_santa_x--;
				for (int l = 0; l < k; l++) {
					if (robo_santa_x == santa_xb[l] && robo_santa_y == santa_yb[l]) {
						ctrl = 1;
					}
				}
				if (ctrl == 0) {
					present++;
				}
				ctrl = 0;
				santa_xb[j++] = robo_santa_x;
				santa_yb[i++] = robo_santa_y;
			}
		}
	}
	cout << "present number is : " << present << endl;
	cout << endl;
	system("pause");
	return 0;
}