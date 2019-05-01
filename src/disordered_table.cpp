#include "disordered_table.h"

TDisorderedTable::TDisorderedTable()
{
	size = DEFAULT_SIZE;
	tbl = new Record*[size];
	free_pl = 0;
	oper = 0;
}

TDisorderedTable::TDisorderedTable(int _size)
{
	if (!_size)
		throw "Error: table size is zero";

	size = _size;
	tbl = new Record*[size];
	free_pl = 0;
	oper = 0;
}

TDisorderedTable::~TDisorderedTable()
{
	for (int i = 0; i < free_pl; i++)
	{
		delete tbl[i];
	}

	delete[] tbl;
}

bool TDisorderedTable::IsEmpty()
{
	if (!free_pl)
		return true;
	else
		return false;
}

bool TDisorderedTable::IsFull()
{
	if (free_pl == size)
		return true;
	else
		return false;
}

void TDisorderedTable::Insert(string _key, Polinom _pol)
{
	oper = 0;
	if (IsFull())
		throw "Error: No free places in the table";

	Record* rec = new Record(_key, _pol);

	tbl[free_pl] = rec;
	free_pl++;
}

void TDisorderedTable::Delete(string _key)
{
	int ind = IndxSearch(_key);
	delete tbl[ind];

	tbl[ind] = tbl[free_pl-1];
	tbl[free_pl - 1] = NULL;
	free_pl--;
}

int TDisorderedTable::IndxSearch(string _key)
{
	oper = 0;
	for (int i = 0; i < free_pl; i++)
	{
		oper++;
		if (tbl[i]->Getname() == _key)
			return i;
	}

	throw "No such element in the table";
}

Polinom TDisorderedTable::Search(string _key)
{
	int ind = IndxSearch(_key);
	return tbl[ind]->GetPolinom();
}


