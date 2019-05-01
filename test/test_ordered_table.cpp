#include "gtest.h"
#include "ordered_table.h"

TEST(TOrderedTable, can_create_table )
{
	ASSERT_NO_THROW(TOrderedTable tbl);
}

TEST(TOrderedTable, can_create_table_with_given_size)
{
	ASSERT_NO_THROW(TOrderedTable tbl(10));
}

TEST(TOrderedTable, do_not_create_table_with_zero_size)
{
	ASSERT_ANY_THROW(TOrderedTable tbl(0));
}

TEST(TOrderedTable, can_delete_table)
{
	TOrderedTable* tbl1 = new TOrderedTable(10);
	ASSERT_NO_THROW(delete tbl1);
}

TEST(TOrderedTable, table_is_empty)
{
	TOrderedTable tbl(3);
	EXPECT_EQ(true, tbl.IsEmpty());
}

TEST(TOrderedTable, record_is_inserted)
{
	TOrderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(false, tbl.IsEmpty());
}

TEST(TOrderedTable, record_is_inserted_in_the_right_place)
{
	TOrderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol1;
	Polinom pol2;

	pol1.Insert(mon);
	tbl.Insert("second", pol2);
	tbl.Insert("first", pol1);

	EXPECT_EQ(pol1 ,tbl.GetValue(0));
	EXPECT_EQ(pol2, tbl.GetValue(1));
}

TEST(TOrderedTable, can_not_insert_when_table_is_full)
{
	TOrderedTable tbl(1);
	Monom mon1(1.0, 11);
	Polinom pol1;
	Polinom pol2;

	pol1.Insert(mon1);
	tbl.Insert("first", pol1);

	ASSERT_ANY_THROW(tbl.Insert("second", pol2));
}

TEST(TOrderedTable, table_is_full)
{
	TOrderedTable tbl(1);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(true, tbl.IsFull());
}

TEST(TOrderedTable, record_is_deleted)
{
	TOrderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);
	tbl.Delete("first");

	EXPECT_EQ(true, tbl.IsEmpty());
}

TEST(TOrderedTable, exception_when_we_delete_nonexistent_record)
{
	TOrderedTable tbl(3);
	Polinom pol;

	tbl.Insert("first", pol);

	ASSERT_ANY_THROW(tbl.Delete("second"));
}

TEST(TOrderedTable, repaking_when_record_is_deleted)
{
	TOrderedTable tbl(3);
	Monom mon1(1.0, 11);
	Monom mon2 (2.0, 22);
	Polinom pol1;
	Polinom pol2;
	Polinom pol3;

	pol1.Insert(mon1);
	pol2.Insert(mon2);
	tbl.Insert("first",pol1);
	tbl.Insert("second", pol2);
	tbl.Insert("third", pol3);
	tbl.Delete("first");

	EXPECT_EQ(pol2, tbl.GetValue(0));
	EXPECT_EQ(pol3, tbl.GetValue(1));
}

TEST(TOrderedTable, can_search_existing_record)
{
	TOrderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(pol, tbl.Search("first"));
}

TEST(TOrderedTable, exception_when_we_search_nonexistent_record)
{
	TOrderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	ASSERT_ANY_THROW(tbl.Search("second"));
}