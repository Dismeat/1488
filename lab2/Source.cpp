#include <iostream>

#include <fstream>

#define MAS_SIZE 1024

const char sep[] = ". ,!?:;_\n\t";

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;

bool check_sep(const char c, const char* sp);

int main() {

	ifstream in("in.txt");

	//Блок проверки открытия файла

	if (!in.is_open()) {

		cout << "Error: file is not opened" << endl;

		in.close();

		return 0;

	}

	//Чтение файла из файлового потока

	int8_t c;
	uint32_t count = 0;
	uint32_t countWord = 0;

	do {

		c = in.get();

		if (!check_sep(c, sep)) {

			++count;

		}
		else {

			if (count > 4) {

				++countWord;

			}

			count = 0;

		}

	} while (c != EOF);

	cout << "Words with less than 5 letters: " << countWord << endl;

	in.close();

	return 0;

}

bool check_sep(const char c, const char* sp) {

	for (int i = 0; sp[i] != '\0'; ++i)

		if (sp[i] == c || sp[i] == EOF) return true;

	return false;

}
