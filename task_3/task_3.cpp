/*
3. Создать массив из 20 случайных чисел в диапазоне от -10 до 20. Определить
максимальное количество подряд идущих положительных элементов, не
прерываемых ни нулями, ни отрицательными числами. Вывести найденный
фрагмент.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода
	srand(time(0));

	int min{ -10 };
	int max{ 20 };
	const int arr_1_Size{ 20 };

	int arr_1[arr_1_Size]{ -5,  15, 0,  -15 ,8, -10, 0, -1, 16, 12, 0 , 20, 6, 8, 17, 4, 10, 3,19 ,16 };

	for (int i = 0; i < arr_1_Size; i++) // заполняем 1 массив и выводим
	{
		arr_1[i] = rand() % (max - min + 1) + min;
		cout << arr_1[i] << ' ';
	}
	cout << endl;

	int start_position{ 0 }, max_start_position{ 0 },
		amount_of_numbers{ 0 }, max_amount_of_numbers{ 0 };
	for (int i = 0; i < arr_1_Size; i++) // 1й массив 
	{
		if (arr_1[i] > 0)
		{
			amount_of_numbers++;
			continue;
		}
		else
		{
			if (amount_of_numbers > max_amount_of_numbers)
			{
				max_amount_of_numbers = amount_of_numbers;
				max_start_position = start_position;
			}
		}
		amount_of_numbers = 0;
		start_position = i;
	}

	if (amount_of_numbers > max_amount_of_numbers) // для цепочки в конце
	{
		max_amount_of_numbers = amount_of_numbers;
		max_start_position = start_position;
	}

	cout << "Максимальная длина цепочки: " << max_amount_of_numbers << endl;

	if (max_start_position == 0) // распределение вывода на вывод для "цепи в начале" и вывод для "цепи в средине и конце"
	{
		for (int i = max_start_position; i < max_start_position + max_amount_of_numbers; i++) // выводим фрагмент для цепи в начале
			cout << arr_1[i] << ' ';
	}
	else
	{
		for (int i = max_start_position + 1; i < max_start_position + max_amount_of_numbers + 1; i++) // выводим фрагмент для цепи в средине и конце
			cout << arr_1[i] << ' ';
	}
	return 0;
}