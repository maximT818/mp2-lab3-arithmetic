// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<double> stack0);
}

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<double> stack0(5));
}

TEST(Stack, can_not_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<double> stack0(-5));
}

TEST(Stack, can_create_stack_by_copying)
{
	Stack<double> st0;
	ASSERT_NO_THROW(Stack<double> stack0(st0));
}

TEST(Stack, can_return_max_size)
{
	Stack<double> stack0(5);
	EXPECT_EQ(5, stack0.GetMaxSize());
}

TEST(Stack, can_create_empty_stack)
{
	Stack<double> stack0;
	EXPECT_EQ(1, stack0.IsEmpty());
}

TEST(Stack, can_create_full_stack)
{
	Stack<double> stack0(7);
	stack0.pop();
	stack0.push(1);
	EXPECT_EQ(1, stack0.IsFull());
}

TEST(Stack, can_push)
{
	Stack<double> stack0(5);
	ASSERT_NO_THROW(stack0.push(1));
}

TEST(Stack, can_pop)
{
	Stack<double> stack0(5);
	ASSERT_NO_THROW(stack0.pop());
}

TEST(Stack, can_show)
{
	Stack<double> stack0(5);
	ASSERT_NO_THROW(stack0.show());
}



