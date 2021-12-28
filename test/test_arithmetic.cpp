// тесты для вычисления арифметических выражений

#include "arithmetic.h"
#include <gtest.h>

TEST(Token, can_create_token)
{
	ASSERT_NO_THROW(Token token(5.0));
}

TEST(Token, can_show_token)
{
	Token token(5.0);
	ASSERT_NO_THROW(token.ShowToken());
}

TEST(Token, can_get_operation)
{
	Token token('+');
	ASSERT_NO_THROW(token.GetOperation());
}

TEST(Token, can_get_value)
{
	Token token(5.0);
	ASSERT_NO_THROW(token.GetValue());
}

TEST(Arithmetic, can_create_line)
{
	ASSERT_NO_THROW(Arithmetic ar);
}

TEST(Arithmetic, can_transform_to_tokens)
{
	Arithmetic ar;
	std::string st0 = "x+4*(3-2)+y";
	ASSERT_NO_THROW(ar.TransformToTokens(st0));
}

TEST(Arithmetic, can_create_postfix_entry)
{
	Arithmetic ar;
	std::string st0 = "2+3*(5-3)";
	ar.TransformToTokens(st0);
	ASSERT_NO_THROW(ar.PostFix());
}

TEST(Arithmetic, can_add_two_numbers)
{
	Arithmetic ar;
	std::string st0 = "250+1251";
	ar.TransformToTokens(st0);
	ar.PostFix();
	EXPECT_EQ(1501, ar.firstCalcul());
}

TEST(Arithmetic, can_multiply_two_numbers)
{
	Arithmetic ar;
	std::string st0 = "3*30";
	ar.TransformToTokens(st0);
	ar.PostFix();
	EXPECT_EQ(90, ar.firstCalcul());
}

TEST(Arithmetic, can_divide_two_numbers)
{
	Arithmetic ar;
	std::string st0 = "30/3";
	ar.TransformToTokens(st0);
	ar.PostFix();
	EXPECT_EQ(10, ar.firstCalcul());
}

TEST(Arithmetic, can_use_unary_minus)
{
	Arithmetic ar;
	std::string st0 = "-5";
	ar.TransformToTokens(st0);
	ar.PostFix();
	EXPECT_EQ(-5, ar.firstCalcul());
}

TEST(Arithmetic, can_use_unary_minus_with_divide_left)
{
	Arithmetic ar;
	std::string st0 = "-5/1";
	ar.TransformToTokens(st0);
	ar.PostFix();
	EXPECT_EQ(-5, ar.firstCalcul());
}

TEST(Arithmetic, can_use_unary_minus_with_divide_right)
{
	Arithmetic ar;
	std::string st0 = "5/-1";
	ar.TransformToTokens(st0);
	ar.PostFix();
	EXPECT_EQ(-5, ar.firstCalcul());
}

TEST(Arithmetic, you_can_not_use_the_last_opening_brackets)
{
	Arithmetic ar;
	std::string st0 = "3+1*(";
	ar.TransformToTokens(st0);
	ASSERT_ANY_THROW(ar.CorrectionCalcul());
}

TEST(Arithmetic, you_can_not_use_the_first_closing_brackets)
{
	Arithmetic ar;
	std::string st0 = ")*3+1";
	ar.TransformToTokens(st0);
	ASSERT_ANY_THROW(ar.CorrectionCalcul());
}

TEST(Arithmetic, can_not_be_empty_between_brackets)
{
	Arithmetic ar;
	std::string st0 = "1+5*()+8";
	ar.TransformToTokens(st0);
	ASSERT_ANY_THROW(ar.CorrectionCalcul());
}

TEST(Arithmetic, you_can_not_have_two_operations_in_a_row)
{
	Arithmetic ar;
	std::string st0 = "1+*5";
	ar.TransformToTokens(st0);
	ASSERT_ANY_THROW(ar.CorrectionCalcul());
}

TEST(Arithmetic, can_use_space)
{
	Arithmetic ar;
	std::string st0 = "5 + 5";
	ASSERT_NO_THROW(ar.TransformToTokens(st0));
}

TEST(Arithmetic, can_use_variables)
{
	Arithmetic ar;
	std::string st0 = "x*y";
	ar.TransformToTokens(st0);
	ASSERT_NO_THROW(ar.CorrectionCalcul());
}

TEST(Arithmetic, can_not_be_more_than_one_point)
{
	Arithmetic ar;
	std::string st0 = "6/1.2.3";
	ASSERT_ANY_THROW(ar.TransformToTokens(st0));
}



