#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream file("/Users/tr/Desktop/advent_of_code/2015day1/input.txt");
	char check;
	int result = 0,counter=0;
	while (1) {
		file >> check;
		if (!file) {
			break;
		}
		else if (check == '(') {
			result++;
			counter++;
			if (result == -1) {
				break;
			}
		}
		else if (check == ')') {
			result--;
			counter++;
			if (result == -1) {
				break;
			}
		}
		
	}
	//std::cout << result << std::endl;
	std::cout << counter << std::endl;
	file.close();
	system("pause");
	return 0;
}
