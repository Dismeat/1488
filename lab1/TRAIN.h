#ifndef _TRAIN_H_
#define _TRAIN_H_

#include "exceptions.h"

class TRAIN {
public:
	TRAIN();
	TRAIN(const String& n, size_t nm, size_t t_H, size_t t_M);
	TRAIN(const TRAIN &Obj);
	~TRAIN() {};

	TRAIN& operator=(const TRAIN& Obj);

	friend void move(TRAIN &Obj1, TRAIN &Obj2);

	void SetName(const String& s);
	void SetNum(size_t nm);
	void SetTime(size_t t_H, size_t t_M);

	const String& GetName() const;
	size_t GetNum() const;
	size_t GetTime_H() const;
	size_t GetTime_M() const;


	void print();

	friend std::istream& operator>>(std::istream &is, TRAIN &Obj);
	friend std::ostream& operator<<(std::ostream &os, const TRAIN &Obj);
private:
	String name;
	size_t num;
	size_t time_H;
	size_t time_M;
};



#endif
