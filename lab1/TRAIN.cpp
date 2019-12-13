#include "TRAIN.h"

TRAIN::TRAIN() : num(0), time_H(0), time_M(0) {}
TRAIN::TRAIN(const String& n, size_t nm, size_t t_H, size_t t_M) :
	name(n), num(nm), time_H(t_H), time_M(t_M) {}
TRAIN::TRAIN(const TRAIN &Obj) :
	name(Obj.name), num(Obj.num), time_H(Obj.time_H), time_M(Obj.time_M) {}


TRAIN& TRAIN::operator=(const TRAIN& Obj) {

	if (this != &Obj) {

		name = Obj.name;
		num = Obj.num;
		time_H = Obj.time_H;
		time_M = Obj.time_M;

	}

	return *this;
}

void move(TRAIN &Obj1, TRAIN &Obj2) {

	move(Obj1.name, Obj2.name);
	Obj1.num = Obj2.num;
	Obj2.num = 0;
	Obj1.time_H = Obj2.time_H;
	Obj1.time_M = Obj2.time_M;

}

void TRAIN::SetName(const String& s) {
	name = s;
}
void TRAIN::SetNum(size_t nm) {
	num = nm;
}
void TRAIN::SetTime(size_t t_H, size_t t_M) {

	if (t_H > 23)
		throw(exceptions("Ошибка указания времени отправления!"));

	if (t_M > 59)
		throw(exceptions("Ошибка указания времени отправления!"));

	this->time_H = t_H;
	this->time_M = t_M;
}

const String& TRAIN::GetName() const  {
	return name;
}
size_t TRAIN::GetNum() const {
	return num;
}
size_t TRAIN::GetTime_H() const  {
	return time_H;
}
size_t TRAIN::GetTime_M() const {
	return time_M;
}


void TRAIN::print() {

	int width = 20;
	std::cout.width(width);
	std::cout << "Пункт назначения: ";
	std::cout << name;
	std::cout << std::endl;

	std::cout.width(width);
	std::cout << "Номер рейса: ";
	std::cout << num;
	std::cout << std::endl;
}

std::istream& operator>>(std::istream &is, TRAIN &Obj) {
	std::cout << "Введите название пункта назначения: ";
	is >> Obj.name;

	std::cout << "Введите номер рейса: ";
	is >> Obj.num;
	is.get();

	std::cout << "Введите час отправления поезда: ";
	is >> Obj.time_H;

	if (Obj.time_H > 23)
		throw(exceptions("Ошибка указания времени отправления!"));

	std::cout << "Введите минуты отправления поезда: ";
	is >> Obj.time_M;

	if (Obj.time_M > 59)
		throw(exceptions("Ошибка указания времени отправления!"));

	return is;
}
std::ostream& operator<<(std::ostream &os, const TRAIN &Obj) {
	int width = 20;
	os.width(width);
	os << "Пункт назначения: ";
	os << Obj.name;
	os << std::endl;

	os.width(width);
	os << "Номер рейса: ";
	os << Obj.num;
	os << std::endl;

	os.width(width);
	os << "Время отправления: ";
	os << Obj.time_H << ':' << Obj.time_M;
	os << std::endl;

	return os;
}
