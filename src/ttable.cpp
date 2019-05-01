#include "ttable.h"

Record::Record()
{
	name = "";
}

Record::Record(string _str, Polinom _pol)
{
	name = _str;
	pol = _pol;
}

Record::~Record()
{
}

string Record::Getname()
{
	return name;
}

Polinom Record::GetPolinom()
{
	return pol;
}

bool TTable::IsFull()
{
	for (int i = 0; i < size; i++)
		if (tbl[i] == NULL)
			return false;

	return true;
}

bool TTable::IsEmpty()
{
	for (int i = 0; i < size; i++)
		if (tbl[i] != NULL)
			return false;

	return true;
}

Polinom TTable::GetValue(int _ind)
{
	if (_ind < 0 || _ind >= size)
		throw "Incorrect index";

	if (tbl[_ind] == NULL)
		throw "Invalid value";

	return tbl[_ind]->GetPolinom();
}

void TTable::Logging(string* str)
{
	ofstream file( "log.txt", ios_base::app);

	for (int i = 0; i < 2; i++)
		file << str[i] << '\t';

	file << "operation " << oper << endl;

	file.close();
}

void CleanLog()
{
	ofstream file("log.txt", ios_base::trunc);
	file.close();
}