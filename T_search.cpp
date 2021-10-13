#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*Реализуйте шаблонную функцию для двоичного поиска в массиве
Протестируйте на массиве строк и чисел.
Строки читать из файла до конца потока!
Числа генерить случайно*/

template <typename T1, typename T2>
int search(T1* arr, int size, T2 elem) {
	bool flag = false;
	int l = 0, r = size - 1, mid=0;
	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2;
		if (arr[mid] == elem) flag = true;
		if (arr[mid] > elem) r = mid - 1;
		else l = mid + 1;
	}	
	return mid+1;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	char str[100];
	int size = 30;
	int den = 33;
	int* Arr = new int[size];
	for (int i = 0; i < size; i++){
		Arr[i] = rand() % 32 + den;
		den += 32;
		cout << Arr[i] << endl;
	}
	cout << "Введите число для поиска: " << endl;
	int elem;
	cin >> elem;
	cout << search(Arr, size, elem);
	ifstream fin("test.txt");
	fin.getline(str, 100);
	fin.close();
	int len = strlen(str);
	cout << endl << "Введите букву для поиска: " << endl;
	char bukva;
	cin >> bukva;
	cout << search(str, len, bukva);
}
