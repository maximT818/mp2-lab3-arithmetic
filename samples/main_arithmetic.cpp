// реализация пользовательского приложения
#pragma once
#include "arithmetic.h"

int main()
{
	Arithmetic result;
	std::string str;

	std::cout << "Enter tokens line: " << std::endl;
	getline(std::cin, str);

	result.TransformToTokens(str);

	if (result.CorrectionCalcul())
	{
		result.PostFix();
		std::cout << std::endl;

		result.Show();
		std::cout << std::endl;

		result.SubstituteValues(result);
		std::cout << "Result: " << result.firstCalcul();
	}

  return 0;
}
