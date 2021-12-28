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

TEST(Stack, can_create_stack_by_copying_2)
{
	Stack<double> st0;
	st0.push(1);
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

TEST(Stack, can_push)
{
	Stack<double> stack0(5);
	ASSERT_NO_THROW(stack0.push(1));
}

TEST(Stack, can_pop)
{
	Stack<double> stack0;
	stack0.push(1);
	ASSERT_NO_THROW(stack0.pop());
}

TEST(Stack, can_show)
{
	Stack<double> stack0(5);
	ASSERT_NO_THROW(stack0.show());
}

TEST(Stack, not_equal_to)
{
	Stack<double> stack1(5);
	Stack<double> stack2(5);
	stack1.push(1);
	stack1.push(3);
	stack2.push(2);
	EXPECT_NE(1, stack1 == stack2);
}

TEST(Stack, equal_to)
{
	Stack<double> stack1;
	Stack<double> stack2(stack1);
	
	EXPECT_EQ(1, stack1 == stack2);
}


