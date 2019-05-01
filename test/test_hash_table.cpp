#include "gtest.h"
#include "hash_table.h"

TEST(THashTable, can_create_table)
{
	ASSERT_NO_THROW(THashTable tbl);
}

TEST(THashTable, can_create_table_with_given_size)
{
	ASSERT_NO_THROW(THashTable tbl(10));
}

TEST(THashTable, do_not_create_table_with_zero_size)
{
	ASSERT_ANY_THROW(THashTable tbl(0));
}

TEST(THashTable, can_delete_table)
{
	THashTable* tbl = new THashTable(10);
	ASSERT_NO_THROW(delete tbl);
}

TEST(THashTable, table_is_empty)
{
	THashTable tbl(3);
	EXPECT_EQ(true, tbl.IsEmpty());
}

TEST(THashTable, record_is_inserted)
{
	THashTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(false, tbl.IsEmpty());
}

TEST(THashTable, record_is_inserted_in_the_right_place)
{
	THashTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;
	string str("first");
	int hash = 0;
	
	pol.Insert(mon);
	tbl.Insert( str, pol);

	EXPECT_EQ(pol, tbl.GetValue(0));
}

TEST(THashTable, when_there_is_collision_record_is_inserted_in_the_right_place)
{
	THashTable tbl(3);
	Monom mon1(1.1, 11);
	Polinom pol1;
	Polinom pol2;

	pol1.Insert(mon1);
	tbl.Insert("a",pol1);
	tbl.Insert("d", pol2);

	EXPECT_EQ(pol1, tbl.GetValue(1));
	EXPECT_EQ(pol2, tbl.GetValue(2));
}

TEST(THashTable, can_not_insert_when_table_is_full)
{
	THashTable tbl(1);
	Monom mon1(1.0, 11);
	Polinom pol1;
	Polinom pol2;

	pol1.Insert(mon1);
	tbl.Insert("first", pol1);

	ASSERT_ANY_THROW(tbl.Insert("second", pol2));
}

TEST(THashTable, table_is_full)
{
	THashTable tbl(1);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(true, tbl.IsFull());
}

TEST(THashTable, record_is_deleted)
{
	THashTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);
	tbl.Delete("first");

	EXPECT_EQ(true, tbl.IsEmpty());
}

TEST(THashTable, exception_when_we_delete_nonexistent_record)
{
	THashTable tbl(3);
	Polinom pol;

	tbl.Insert("first", pol);

	ASSERT_ANY_THROW(tbl.Delete("second"));
}

TEST(THashTable, can_search_existing_record)
{
	THashTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(pol, tbl.Search("first"));
}

TEST(THashTable, exception_when_we_search_nonexistent_record)
{
	THashTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	ASSERT_ANY_THROW(tbl.Search("second"));
}