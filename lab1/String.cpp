#include "String.h"

String::String() : str(nullptr), len(0) {}
String::String(const char *str) {
	create(str);
}
String::String(const String &Obj) {
	create(Obj.str);
}
String::String(String &&Obj) {
	str = Obj.str;
	len = Obj.len;
	Obj.str = nullptr;
	Obj.len = 0;
}
String::~String() {
	clear();
}
String& String::operator=(const char* str) {
	clear();
	create(str);
	return *this;
}
String& String::operator=(const String &Obj) {
	if (this != &Obj) {
		clear();
		create(Obj.str);
	}
	return *this;
}
String& String::operator=(String &&Obj) noexcept {
	if (this != &Obj) {
		delete[] str;
		str = Obj.str;
		len = Obj.len;
		Obj.str = nullptr;
		Obj.len = 0;
	}
	return *this;
}

bool operator==(const String &Obj1, const String &Obj2) {
	if (&Obj1 == &Obj2)
		return true;
	if (Obj1.len != Obj2.len)
		return false;
	for (int i = 0; i < Obj1.len; ++i)
		if (Obj1.str[i] != Obj2.str[i])
			return false;
	return true;
}

bool operator<(const String &Obj1, const String &Obj2) {
	int i;
	int len = min(Obj1.len, Obj2.len);
	for (i = 0; i < len; ++i) {
		if (uppercase(Obj1.str[i]) == uppercase(Obj2.str[i])) {
			if (Obj1.str[i] < Obj2.str[i])
				return true;
			else if (Obj1.str[i] > Obj2.str[i])
				return false;
		}
		else if (uppercase(Obj1.str[i]) < uppercase(Obj2.str[i]))
			return true;
	}
	return (Obj1.len < Obj2.len) ? true : false;
}

void move(String &str1, String &str2) {
	str1.clear();
	str1.len = str2.len;
	str1.str = str2.str;
	str2.str = nullptr;
	str2.len = 0;
}

std::istream& operator>>(std::istream &is, String &Obj) {
	int i;
	char c[MAX_SIZE];
	Obj.clear();
	for (i = 0; (c[i] = is.get()) != '\n'; ++i);
	c[i] = '\0';
	Obj.create(c);
	return is;
}
std::ostream& operator<<(std::ostream &os, const String &Obj) {
	if (Obj.str) os << Obj.str;
	else os << 'o';
	return os;
}

void String::create(const char* str) {
	len = _strlen(str);
	if (len) {
		this->str = new char[++len];
		_strcpy(this->str, str, len--);
	}
	else {
		this->str = nullptr;
	}
}
void String::clear() {
	delete[] str;
	str = nullptr;
	len = 0;
}
