#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;     // string - тип данных, (массив символов)


bool task_1(char arr[], int k) {           // bool - потому что функция возвращает логическое значение (true/false)
	char vsp[255];
	int sch = 0;
	for (int i = k - 1; i >= 0; i--) {     // k - переменная которая хранит индекс положении точки.  i = k - 1 (чтобы мы начинали сравнение с символа  а не с точки)
		vsp[sch] = arr[i];
		sch++;
	}
	for (int i = 0; i < k; i++) {
		if (vsp[i] != arr[i]) {
			return false;
		}
	}
	return true;
}

void task_2(char arr[], int k) {    // Передаем массив и положение точки
	cout << "Enter a substring: ";
	string str;
	cin >> str;
	int sch = 0;
	int sch2 = 0;
	int sch3 = 0;
	int mass[255];
	int perem = 0;
	for (int i = 0; i < k; i++) {
		if (arr[i] == str[sch]) {
			sch2++;
			sch++;
			if (sch == 1) {
				mass[sch3] = i;
			}
			if (sch2 == str.size()) {
				perem++;
				sch3++;
				sch = 0;              // Обнуляем чтобы не выйти за пределы строки. 
				sch2 = 0;
			}
		}
		else {
			sch2 = 0;
			sch = 0;
		}

	}
	cout << "The entered substring is found in the following places: " << endl;
	cout << "[";
	for (int i = 0; i < perem; i++) {
		cout << mass[i];
		if (i != perem - 1) {    // Если проверяем елемент и он является последним то запятая не выводится.
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

void task_3(char arr[], int k) {
	cout << "Enter the key for the Caesar cipher: ";
	int key = 0;
	cin >> key;
	for (int i = 0; i < k; i++) {                                 // k - индекс на котором стоит точка
		if (arr[i] + key > 'z') {
			cout << (char)(('a' - 1) + ((arr[i] + key) % 'z'));   // возвращение в начало алфавита в случае выхода за пределы 
		}
		else {
			cout << (char)(arr[i] + key);     // просто добовляем ключ (если не выходим за пределы)
		}
	}
	cout << endl;
}
void task_4(char arr[], int k) {
	bool flag = false;                    // вводим флаг false (чтобы не было черты в самом начале строки)
	for (int i = 0; i < k; i++) {
		if (arr[i] == '"') {
			if (flag) {
				cout << " | ";
			}
			flag = true;
			i++;
			while (arr[i] != '"') {
				cout << arr[i];
				i++;
			}
		}
	}
	cout << endl;
}

int main() {         // Подключаем функцию позволяющия выводить русскоязычные слова 
	int n;
	bool flag = true;

	char arr[255];
	int i = 0;
	cout << "Enter symbols array: ";
	cin >> arr[i];
	while (arr[i] != '.') {
		i++;
		cin >> arr[i];
	}

	while (flag) {
		cout << "Enter the task number(enter 0 for exit): ";
		cin >> n;

		switch (n) {
		case 1:
			if (task_1(arr, i)) {
				cout << "This line is a palindrome \n";
			}
			else {
				cout << "This line is not a palindrome \n";
			}
			break;
		case 2: task_2(arr, i);
			break;
		case 3: task_3(arr, i);
			break;
		case 4: task_4(arr, i);
			break;
		case 0:
			flag = false;
			break;
		}
	}
}