
#include <cmath>
#include <vector>
#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;

bool is_palindrome(int number) {
	int N = int(log10(abs(number))) + 1; //int - приведение к целой части
	int divisor = pow(10, N - 1);

	// >1, чтобы не анализировать однозначные числа (они и так палиндромы)
	while (divisor > 1) {
		int max = number / divisor;
		int min = number % 10;

		number %= divisor; //убираем первое число
		number /= 10; //убираем последнее число

		divisor /= 100; //срезаем divisor ввиду уменьшения числа после предыдущих операций

		if (min != max)
			return false; // no - не палиндром
	}

	return true;// yes - палиндром
}

/*//просто ответ на задание
int main() {
	vector<int> array;
	int N;

	cout << "Enter N: ";
	cin >> N;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		array.push_back(number);
		if (is_palindrome(number))
			array.push_back(number);
	}

	for (int i = 0; i < array.size(); i++)
		cout << array[i] << '\n';

	return 0;
}*/


//для демонстрации времени проверка на палиндромы

int main() {
	vector<int> array;
	int N;

	/*cout << "Enter N: ";
	cin >> N;*/

	N = 10000; //чем меньше значение, тем быстрее выполнение

	for (int i = 0; i < N; i++) {
		//int number;
		//cin >> number;
		//array.push_back(number);
		array.push_back(rand());
	}
	
	//ввод и вывод не должны засчитываться, потому что зависят от ОС
	clock_t start = clock();

	for (int i = 0; i < N; i++) 
		if (is_palindrome(array[i]))
			array.push_back(array[i]);

	clock_t end = clock();

	cout << double(end - start) / CLOCKS_PER_SEC << endl; //измерение в тактах процессора

	system("pause");

	for (int i = 0; i < array.size(); i++)
		cout << array[i] << '\n';

	return 0;
}
