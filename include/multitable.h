#ifndef _MULTITABLE_H
#define _MULTITABLE_H

#include "disordered_table.h"
#include "ordered_table.h"
#include "hash_table.h"

class TMultitable
{
	int size;
	TDisorderedTable dis;
	TOrderedTable ord;
	THashTable hash;

public:
	
	TMultitable();
	TMultitable(int);
	~TMultitable();

	void Insert(string, Polinom);
	void Delete(string);
	Polinom Search(string);
};
#endif 