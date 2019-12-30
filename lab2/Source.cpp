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
	int8_t c;
	uint32_t count = 0;
	uint32_t countWord = 0;
	uint32_t countadd = 0;
	int n = 0;//Номер элемента файла для чтения
	int a = -1;
	//Цикл с защитой от вытаскивание флешки топорным методом.Я бы сказал псевдовариантом.
	//Если флешка вытащена,мы при открытии,проверке,закрытии и это в цикле - увидем это.
   do {

	   ifstream in("in.txt");

	    //Блок проверки открытия файла

	   if (!in.is_open()) {

		cout << "Error: file is not opened" << endl;

		in.close();

		break;
	   }

	   //Цикл поиска текущего элемента с считываемого файла
	   do
	   {
	     c = in.get();
		 a++;
	   } while (a != n);

	   a = -1;

	   if(!check_sep(c, sep)) {

		++count;

	   }
	   else {
		   count = 0;
	   }
	   if (count > 4) {

		++countWord;
		count = 0;
	   }

	   n++;
	   in.close();
   }while (c != EOF);

	cout << "Words were found with less than 5 letters: " << countWord << endl;



}

bool check_sep(const char c, const char* sp) {

	for (int i = 0; sp[i] != '\0'; ++i)

		if (sp[i] == c || sp[i] == EOF) return true;

	return false;

}
