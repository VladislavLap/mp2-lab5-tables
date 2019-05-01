#include "gtest.h"
#include "polinom.h"

TEST(Node, can_create_node)
{
	ASSERT_NO_THROW(Node<int> test);
}

TEST(Node, can_create_node_with_given_data)
{
	ASSERT_NO_THROW(Node<int> test(1));
}

TEST(Node, is_data_correct_when_create_node_with_given_data)
{
	Node<int> test(4);
	EXPECT_EQ(4, test.data);
}

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> test);
}

TEST(List, can_create_list_with_given_head)
{
	Node<int>* first = new Node<int>;

	ASSERT_NO_THROW(List<int> test(first));
}

TEST(List, copied_list_is_equal_to_source_one)
{
	List<int> test1;

	test1.Insert(1);
	test1.Insert(2);

	List<int> test2(test1);

	EXPECT_EQ(test1, test2);
}

TEST(List, IsEmpty_return_true_if_list_is_empty)
{
	List<int> lst;

	EXPECT_EQ(true, lst.IsEmpty());
}

TEST(List, the_data_inserted_in_the_right_place)
{
	Node<int>* t3 = new Node<int>;
	Node<int>* t1 = new Node<int>;

	t3->data = 3;
	t1->data = 1;
	t3->next = t1;
	t1->prev = t3;

	List<int> test(t3);
	test.Insert(2);

	EXPECT_EQ(2, t3->next->data);
	EXPECT_EQ(t1, t3->next->next);
	EXPECT_EQ(t3, t3->next->prev);
	EXPECT_EQ(t3->next, t3->next->next->prev);
	EXPECT_EQ(t3, t3->next->prev);
}

TEST(List, the_list_empty_after_cleaning)
{
	List<int> test;

	test.Insert(3);
	test.Insert(4);
	test.Clear();

	EXPECT_EQ(true, test.IsEmpty());
}

TEST(List, is_the_node_deleted)
{
	Node<int>* t3 = new Node<int>;
	Node<int>* t2 = new Node<int>;
	Node<int>* t1 = new Node<int>;

	t3->data = 3;
	t2->data = 2;
	t1->data = 1;
	t3->next = t2;
	t2->prev = t3;
	t2->next = t1;
	t1->prev = t2;

	List<int> test(t3);
	test.Delete(t2);

	EXPECT_EQ(t1, t3->next);
	EXPECT_EQ(t3, t1->prev);
}

TEST(List, can_merge_two_lists_correctly)
{
	List<int> test1;
	List<int> test2;
	List<int> res;
	List<int> exp;

	test1.Insert(1);
	test1.Insert(3);
	test2.Insert(2);
	test2.Insert(4);

	exp.Insert(4);
	exp.Insert(3);
	exp.Insert(2);
	exp.Insert(1);

	res = test1.Merge(test2);

	EXPECT_EQ(true, res == exp);
}

TEST(List, compare_equal_lists_return_true_)
{
	List<int> lst1;
	List<int> lst2;

	lst1.Insert(1);
	lst1.Insert(2);

	lst2.Insert(1);
	lst2.Insert(2);

	EXPECT_EQ(true, lst1 == lst2);
}

TEST(List, can_assign_lists)
{
	List<int> test1;
	List<int> test2;

	test1.Insert(2);
	test2.Insert(3);
	test2.Insert(4);

	test1 = test2;

	EXPECT_EQ(test2, test1);
}

