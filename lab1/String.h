#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

#define MAX_SIZE 2048

#define min(a, b) ((a) > (b)) ? (b) : (a)

class String {
public:
	String();
	String(const char* str);
	String(const String& obj);
	String(String&& obj);
	~String();
	String& operator=(const char* str);
	String& operator=(const String& obj);
	String& operator=(String&& obj) noexcept;

	int _strlen(const char* strt);
	void _strcpy(char* strt1, const char* strt2, int N);
	char _uppercase(const char c) {
		if (int(c) > 96 && int(c) < 123)
			return char(int(c) - 32);
		return c;
	}

	friend bool operator==(const String& Obj1, const String& Obj2);

	friend bool operator<(const String& Obj1, const String& Obj2);

	friend void move(String& str1, String& str2);

	friend std::istream& operator>>(std::istream& is, String& Obj);
	friend std::ostream& operator<<(std::ostream& os, const String& Obj);

	void create(const char* str);
	void clear();

private:
	char* str;
	int len;
};

#endif
