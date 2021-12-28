// реализация функций и классов для вычисления арифметических выражений

#include "../include/arithmetic.h"
#include <cmath>
#include <string>

bool Token::operator!=(const Token& token0) const
{
	if ((*this) == token0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool Token::operator==(const Token& token0) const
{
	if (type == token0.type)
	{
		if (type == true)
		{
			return (val == token0.val);
		}
		else
		{
			return (op == token0.op);
		}
	}
	else
	{
		return 0;
	}
}

void Token::ShowToken()
{
	if (type)
	{
		std::cout << val;
	}
	else
	{
		std::cout << op;
	}
}

int Token::OperationWeight()
{
	if (op == "+")
	{
		return 0;
	}
	else if (op == "-")
	{
		return 0;
	}
	else if (op == "*")
	{
		return 1;
	}
	else if (op == "/")
	{
		return 1;
	}
	else if (op == "@")
	{
		return 2;
	}
	else
	{
		return -1;//To implement comparison in an empty stack (273 string)
	}
}

void Arithmetic::Show()
{
	for (int i = 0; i < line.size(); i++)
	{
		line[i].ShowToken();
	}
}

bool Arithmetic::SubstituteValues(Arithmetic& str0)
{
	bool flag = 0;
	for (int i = 0; i < line.size(); i++)
	{
		double value;
		Token saver(str0.line[i]);
		if (saver.GetOperation() == "x")
		{
			std::cout << "Enter x: ";
			std::cin >> value;

			for (int j = 0; j < line.size(); j++)
			{
				saver = str0.line[j];
				Token valT(value);
				if (saver.GetOperation() == "x")
				{
					str0.line[i] = valT;
				}
			}
			flag = 1;
			break;
		}
		
	}

	for (int i = 0; i < line.size(); i++)
	{
		double value;
		Token saver(str0.line[i]);
		if (saver.GetOperation() == "y")
		{
			std::cout << "Enter y: ";
			std::cin >> value;

			for (int j = 0; j < line.size(); j++)
			{
				saver = str0.line[j];
				Token valT(value);
				if (saver.GetOperation() == "y")
				{
					str0.line[i] = valT;
				}
			}
			flag = 1;
			break;
		}
		
	}

	for (int i = 0; i < line.size(); i++)
	{
		double value;
		Token saver(str0.line[i]);
		if (saver.GetOperation() == "z")
		{
			std::cout << "Enter z: ";
			std::cin >> value;

			for (int j = 0; j < line.size(); j++)
			{
				saver = str0.line[j];
				Token valT(value);
				if (saver.GetOperation() == "z")
				{
					str0.line[i] = valT;
				}
			}
			flag = 1;
			break;
		}
		
	}

	return flag;
}

void Arithmetic::TransformToTokens(std::string& str0)
{
	std::string stringSaver;
	double numberSaver;

	int i = 0; // Global Counter

	while (i < str0.length())
	{
		if (str0[i] == 'x' || str0[i] == 'y' || str0[i] == 'z')
		{
			Token variable(str0[i]);
			line.push_back(variable);
			i++;
		}
		else if (((str0[i] >= '0') && (str0[i] <= '9')) || str0[i] == '.')
		{
			int dotCounter = 0;

			while (((str0[i] >= '0') && (str0[i] <= '9')) || str0[i] == '.')
			{
				stringSaver += str0[i];
				i++;
				
				if (str0[i] == '.')
				{
					dotCounter++;
				}

				if (dotCounter > 1)
				{
					throw "More than two points";
				}
			}
			numberSaver = stof(stringSaver);
			Token numb0(numberSaver);
			line.push_back(numb0);
			stringSaver.clear();
		}
		else if (str0[i] == '*' || str0[i] == '/' || str0[i] == '+')
		{
			Token operation(str0[i]);
			line.push_back(operation);
			i++;
		}
		else if (str0[i] == '-')
		{
			if (i == 0)
			{
				Token unaryMinus('@');
				line.push_back(unaryMinus);
				i++;
			}
			else if ((line[line.size() - 1].GetOperation() != "x") && (line[line.size() - 1].GetOperation() != "y") && (line[line.size() - 1].GetOperation() != "z") && (line[line.size() - 1].GetOperation() != ")") && (line[line.size() - 1].GetType() != true))
			{
				Token unaryMinus('@');
				line.push_back(unaryMinus);
				i++;
			}
			else
			{
				Token minus(str0[i]);
				line.push_back(minus);
				i++;
			}
		}
		else if ((str0[i] == '(') || (str0[i] == ')'))
		{
			Token bracket(str0[i]);
			line.push_back(bracket);
			i++;
		}
		else if (str0[i] == ' ')
		{
			i++;
		}
		else
		{
			throw "Invalid character entered";
		}
	}

}

void Arithmetic::PostFix()
{
	std::vector<Token> PostFixLine;
	Stack<Token> opStack;

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i].GetType() == true)
		{
			PostFixLine.push_back(line[i]);
		}
		else if ((line[i].GetOperation() == "x") || (line[i].GetOperation() == "y") || (line[i].GetOperation() == "z"))
		{
			PostFixLine.push_back(line[i]);
		}
		else if (line[i].GetOperation() == "(" || line[i].GetOperation() == "@")
		{
			opStack.push(line[i]);
		}
		else if (line[i].GetOperation() == ")")
		{
			while ((opStack.show()) != '(')
			{
				Token saver(opStack.pop());
				PostFixLine.push_back(saver);
			}
			opStack.pop(); // Delete '('
		}
		else
		{
			if (!opStack.IsEmpty())
			{
				while ((opStack.show().OperationWeight() >= line[i].OperationWeight()) && !opStack.IsEmpty())//Here
				{
					Token saver(opStack.pop());
					PostFixLine.push_back(saver);
				}

			}

			opStack.push(line[i]);
		}
	}

	//Unloading the remaining operations
	while (!opStack.IsEmpty())
	{
		Token saver(opStack.pop());
		PostFixLine.push_back(saver);
	}
	
	//Changing the pointer
	line = PostFixLine;
}

double Arithmetic::firstCalcul()
{
	Stack<Token> stack0;
	Token tSaver1 , tSaver2;
	double first, second, result;

	for (int i = 0; i < line.size(); i++)
	{
		//value
		if (line[i].GetType() == true)
		{
			stack0.push(line[i].GetValue());
		}
		//unary minus
		else if (line[i].GetOperation() == "@")
		{
			tSaver1 = stack0.pop();
			result = (-1) * tSaver1.GetValue();
			stack0.push(result);
		}
		// * / + -
		else
		{
			tSaver1 = stack0.pop();
			tSaver2 = stack0.pop();
			first = tSaver1.GetValue();
			second = tSaver2.GetValue();

			if (line[i].GetOperation() == "*")
			{
				result = first * second;
			}
			else if (line[i].GetOperation() == "/")
			{
				result = second / first;
			}
			else if (line[i].GetOperation() == "+")
			{
				result = first + second;
			}
			else if (line[i].GetOperation() == "-")
			{
				result = second - first;
			}

			stack0.push(result);
		}
	}
	tSaver1 = stack0.pop();
	return tSaver1.GetValue();
}

bool Arithmetic::BracketsCalcul()
{
	int counter = 0;

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i].GetOperation() == "(")
		{
			if (i >= 1)
			{
				if ((line[i - 1].GetType() || (line[i - 1].GetOperation() == "x") || (line[i - 1].GetOperation() == "y") || (line[i - 1].GetOperation() == "z")))
				{
					throw "The number before the opening bracket";
				}
			}
			
			else if (i + 1 <= line.size() - 1)
			{
				if ((line[i + 1].GetOperation() == "/") || (line[i + 1].GetOperation() == "+") || (line[i + 1].GetOperation() == "-") || (line[i + 1].GetOperation() == "*"))
				{
					throw "Operation after the opening bracket";
				}
				else if (line[i + 1].GetOperation() == ")")
				{
					throw "No expression in brackets";
				}
			}
			
			counter++;
		}
		else if (line[i].GetOperation() == ")" && (counter >= 0))
		{
			if (i >= 1)
			{
				if (!line[i - 1].GetType())
				{
					throw "Operation before closer bracket";
				}
			}
			
			else if (i + 1 <= line.size() - 1)
			{
				if (line[i + 1].GetOperation() == "(")
				{
					throw "Opening bracket after closer bracket";
				}
				else if (line[i + 1].GetType() || (line[i + 1].GetOperation() == "x") || (line[i + 1].GetOperation() == "y") || (line[i + 1].GetOperation() == "z"))
				{
					throw "The number after the closer bracket";
				}
			}
			

			counter--;
		}
	}

	return (counter == 0);
}

double Arithmetic::CorrectionCalcul()
{
	if (line[0] == '+' || line[0] == '*' || line[0] == '/')
	{
		throw "The operation cannot be in the first place, except for the unary minus";
	}
	else if (line[line.size() - 1] == '+' || line[line.size() - 1] == '*' || line[line.size() - 1] == '/' || line[line.size() - 1] == '-')
	{
		throw "The operation cannot be in the last place";
	}
	else if (!BracketsCalcul())
	{
		throw "Brackets are placed incorrectly";
	}
	else
	{
		for (int i = 0; i < line.size() - 1; i++)
		{
			if ((line[i].GetOperation() == "+" || line[i].GetOperation() == "-" || line[i].GetOperation() == "*" || line[i].GetOperation() == "/") && (line[i + 1].GetOperation() == "+" || line[i + 1].GetOperation() == "*" || line[i + 1].GetOperation() == "/" || line[i + 1].GetOperation() == "-"))
			{
				throw "Operation after operation";
			}
			else if ((line[i].GetType() && line[i + 1].GetType()))
			{
				throw "Value after value";
			}
			else if ((line[i].GetType() && (line[i + 1].GetOperation() == "x" || line[i + 1].GetOperation() == "y" || line[i + 1].GetOperation() == "z")))
			{
				throw "Value after value";
			}
			else if ((line[i + 1].GetType() && (line[i].GetOperation() == "x" || line[i].GetOperation() == "y" || line[i].GetOperation() == "z")))
			{
				throw "Value after value";

			}
			else if (((line[i].GetOperation() == "x" || line[i].GetOperation() == "y" || line[i].GetOperation() == "z") && (line[i + 1].GetOperation() == "x" || line[i + 1].GetOperation() == "y" || line[i + 1].GetOperation() == "z")))
			{
				throw "Value after value";
			}
		}
	}
	return true;
}
