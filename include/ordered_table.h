#ifndef _ORDERED_H_
#define _ORDERED_H_

#include "ttable.h"

class TOrderedTable : public TTable
{
	int free_pl;

	void Repacking(int);
	void ControlIndex(int, string);
	int IndxSearch(string);

public:

	TOrderedTable();
	TOrderedTable(int);
	~TOrderedTable();

	bool IsEmpty();
	bool IsFull();

	void Insert(string, Polinom);
	void Delete(string);
	Polinom Search(string);
};
#endif