// реализация пользовательского приложения
#pragma once
#include "arithmetic.h"

int main()
{
	try {
		
		
		std::string check = " ";

		do
		{
			Arithmetic result;
			Arithmetic result_0;
			std::string str = " ";
			bool flag;

			std::cout << "Enter tokens line: " << std::endl;
			std::cin >> str;

			result.TransformToTokens(str);

			if (result.CorrectionCalcul())
			{
				std::string check2 = "yes";
				result.PostFix();
				std::cout << std::endl;

				result.Show();
				std::cout << std::endl;

				result_0 = result;

				flag = result.SubstituteValues(result);
				std::cout << "Result: " << result.firstCalcul();
				

				while ((check2 == "yes") && flag)
				{
					
					std::cout << std::endl;
					std::cout << "Do you want to substitute other values?" << std::endl;
					std::cout << "If yes, then enter yes " << std::endl;
					std::cin >> check2;
					if (check2 == "yes")
					{
						result = result_0;
						result.SubstituteValues(result);
						std::cout << "Result: " << result.firstCalcul();
					}
					

				}
			}

			std::cout << std::endl;
			std::cout << "Do you want to get out?" << std::endl;

			std::cout << "If yes, then enter yes " << std::endl;
			std::cin >> check;

			std::cout << std::endl;

		}while (check != "yes");
		
	}
	catch (char* er)
	{
		std::cout << er << std::endl;
	}

  return 0;
}
