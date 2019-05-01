#ifndef _HASH_H_
#define _HASH_H_

#include "ttable.h"
#include "stdlib.h"

class THashTable : public TTable
{
	bool* flag;

	int HashFunction(string, int);
	int IndxSearch(string key);

public:

	THashTable();
	THashTable(int);
	~THashTable();

	void Insert(string, Polinom);
	void Delete(string);
	Polinom Search(string);
};
#endif