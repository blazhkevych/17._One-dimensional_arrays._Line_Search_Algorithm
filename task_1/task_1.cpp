/*
1. Даны два массива размерности 10 и 8 соответственно, заполненные
случайными числами из диапазона от 0 до 20. Необходимо переписать в
третий массив общие элементы первых двух массивов без повторений.
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
	int max{ 20 };
	const int arr_1_Size{ 10 };
	const int arr_2_Size{ 8 };
	const int arr_3_Size{ 8 };

	int arr_1[arr_1_Size]{};
	int arr_2[arr_2_Size]{};
	int arr_3[arr_3_Size]{};

	for (int i = 0; i < arr_1_Size; i++) // заполняем 1 массив и выводим
	{
		arr_1[i] = rand() % (max - min + 1) + min;
		cout << arr_1[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < arr_2_Size; i++) // заполняем 2 массив и выводим
	{
		arr_2[i] = rand() % (max - min + 1) + min;
		cout << arr_2[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < arr_3_Size; i++) // заполняем 3 массив "-1"
		arr_3[i] = -1;

	for (int i = 0; i < arr_1_Size; i++)
	{
		for (int j = 0; j < arr_2_Size; j++)
		{
			if (arr_1[i] == arr_2[j])
			{
				for (int k = 0; k < arr_3_Size; k++)
				{
					if (arr_1[i] == arr_3[k])
						break;
					else
					{
						if (arr_3[k] == -1)
						{
							arr_3[k] = arr_1[i];
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < arr_3_Size; i++) // выводим 3 массив
	{
		if (arr_3[i] != -1)
			cout << arr_3[i] << ' ';
	}
	cout << endl;

	return 0;
}