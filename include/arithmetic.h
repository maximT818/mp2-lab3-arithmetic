// объ€вление функций и классов дл€ вычислени€ арифметических выражений



#pragma once
#include "stack.h"

#include <string>
#include <vector>
#include <iostream>

class Token
{
private:
	std::string op; //operation
	bool type; //value_type?
	double val; // value

public:
	Token() {}
	Token(const double& val0) { val = val0; type = true; }
	Token(const char& op0) { op = op0; type = false; }
	Token(const std::string& op0) { op = op0; type = false; }

	void ShowToken();

	std::string GetOperation()
	{
		return op;
	}

	bool GetType()
	{
		return type;
	}

	double GetValue()
	{
		return val;
	}

	bool operator==(const Token& token0) const;

	bool operator!=(const Token& token0) const;

	int OperationWeight();

};

class Arithmetic
{
private:
	std::vector<Token> line;
public:
	Arithmetic() {};
	void PostFix();
	double firstCalcul();
	bool BracketsCalcul();
	double CorrectionCalcul();
	void Show();
	void TransformToTokens(std::string& str0);
	bool SubstituteValues(Arithmetic& str0);
};