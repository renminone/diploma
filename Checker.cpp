#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "Checker.h"

Checker::Checker()
{
	//n = 10000019;
	std::cout << "Идёт генерация числа!" << std::endl;
	Sleep(2000);
	srand(time(0)); //Установка случайного ключа генерации.
	long long start = 10000000; //Минимальная граница.
	long long end = 9999999999; //Максимальная граница.
	n = rand() % (end - start + 1) + start; //Генерация числа.
	std::cout << "Сгенерировано число: " << n << std::endl << std::endl;
}

Checker::~Checker()
{
	std::cout << "Работа программы завершена!" << std::endl;
}

long long Checker::power(long long a, long long b, long long mod) {
	long long result = 1;
	a = a % mod;
	while (b > 0) {
		if (b % 2 == 1)
			result = (result * a) % mod;
		b = b >> 1;
		a = (a * a) % mod;
	}
	return result;
}

void Checker::ng()
{
	std::cout << "Идёт генерация нового числа!" << std::endl;
	Sleep(2000);
	srand(time(0)); //Установка случайного ключа генерации.
	long long start = 10000000; //Минимальная граница.
	long long end = 9999999999; //Максимальная граница.
	n = rand() % (end - start + 1) + start; //Генерация числа.
	std::cout << "Сгенерировано число: " << n << std::endl << std::endl;
}

bool Checker::fermtest(int k)
{
	std::cout << "Тест Ферма." << std::endl;
	// Базовые случаи
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// Проводим k тестов
	for (int i = 0; i < k; ++i) {
		// Выбираем случайное число a в интервале [2, n-2]
		long long a = 2 + rand() % (n - 3);

		// Проверяем условие малой теоремы Ферма
		if (power(a, n - 1, n) != 1)
			return false;
	}

	// Если все тесты прошли успешно, то число вероятно простое
	return true;
}

void Checker::launchfermtest()
{
	int start = clock();
	int bitLength = static_cast<int>(log2(n)) + 1;
	// Выбираем количество итераций в зависимости от битовой длины
	int iterations;
	if (2 * bitLength > 5)
		iterations = 2 * bitLength;
	else iterations = 5;
	if (fermtest(iterations)) std::cout << n << " вероятно простое число." << std::endl;
	else std::cout << n << " составное число." << std::endl;
	int end = clock();
	int t = (end - start);
	std::cout << "Время выполнения заняло " << t << " ms." << std::endl << std::endl;
}

long long Checker::legendreSymbol(long long a, long long p) {
	long long ls = 1;
	a = a % p;
	if (a < 0)
		a = a + p;
	while (a != 0) {
		while (a % 2 == 0) {
			a = a / 2;
			if (p % 8 == 3 || p % 8 == 5)
				ls = -ls;
		}
		std::swap(a, p);
		if (a % 4 == 3 && p % 4 == 3)
			ls = -ls;
		a = a % p;
	}
	return (p == 1) ? ls : 0;
}

bool Checker::soloveytest(int k)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 0; i < k; ++i) {
		// Выбираем случайное число a в интервале [2, n-2]
		long long a = 2 + rand() % (n - 3);

		// Вычисляем символ Лежандра
		long long legendre = legendreSymbol(a, n);

		// Вычисляем символ Лежандра по малой теореме Штрассена
		long long mod_result = power(a, (n - 1) / 2, n);

		// Проверяем условие теста Соловея-Штрассена
		if (legendre == 0 || mod_result != legendre)
			return false;
	}

	// Если все тесты прошли успешно, то число вероятно простое
	return true;
}

void Checker::launchsoloveytest()
{
	std::cout << "Тест Соловея-Штрассена." << std::endl;
	int start = clock();
	int bitLength = static_cast<int>(log2(n)) + 1;
	// Выбираем количество итераций в зависимости от битовой длины
	int iterations;
	if (2 * bitLength > 5)
		iterations = 2 * bitLength;
	else iterations = 5;
	if (soloveytest(iterations)) std::cout << n << " вероятно простое число." << std::endl;
	else std::cout << n << " составное число." << std::endl;
	int end = clock();
	int t = (end - start);
	std::cout << "Время выполнения заняло " << t << " ms." << std::endl << std::endl;
}

void Checker::eilertest()
{
	long long f;
	bool det = false;
	srand(time(0));
	int start = 1, end = 5, i = 0;
	long long startg = 10000000, endg = 9999999999;
	int k = rand() % (end - start + 1) + start;
	q = new long long[k];
	long long* m;
	bool* simple;
	int cs = 0;
	int* el;
	int b;

	int sttime = clock();
	while (i < k) {
		f = rand() % (endg - startg + 1) + startg; //Генерация числа.

		// Проверка делимости числа на простые числа из массива primes
		bool primes[MAX_PRIMES]; // Массив для хранения простых чисел
		bool is_prime = true;
		memset(primes, true, sizeof(primes));
		primes[0] = primes[1] = false; // 0 и 1 не являются простыми числами

		for (int p = 2; p * p < MAX_PRIMES; ++p) {
			if (primes[p]) {
				for (int i = p * p; i < MAX_PRIMES; i += p) {
					primes[i] = false;
				}
			}
		}

		for (int p = 2; p * p <= f; ++p)
		{
			if (primes[p] && f % p == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
		{
			q[i] = f;
			i++;
		}
	}

	int h = rand() % (k - start + 1) + start;
	m = new long long[h];
	//Выбор элементов из q и перенос в m.
	if (h == k)
	{
		for (int i = 0; i < h; i++)
			m[i] = q[i];
	}
	else
	{
		el = new int[h];
		for (int i = 0; i < h; i++)
			el[i] = 0;

		for (int i = 0; i < h; i++)
		{
			switch (i)
			{
			case 0:
				el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 1:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el1)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 2:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el2)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 3:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el3)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 4:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el4)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 5:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el5)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 6:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el6)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 7:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el7)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			case 8:
				el[i] = rand() % (k - 0 + 1) + 0;
				while (el8)
					el[i] = rand() % (k - 0 + 1) + 0;
				break;
			}
		}
		for (int i = 0; i < h; i++)
		{
			int r = el[i];
			m[i] = q[i];
		}
	}
	//Подсчёт числа p
	for (int i = 0; i < h; i++)
	{
		if (i == 0)
			p = m[i];
		else p *= m[i];
	}
	p += 1;

	simple = new bool[h];

#pragma omp parallel for 
	for (b = 2; b < p; b++)
	{
		if (power(b, p - 1, p) == (1 % p))
			if (power(b, (p - 1) / m[i], p))
			{
				simple[i] = true;
			}
			else simple[i] = false;
		else simple[i] = false;
	}
	for (i = 0; i < h; i++)
	{
		if (simple[i] == true)
			cs++;
	}

	if (cs == h)
	{
		std::cout << "Число " << p << " простое." << std::endl;
	}
	else
	{
		std::cout << "Число " << p << " составное." << std::endl;
	}
	int endtime = clock();
	int t = (endtime - sttime);
	std::cout << "Время выполнения заняло " << t << " ms." << std::endl << std::endl;
}

void Checker::gosttest()
{
	int sttime = clock();
	srand(time(0));
	long long x, N;
	while (true)
	{
		x = rand() % (9999999999 - 10000000 + 1) + 10000000;
		if (x % 2 != 0)
			break;
	}
	while (true)
	{
		N = rand() % (9999999999 - 10000000 + 1) + 10000000;
		if ((N % 2 == 0) && ((x * N + 1) < ((2 * x + 1) * (2 * x + 1))))
			break;
	}
	p = x * N + 1;
	if (((power(2, x * N - 1, x * N)) == (1 % p)) && ((power(2, N - 1, N) != (1 % p))))
	{
		std::cout << "Число " << p << " простое." << std::endl;
	}
	else std::cout << "Число " << p << " составное." << std::endl;
	int endtime = clock();
	int t = (endtime - sttime);
	std::cout << "Время выполнения заняло " << t << " ms." << std::endl << std::endl;
}

void Checker::tests()
{
	launchfermtest();
	launchsoloveytest();
	eilertest();
	gosttest();
}
