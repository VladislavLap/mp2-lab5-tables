#include "hash_table.h"

THashTable::THashTable()
{
	size = DEFAULT_SIZE;
	tbl = new Record*[size];
	oper = 0;

	flag = new bool[size];
	for (int i = 0; i < size; i++)
	{
		flag[i] = false;
		tbl[i] = NULL;
	}
}

THashTable::THashTable(int _size)
{
	if (!_size)
		throw "Error: table size is zero";

	size = _size;
	tbl = new Record*[size];
	oper = 0;

	flag = new bool[size];
	for (int i = 0; i < size; i++)
	{
		flag[i] = false;
		tbl[i] = NULL;
	}
}

THashTable::~THashTable()
{
	for (int i = 0; i < size; i++)
		delete tbl[i];

	delete[] tbl;
	delete[] flag;
}


int THashTable::HashFunction(string _key, int bias)
{
	int hash = 0;

	for (int i = 0; i < _key.length(); i++)
		hash += _key[i];
	hash = hash % size;

	oper++;
	if (bias)
		return (hash + bias) % size;
	else
		return hash;
}

void THashTable::Insert(string _key, Polinom p)
{
	oper = 0;
	Record* rec = new Record(_key, p);

	int count = 0;
	bool ins = false;

	do 
	{
		int hash = HashFunction(_key, count);

		oper++;
		if (tbl[hash] == NULL)
		{
			tbl[hash] = rec;
			flag[hash] = true;
			ins = true;
		}
		count++;

	} while (!ins && count != size);

	oper++;
	if(!ins && count == size)
	throw "Error: No free places in the table";
}

void THashTable::Delete(string _key)
{
	int ind = IndxSearch(_key);
	delete tbl[ind];
	tbl[ind] = NULL;
}

int THashTable::IndxSearch(string _key)
{
	oper = 0;
	int count = 0;
	int hash = HashFunction(_key, count);

	while (flag[hash] != false && count != size)
	{
		oper++;
		if (tbl[hash] != NULL && tbl[hash]->Getname() == _key)
			return hash;

		count++;
		hash = HashFunction(_key, count);
	} 

	throw "No such element in the table";
}

Polinom THashTable::Search(string _key)
{
	int ind = IndxSearch(_key);
	return tbl[ind]->GetPolinom();
}

