#ifndef _TTABLE_H_
#define _TTABLE_H_

#include "iostream"
#include "fstream"
#include "string"
#include "polinom.h"
using namespace std;

#define DEFAULT_SIZE 40

class Record 
{
	string name;
	Polinom pol;

public:

	Record();
	Record(string, Polinom);
	~Record();

	string Getname();
	Polinom GetPolinom();
};

class TTable 
{

protected:

	Record** tbl;
	int size;
	int oper;

	virtual int IndxSearch(string) = 0;

public:

	virtual bool IsFull();
	virtual bool IsEmpty();
	Polinom GetValue(int);

	virtual void Insert(string, Polinom) = 0;
	virtual void Delete(string) = 0;
	virtual Polinom Search(string) = 0;

	void Logging(string*);
};

void CleanLog();

#endif