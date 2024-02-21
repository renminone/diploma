#pragma once
#include <iostream>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

#define el1 el[i] == el[i - 1]
#define el2 (el[i] == el[i - 1]) || (el[i] == el[i - 2])
#define el3 (el[i] == el[i - 1]) || (el[i] == el[i - 2]) || (el[i] == el[i - 3])
#define el4 (el[i] == el[i - 1]) || (el[i] == el[i - 2]) || (el[i] == el[i - 3]) || (el[i] == el[i - 4])
#define el5 (el[i] == el[i - 1]) || (el[i] == el[i - 2]) || (el[i] == el[i - 3]) || (el[i] == el[i - 4]) || (el[i] == el[i - 5])
#define el6 (el[i] == el[i - 1]) || (el[i] == el[i - 2]) || (el[i] == el[i - 3]) || (el[i] == el[i - 4]) || (el[i] == el[i - 5]) || (el[i] == el[i - 6])
#define el7 (el[i] == el[i - 1]) || (el[i] == el[i - 2]) || (el[i] == el[i - 3]) || (el[i] == el[i - 4]) || (el[i] == el[i - 5]) || (el[i] == el[i - 6]) || (el[i] == el[i - 7])
#define el8 (el[i] == el[i - 1]) || (el[i] == el[i - 2]) || (el[i] == el[i - 3]) || (el[i] == el[i - 4]) || (el[i] == el[i - 5]) || (el[i] == el[i - 6]) || (el[i] == el[i - 7]) || (el[i] == el[i - 8])
#define MAX_PRIMES 1000000

class Checker
{
	long long n; //Число.
	long long* q; //Набор простых чисел.
	unsigned long long p; //Число

	
public:
	Checker(); //Конструктор.
	~Checker(); //Деструктор.
	long long legendreSymbol(long long a, long long p); //Символ Лежандра.
	long long power(long long a, long long b, long long mod); //Функция возведения в степень.
	void ng(); //Собрать новое число.
	//Тест Ферма
	bool fermtest(int k);
	void launchfermtest();
	//Тест Соловея-Штрассена.
	bool soloveytest(int k); 
	void launchsoloveytest();
	//Тест Эйлера	
	void eilertest(); //
	//Стандарт ГОСТ P 34.10-94
	void gosttest();
	void tests(); //Запуск тестов.
};
