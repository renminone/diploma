#include <iostream>
#include <conio.h>
#include "Checker.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	char again = 'E';
	Checker C;
	while (true)
	{
		C.tests();
		while ((again != 'Y') && (again != 'N'))
		{
			std::cout << "Хотите ли вы провести новый тест для нового числа? Y/N: ";
			std::cin >> again;
			if (again == 'Y')
			{
				C.ng();
			}
			else
			{
				if (again == 'N') break;
				else std::cout << "Неверный ввод!" << std::endl;
			}
		}
		if (again == 'N') break;
		again = 'E';
	}
	return 0;
}
