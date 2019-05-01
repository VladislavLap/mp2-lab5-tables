#include "ordered_table.h"

TOrderedTable::TOrderedTable()
{
	size = DEFAULT_SIZE;
	tbl = new Record*[size];
	free_pl = 0;
	oper = 0;
}

TOrderedTable::TOrderedTable(int _size)
{
	if (!_size)
		throw "Error: table size is zero";

	size = _size;
	tbl = new Record*[size];
	free_pl = 0;
	oper = 0;
}

TOrderedTable::~TOrderedTable()
{
	for (int i = 0; i < free_pl; i++)
		delete tbl[i];

	delete[] tbl;
}

bool TOrderedTable::IsEmpty()
{
	if (!free_pl)
		return true;
	else
		return false;
}

bool TOrderedTable::IsFull()
{
	if (free_pl == size)
		return true;
	else
		return false;
}

void TOrderedTable::Repacking(int _ind)
{
	Record* copy = tbl[_ind];

	for (int i = _ind; i < free_pl; i++)
	{
		oper++;
		Record* temp = copy;
		copy = tbl[i + 1];
		tbl[i + 1] = temp;
	}
}

void TOrderedTable::Insert(string _key, Polinom _pol)
{
	oper = 0;
	if (IsFull())
		throw "Error: No free places in the table";

	Record* rec = new Record(_key,_pol);

	oper++;
	if (IsEmpty())
		tbl[0] = rec;
	else 
	{
		int ind = IndxSearch(_key);

		oper++;
		if (tbl[ind]->Getname() > _key)
		{
			Repacking(ind);
			tbl[ind] = rec;
		}
		else
		{
			Repacking(ind + 1);
			tbl[ind + 1] = rec;
		}
	}

	free_pl++;
}

void TOrderedTable::Delete(string _key)
{
	int ind = IndxSearch(_key);
	ControlIndex(ind, _key);
	delete tbl[ind];

	for (int i = ind + 1; i < free_pl; i++)
	{
		oper++;
		tbl[i - 1] = tbl[i];
	}

	free_pl--;
	tbl[free_pl] = NULL;
}

int TOrderedTable::IndxSearch(string _key)
{
	oper = 0;
	int left = 0, right = free_pl - 1, mid;

	oper++;
	if (!free_pl)
		right = 0;

	while (left != right)
	{
		mid = left + (1 / 2)*(right - left);

		oper++;
		if (tbl[mid]->Getname() >= _key)
			right = mid;
		else
			left = mid + 1;
	}

	return left;
}

void TOrderedTable::ControlIndex(int ind, string _key)
{
	oper++;
	if (tbl[ind] == NULL || tbl[ind]->Getname() != _key)
		throw "No such element in the table";
}

Polinom TOrderedTable::Search(string _key)
{
	int ind = IndxSearch(_key);
	ControlIndex(ind, _key);
	return tbl[ind]->GetPolinom();
}