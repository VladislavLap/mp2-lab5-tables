#ifndef _DISORDERED_H_
#define _DISORDERED_H_

#include "ttable.h"

class TDisorderedTable : public TTable
{
	int free_pl; 

	int IndxSearch(string);

public:

	TDisorderedTable();
	TDisorderedTable(int);
	~TDisorderedTable();

	bool IsEmpty();
	bool IsFull();

	void Insert(string, Polinom);
	void Delete(string);
	Polinom Search(string);
};
#endif
