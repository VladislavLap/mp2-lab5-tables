#include "ttable.h"
#include "gtest.h"

TEST(Record, can_create_record)
{
	ASSERT_NO_THROW(Record rec);
}

TEST(Record, can_create_record_wirh_given_values)
{
	Polinom pol;
	ASSERT_NO_THROW(Record rec("first", pol));
}

TEST(Record, can_delete_record)
{
	Record* rec = new Record;
	ASSERT_NO_THROW(delete rec);
}

TEST(Record, can_get_name)
{
	Polinom pol;
	Record rec("first",pol);

	EXPECT_EQ("first",rec.Getname());
}

TEST(Record, can_get_polinom)
{
	Monom mon(1, 1);
	Polinom pol;

	pol.Insert(mon);
	Record rec("first", pol);

	EXPECT_EQ(pol,rec.GetPolinom());
}