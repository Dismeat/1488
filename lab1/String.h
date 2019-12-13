#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include "function_String.h"

#define MAX_SIZE 2048

#define min(a, b) ((a) > (b)) ? (b) : (a)

class String {
public:
	String();
	String(const char *str);
	String(const String &obj);
	String(String &&obj);
	~String();
	String& operator=(const char* str);
	String& operator=(const String &obj);
	String& operator=(String &&obj) noexcept;

	friend bool operator==(const String &Obj1, const String &Obj2);

	friend bool operator<(const String &Obj1, const String &Obj2);

	friend void move(String &str1, String &str2);

	friend std::istream& operator>>(std::istream& is, String &Obj);
	friend std::ostream& operator<<(std::ostream& os, const String &Obj);

	void create(const char* str);
	void clear();

private:
	char* str;
	int len;
};

#endif
