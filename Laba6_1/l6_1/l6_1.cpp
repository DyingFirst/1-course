#include <string>
#include <iostream>
#include <stack>
void task_stack(std::string str) {
	std::stack <int> steck;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' or str[i] == '[' or str[i] == '{') {
			steck.push(str[i]); // добавляется новый элемент, указывающий на элемент, бывший до этого головой
		}
		else if (str[i] == ')' or str[i] == ']' or str[i] == '}') {
			if ((steck.top() == '(' and str[i] == ')') or (steck.top() == '{' and str[i] == '}') or (steck.top() == '[' and str[i] == ']')) {
				steck.pop(); // убирается первый, а головным становится тот, на который был указатель у этого объекта
			}
		}
	}
	if (steck.empty()) { //проверка на пустоту
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	std::string str;
	std::cout << "Введите строку: ";
	std::getline(std::cin, str);
	task_stack(str);
}
//Стек — это стандартный адаптер контейнера C++, предназначенный для использования в контексте LIFO