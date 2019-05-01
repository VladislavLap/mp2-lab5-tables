#include "polinom.h"
#include "gtest.h"

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom A);
}

TEST(Monom, can_create_monom_with_given_fields)
{
	ASSERT_NO_THROW(Monom A(4.4, 5));
}

TEST(Monom, throw_when_create_monom_with_too_large_or_to_small_degree)
{
	ASSERT_ANY_THROW(Monom A(4, 1000));
}

TEST(Monom, RetSum_returns_true_value)
{
	Monom mon(3, 456);
	int sum = mon.RetSum();

	EXPECT_EQ(15, sum);
}

TEST(Monom, greater_or_equal_operator_return_true_if_monom_is_greater_than_other_or_they_equal)
{
	Monom m1(2, 44);
	Monom m2(3, 66);

	EXPECT_EQ(true, m2 >= m1);
}

TEST(Monom, less_operator_return_true_if_monom_is_less_than_other)
{
	Monom m1(2, 55);
	Monom m2(2, 300);

	EXPECT_EQ(true, m1<m2);
}

TEST(Monom, not_equal_operator_return_true_if_monoms_are_not_equal)
{
	Monom m1(2, 0);
	Monom m2(2, 7);

	EXPECT_EQ(true, m1!=m2);
}

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom pol);
}

TEST(Polinom, ToStandartView_deletes_monoms_with_zero_coefficient)
{
	Polinom test;
	Polinom exp;
	Monom m1(0, 999);
	Monom m2(3, 444);
	Monom m3(0, 222);

	test.Insert(m1);
	test.Insert(m2);
	test.Insert(m3);
	exp.Insert(m2);

	test.ToStandartView();

	EXPECT_EQ(exp, test);
}

TEST(Polinom, ToStandartView_leads_similar_monoms)
{
	Polinom test;
	Polinom exp;
	Monom m1(2, 555);
	Monom m2(5, 555);
	Monom m3(3, 550);
	Monom m4(7, 555);

	test.Insert(m1);
	test.Insert(m2);
	test.Insert(m3);

	exp.Insert(m3);
	exp.Insert(m4);

	test.ToStandartView();

	EXPECT_EQ(exp, test);
}

TEST(Polinom, can_assign_polinoms)
{
	Polinom p1;
	Polinom p2;
	Monom m1(1, 111);
	Monom m2(2, 222);
	Monom m3(3, 333);

	p1.Insert(m1);
	p1.Insert(m2);
	p2.Insert(m3);

	p1 = p2;

	EXPECT_EQ(p2, p1);
}

TEST(Polinom, can_assign_list_of_monoms_to_polinom)
{
	List<Monom> lst;
	Polinom test;
	Polinom exp;
	Monom m1(3, 333);
	Monom m2(4, 444);

	lst.Insert(m1);
	lst.Insert(m2);
	exp.Insert(m1);
	exp.Insert(m2);

	test = lst;

	EXPECT_EQ(exp, test);
}

TEST(Polinom, can_add_two_polinoms)
{
	Polinom p1;
	Polinom p2;
	Polinom exp;

	Monom m1(2, 33);
	Monom m2(3, 44);
	Monom m3(4, 33);
	Monom m4(3, 222);
	Monom m5(6, 33);

	p1.Insert(m1);
	p1.Insert(m2);
	p2.Insert(m3);
	p2.Insert(m4);

	exp.Insert(m2);
	exp.Insert(m4);
	exp.Insert(m5);

	EXPECT_EQ(exp, p1+p2);
}

TEST(Polinom, can_subtract_polinom_from_another_polinom)
{
	Polinom p1;
	Polinom p2;
	Polinom exp;

	Monom m1(2, 33);
	Monom m2(3, 44);
	Monom m3(4, 33);
	Monom m4(3, 222);
	Monom m5(-2, 33);
	Monom m6(3, 44);
	Monom m7(-3, 222);

	p1.Insert(m1);
	p1.Insert(m2);
	p2.Insert(m3);
	p2.Insert(m4);

	exp.Insert(m5);
	exp.Insert(m6);
	exp.Insert(m7);

	EXPECT_EQ(exp, p1-p2);
}

TEST(Polinom, can_multiply_polinom_by_constant)
{
	Polinom p1;
	Polinom exp;
	Monom m1(3, 22);
	Monom m2(12, 999);
	Monom m3(15, 22);
	Monom m4(60, 999);
	double c = 5.0;

	p1.Insert(m1);
	p1.Insert(m2);
	
	exp.Insert(m3);
	exp.Insert(m4);

	EXPECT_EQ(exp, p1*c);
}

TEST(Polinom, can_multiply_polinom_by_monom)
{
	Polinom p1;
	Polinom exp;
	Monom m1(2, 444);
	Monom m2(3, 555);
	Monom m3(4, 421);
	Monom m4(8, 865);
	Monom m5(12, 976);

	p1.Insert(m1);
	p1.Insert(m2);

	exp.Insert(m4);
	exp.Insert(m5);

	EXPECT_EQ(exp, p1*m3);
}

TEST(Polinom, throw_if_degree_of_variable_more_than_9_when_multiply_polinom_by_monom)
{
	Polinom p1;
	Monom m1(3, 666);
	Monom m2(4, 444);

	p1.Insert(m1);

	ASSERT_ANY_THROW(p1*m2);
}

TEST(Polinom, can_multiply_two_polinoms)
{
	Polinom p1;
	Polinom p2;
	Polinom exp;
	Monom m1(2, 222);
	Monom m2(3, 333);
	Monom m3(4, 444);
	Monom m4(5, 111);
	Monom m5(8, 666);
	Monom m6(12,777);
	Monom m7(10, 333);
	Monom m8(15, 444);

	p1.Insert(m1);
	p1.Insert(m2);
	p2.Insert(m3);
	p2.Insert(m4);

	exp.Insert(m5);
	exp.Insert(m6);
	exp.Insert(m7);
	exp.Insert(m8);

	EXPECT_EQ(exp, p1*p2);
}
