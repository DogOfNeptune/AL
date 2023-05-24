#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int Random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void Arr_Fill(int* Arr, int Lenght) {
	for (int i = 0; i < Lenght; i++)
		Arr[i] = Random(0, 50000);
}

void Arr_Copy(int* Arr_A, int* Arr_B, int Lenght) {
	for (int i = 0; i < Lenght; i++)
		Arr_A[i] = Arr_B[i];
}

void Arr_Sort_Selection(int* Arr, int Lenght) {
	for (int i = 0; i < Lenght - 1; i++)
		for (int j = i + 1; j < Lenght; j++)
			if (Arr[j] < Arr[i])
				swap(Arr[i], Arr[j]);
}

void Arr_Sort_Insert(int* Arr, int Lenght) {
	for (int i = 1; i < Lenght; i++) {
		int key = Arr[i];

		int j;
		for (j = i - 1; j >= 0 && Arr[j] > key; j--)
			Arr[j + 1] = Arr[j];
	}
}

void Arr_Sort_Quick(int* Arr, int Lenght, int first, int last) {
	int middle = Arr[(first + last) / 2];
	int i = first;
	int j = last;

	do {
		while (Arr[i] < middle)
			i++;
		while (Arr[j] > middle)
			j--;

		if (i <= j) {
			swap(Arr[i], Arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > first)
		Arr_Sort_Quick(Arr, Lenght, first, j);
	if (i < last)
		Arr_Sort_Quick(Arr, Lenght, i, last);
}

void Arr_Print(int* Arr, int Lenght) {
	cout << "Елементи масиву: ";
	for (int i = 0; i < Lenght; i++)
		cout << Arr[i] << " ";
	cout << endl;
}

int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int Lenght;
	cout << "Введіть кількість елементів в масиві: ";
	cin >> Lenght;
	if (Lenght <= 0)
		return 0;

	int* Arr_Origin = new int[Lenght];
	int* Arr_Reserve = new int[Lenght];
	Arr_Fill(Arr_Origin, Lenght);
	Arr_Copy(Arr_Reserve, Arr_Origin, Lenght);

	cout << "Згенерований масив: " << endl;
	Arr_Print(Arr_Origin, Lenght);

	int Choice;
	unsigned int start_time, end_time = 0, search_time = 0;
	while (true) {
		cout << "1 - Сортування методом вставки" << endl;
		cout << "2 - Сортування методом швидкого сортування" << endl;
		cout << "3 - Сортування методом вибору" << endl;
		cout << "4 - Змінити значення в масиві" << endl;
		cout << "0 - Вихід" << endl;
		cout << "Ваш вибір: ";
		cin >> Choice;
		cout << endl;
		switch (Choice) {
		case 1:
			cout << "Метод Вставки" << endl << endl;
			
			start_time = clock();
			Arr_Sort_Insert(Arr_Origin, Lenght);
			end_time = clock();
			search_time = end_time - start_time;
			cout << "Час сортування: " << search_time << endl << endl;
			
			Arr_Print(Arr_Origin, Lenght);

			Arr_Copy(Arr_Origin, Arr_Reserve, Lenght);
			break;
		case 2:
			cout << "Метод Швидкого сортування" << endl << endl;
			
			start_time = clock();
			Arr_Sort_Quick(Arr_Origin, Lenght, 0, Lenght - 1);
			end_time = clock();
			search_time = end_time - start_time;
			cout << "Час сортування: " << search_time << endl << endl;

			Arr_Print(Arr_Origin, Lenght);

			Arr_Copy(Arr_Origin, Arr_Reserve, Lenght);
			break;
		case 3:
			cout << "Метод Вибору" << endl << endl;
			
			start_time = clock();
			Arr_Sort_Selection(Arr_Origin, Lenght);
			end_time = clock();
			search_time = end_time - start_time;
			cout << "Час сортування: " << search_time << endl << endl;

			Arr_Print(Arr_Origin, Lenght);

			Arr_Copy(Arr_Origin, Arr_Reserve, Lenght);
			break;
		case 4:
			Arr_Fill(Arr_Reserve, Lenght);
			Arr_Copy(Arr_Origin, Arr_Reserve, Lenght);

			cout << "Нові значення масиву: " << endl;
			Arr_Print(Arr_Origin, Lenght);
			
			break;
		case 0:
			return 0;
			break;
		}
	}

	delete[] Arr_Origin;
	delete[] Arr_Reserve;
	return 0;
}