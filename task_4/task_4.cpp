/*
4. Создать массив из 10 случайных чисел в диапазоне от -20 до 20. Заменить все
отрицательные значения их модулями.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода
	srand(time(0));

	int min{ -20 };
	int max{ 20 };
	const int arr_1_Size{ 10 };

	int arr_1[arr_1_Size]{ 0 };

	for (int i = 0; i < arr_1_Size; i++) // заполняем 1 массив и выводим
	{
		arr_1[i] = rand() % (max - min + 1) + min;
		cout << arr_1[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < arr_1_Size; i++)
	{
		if (arr_1[i] >= 0) // Для положительного числа и нуля модуль равен самомý числу
			arr_1[i] = arr_1[i];
		else if (arr_1[i] < 0) // а для отрицательного – противоположному числу;
			arr_1[i] = arr_1[i]*-1;
	}

	for (int i = 0; i < arr_1_Size; i++) // выводим 1 массив с модулями
		cout << arr_1[i] << ' ';

	return 0;
}