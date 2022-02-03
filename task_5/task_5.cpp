/*
5. Создать массив из 10 целых случайных чисел в диапазоне от 0 до 100. Найти
элемент, максимально близкий к среднему арифметическому значений
массива.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода
	srand(time(0));

	int min{ 0 };
	int max{ 100 };
	const int arr_1_Size{ 10 };

	int arr_1[arr_1_Size]{ 0 };

	for (int i = 0; i < arr_1_Size; i++) // заполняем 1 массив и выводим
	{
		arr_1[i] = rand() % (max - min + 1) + min;
		cout << arr_1[i] << ' ';
	}
	cout << endl;

	int average{ 0 }, sum{ 0 };

	for (int i = 0; i < arr_1_Size; i++)
		sum += arr_1[i];
	//cout << "sum = " << sum << endl;

	average = sum / arr_1_Size;
	cout << "Среднее арифметическое значение массива : " << average << endl;

	int dif{ 0 }, min_dif{ 101 }, closest_element_indx{ -1 };
	int i{ 0 };
	for (i = 0; i < arr_1_Size; i++)
	{
		dif = average - arr_1[i];
		if (dif < 0)
			dif = dif * -1;
		if (dif < min_dif)
		{
			min_dif = dif;
			closest_element_indx = i;
		}
		dif = 101;
	}

	cout << "Максимально близкий элемент к среднему арифметическому значений массива: " << arr_1[closest_element_indx] << endl;

	return 0;
}