#ifndef _KEEPER_H_
#define _KEEPER_H_

#include "TRAIN.h"

class Keeper {
public:
	enum {
		COUNT = 8
	};

	Keeper();
	~Keeper();

	void operator+=(const TRAIN &Obj);
	void remove(int dec);

	void print(size_t time_H, size_t time_M);

	friend std::ostream& operator<<(std::ostream& os, const Keeper &kpr);
	friend std::istream& operator>>(std::istream& is, Keeper &kpr);

	int GetSize() const { return size; }

private:
	TRAIN *mas;
	int size;
};

#endif
