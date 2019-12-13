#include "function_String.h"

int _strlen(const char *str) {
	int i = 0;
	if (str)
		while (str[i] != '\0') ++i;
	return i;
}
void _strcpy(char *str1, const char *str2, int N) {
	for (int i = 0; i < N; ++i)
		str1[i] = str2[i];
}

char uppercase(const char c) {
	if (int(c) > 96 && int(c) < 123)
		return char(int(c) - 32);
	return c;
}
