#include "multitable.h"

TMultitable::TMultitable()
{
}

TMultitable::TMultitable(int size):
	dis(size), ord(size), hash(size) {}

TMultitable::~TMultitable()
{
}

void TMultitable::Insert(string _key, Polinom pol)
{
	dis.Insert(_key, pol);
	ord.Insert(_key, pol);
	hash.Insert(_key, pol);

	string s_dis[2] = { "disordered tbl", "insert" };
	string s_ord[2] = { "ordered tbl", "insert" };
	string s_hash[2] = { "hash tbl","insert" };

	dis.Logging(s_dis);
	ord.Logging(s_ord);
	hash.Logging(s_hash);
}

void TMultitable::Delete(string _key)
{
	dis.Delete(_key);
	ord.Delete(_key);
	hash.Delete(_key);

	string s_dis[2] = { "disordered tbl", "delete" };
	string s_ord[2] = { "ordered tbl", "delete" };
	string s_hash[2] = { "hash tbl","delete" };

	dis.Logging(s_dis);
	ord.Logging(s_ord);
	hash.Logging(s_hash);
}

Polinom TMultitable::Search(string _key)
{
	Polinom res;
	 
	res = dis.Search(_key);
	ord.Search(_key);
	hash.Search(_key);

	string s_dis[2] = { "disordered tbl", "search" };
	string s_ord[2] = { "ordered tbl", "search" };
	string s_hash[2] = { "hash tbl","search" };

	dis.Logging(s_dis);
	ord.Logging(s_ord);
	hash.Logging(s_hash);

	return res;
}