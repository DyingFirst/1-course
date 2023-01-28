#include <iostream>
#include <string>

struct Struct1 {
	std::string name, surname;
	int int_age;

	Struct1(std::string one, std::string two, int three) {
		this->int_age = three;
		this->name = one;
		this->surname = two;
	}

	std::string print() {
		return "[" + this->name + ", " + this->surname + ", " + std::to_string(this->int_age) + "]";
	}
	auto operator[] (std::string column) {
		if (column == "name") { return this->name; }
		else if (column == "surname") { return this->surname; }
		else if (column == "age") { return std::to_string(this->int_age); }
	}
};

bool compare(Struct1 lhs, Struct1 rhs, std::string col = "")
{
	if (col == "age") return (lhs.int_age < rhs.int_age);
	else return (lhs[col] < rhs[col]);
}

template <typename T>
bool compare(T lhs, T rhs, std::string col = "")
{
	if (col == "") return (lhs < rhs);
}

//шаблонная функция для структуры
template <typename T>
void qsortRecursive(T* arr, int size, std::string col = "") {
	int i = 0; //индекс начала
	int j = size - 1; //индекс конца
	auto mid = arr[size / 2]; //центральный элемент массива
	do {
		while (compare(arr[i], mid, col)) {
			i++;
		}
		while (compare(mid, arr[j], col)) {
			j--;
		}
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}

	} while (i <= j);
	if (j > 0) {
		//Левый кусок
		qsortRecursive(arr, j + 1, col);
	}
	if (i < size) {
		//Правый кусок
		qsortRecursive(&arr[i], size - i, col);
	}
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	// сортировка данных типа char
	std::cout << "\x1B[31m" << "Сортировка данных типа char" << "\033[0m" << std::endl;
	char data_1[7] = { 'a', 'b', 'c', 'z', 'e', 'o', 'p' };
	qsortRecursive(data_1, 7);
	std::cout << "\x1B[33m" << "{ " << "\033[0m ";
	for (auto i : data_1) { std::cout << "\x1B[33m" << i << "\033[0m "; }
	std::cout << "\x1B[33m" << "}" << "\033[0m " << std::endl;
	// сортировка данных типа int
	std::cout << "\x1B[31m" << "Сортировка данных типа int" << "\033[0m" << std::endl;
	int data_2[8] = { 5, 3, 5, 6, 3, 1, 6, 9 };
	qsortRecursive(data_2, 8);
	std::cout << "\x1B[33m" << "{ " << "\033[0m ";
	for (auto i : data_2) { std::cout << "\x1B[33m" << i << "\033[0m "; }
	std::cout << "\x1B[33m" << "}" << "\033[0m " << std::endl;
	// сортировка данных типа float
	std::cout << "\x1B[31m" << "Сортировка данных типа float" << "\033[0m" << std::endl;
	float data_3[16] = { 5.6, 3.1, 9.4, 9.4, 5.1, 4.5, 9.5, 4.3, 6.1, 6.1, 7.5, 6.3, 1.2, 4.3, 8.1, 6.5 };
	qsortRecursive(data_3, 16);
	std::cout << "\x1B[33m" << "{ " << "\033[0m ";
	for (auto i : data_3) { std::cout << "\x1B[33m" << i << "\033[0m "; }
	std::cout << "\x1B[33m" << "}" << "\033[0m " << std::endl;
	// сортировка по имени
	std::cout << "\x1B[31m" << "Сортировка по имени" << "\033[0m" << std::endl;
	Struct1 data_0[10] = { {"Кирилл", "Осин", 18},
						{"Дмитрий", "Белюченко", 18},
						{"Диана", "Паринова", 19},
						{"Алишер", "Кудайбергенов", 19},
						{"Иван", "Иванов", 49},
						{"Мирон", "Янович", 43},
						{"Алексей", "Долматов", 43},
						{"Мария", "Афанасьевна", 8},
						{"Эвелина", "Матях", 23},
						{"Иван", "Сазонов", 93} };
	qsortRecursive(data_0, 10, "name");
	for (auto i : data_0) { std::cout << "\x1B[32m" << i.print() << "\033[0m" << std::endl; }
	std::cout << "\x1B[31m" << "Сортировка по фамилии" << "\033[0m" << std::endl;
	// сортировка по фамилии
	Struct1 data_5[10] = { {"Кирилл", "Осин", 18},
					{"Дмитрий", "Белюченко", 18},
					{"Диана", "Паринова", 19},
					{"Алишер", "Кудайбергенов", 19},
					{"Иван", "Иванов", 49},
					{"Мирон", "Янович", 43},
					{"Алексей", "Долматов", 43},
					{"Мария", "Афанасьевна", 8},
					{"Эвелина", "Матях", 23},
					{"Иван", "Сазонов", 93} };
	qsortRecursive(data_5, 10, "surname");
	for (auto i : data_5) { std::cout << "\x1B[32m" << i.print() << "\033[0m" << std::endl; }
	std::cout << "\x1B[31m" << "Сортировка по возрасту" << "\033[0m" << std::endl;
	// сортировка по возрасту
	Struct1 data_6[10] = { {"Кирилл", "Осин", 18},
					{"Дмитрий", "Белюченко", 18},
					{"Диана", "Паринова", 19},
					{"Алишер", "Кудайбергенов", 19},
					{"Иван", "Иванов", 49},
					{"Мирон", "Янович", 43},
					{"Алексей", "Долматов", 43},
					{"Мария", "Афанасьевна", 8},
					{"Эвелина", "Матях", 23},
					{"Иван", "Сазонов", 93} };
	qsortRecursive(data_6, 10, "age");
	for (auto i : data_6) { std::cout << "\x1B[32m" << i.print() << "\033[0m" << std::endl; }
}