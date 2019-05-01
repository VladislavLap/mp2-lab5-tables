#include "gtest.h"
#include "disordered_table.h"

TEST(TDisorderedTable, can_create_table)
{
	ASSERT_NO_THROW(TDisorderedTable tbl);
}

TEST(TDisorderedTable, can_create_table_with_given_size)
{
	ASSERT_NO_THROW(TDisorderedTable tbl(10));
}

TEST(TDisorderedTable, do_not_create_table_with_zero_size)
{
	ASSERT_ANY_THROW(TDisorderedTable tbl(0));
}

TEST(TDisorderedTable, can_delete_table)
{
	TDisorderedTable* tbl = new TDisorderedTable(10);
	ASSERT_NO_THROW(delete tbl);
}

TEST(TDisorderedTable, table_is_empty)
{
	TDisorderedTable tbl(3);
	EXPECT_EQ(true, tbl.IsEmpty());
}

TEST(TDisorderedTable, record_is_inserted)
{
	TDisorderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(false,tbl.IsEmpty());
}

TEST(TDisorderedTable, record_is_inserted_in_the_right_place)
{
	TDisorderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(pol, tbl.GetValue(0));
}

TEST(TDisorderedTable, can_not_insert_when_table_is_full)
{
	TDisorderedTable tbl(1);
	Monom mon1(1.0, 11);
	Polinom pol1;
	Polinom pol2;

	pol1.Insert(mon1);
	tbl.Insert("first",pol1);

	ASSERT_ANY_THROW(tbl.Insert("second", pol2));
}

TEST(TDisorderedTable, table_is_full)
{
	TDisorderedTable tbl(1);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(true,tbl.IsFull());
}

TEST(TDisorderedTable, record_is_deleted)
{
	TDisorderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);
	tbl.Delete("first");

	EXPECT_EQ(true,tbl.IsEmpty());
}

TEST(TDisorderedTable, exception_when_we_delete_nonexistent_record)
{
	TDisorderedTable tbl(3);
	Polinom pol;

	tbl.Insert("first", pol);

	ASSERT_ANY_THROW(tbl.Delete("second"));
}

TEST(TDisorderedTable, last_record_move_to_free_place)
{
	TDisorderedTable tbl(3);
	Monom mon1(1.0, 11);
	Monom mon2(2.0, 22);
	Polinom pol1;
	Polinom pol2;

	pol1.Insert(mon1);
	pol2.Insert(mon2);

	tbl.Insert("first",pol1);
	tbl.Insert("second", pol2);
	tbl.Delete("first");

	EXPECT_EQ(pol2,tbl.GetValue(0));
}

TEST(TDisorderedTable, can_search_existing_record)
{
	TDisorderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	EXPECT_EQ(pol, tbl.Search("first"));
}

TEST(TDisorderedTable, exception_when_we_search_nonexistent_record)
{
	TDisorderedTable tbl(3);
	Monom mon(1.0, 11);
	Polinom pol;

	pol.Insert(mon);
	tbl.Insert("first", pol);

	ASSERT_ANY_THROW(tbl.Search("second"));
}