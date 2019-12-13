#include "Keeper.h"

Keeper::Keeper() : size(0) {
	mas = new TRAIN[Keeper::COUNT];
}
Keeper::~Keeper() {
	delete[] mas;
}

void Keeper::operator+=(const TRAIN &Obj) {
	int i, j;
	if (size == Keeper::COUNT)
		throw exceptions("Список TRAIN полон. Добаваить новую запись нельзя.");
	for (i = 0; i < size; ++i) {
		if (Obj.GetName() < mas[i].GetName())
			break;
	}
	if (size) {
		for (j = size - 1; j >= i; --j)
			move(mas[j + 1], mas[j]);
	}
	mas[i] = Obj;
	++size;
}
void Keeper::remove(int dec) {
	int i;
	if (dec < 0 || dec >= size)
		throw exceptions("Введен неверный номер.");
	for (i = dec; i < size; ++i)
		move(mas[i], mas[i + 1]);
	--size;
}

void Keeper::print(size_t time_H, size_t time_M) {
	int j = 0;
	bool flag = true;
	for (int i = 0; i < size; ++i) {
		if (mas[i].GetTime_H() > time_H || (mas[i].GetTime_H() == time_H && mas[i].GetTime_M() > time_M)) {
			std::cout << '(' << j++ + 1 << ')' << std::endl;
			mas[i].print();
			flag = false;
			std::cout << std::endl;
		};
	}
	if (flag)
		throw exceptions("Нет поездов с временем отправления позже заданного.");
}

std::ostream& operator<<(std::ostream& os, const Keeper &kpr) {
	if (!kpr.size)
		os << "Список записей пуст." << std::endl;
	for (int i = 0; i < kpr.size; ++i) {
		os << '(' << i + 1 << ')' << std::endl;
		os << kpr.mas[i];
		os << std::endl;
	}

	return os;
}
std::istream& operator>>(std::istream& is, Keeper &kpr) {
	TRAIN Obj;
	int N;

	std::cout << "Сколько добавить записей? ";
	is >> N;
	is.get();

	std::cout << std::endl;

	if (N > Keeper::COUNT || N <= 0)
		throw exceptions("Введенное неверное число.");

	kpr.size = 0;

	for (int i = 0; i < N; ++i) {

		std::cout << '(' << i + 1 << ')' << std::endl;

		try {

			is >> Obj;
			kpr += Obj;
			std::cout << std::endl;

		}
		catch (const exceptions& e) {

			std::cout << e.what() << std::endl;
			--i;

		}

	}

	return is;
}
