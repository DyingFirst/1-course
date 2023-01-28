#include <iostream>
#include <set>
#include <map>
#include <string>
void task_set() {
	std::set <std::string> st;
	std::map <std::string, int> letters;
	std::string str;
	std::string ac;
	int test = 0;
	std::cout << "Введите аккаунт и результат теста, чтобы закончить ввод введите 0\n";
	std::getline(std::cin, str);
	while (str != "0") {
		int a = str.find_last_of(' ');
		ac = str.substr(0, a);
		test = stoi(str.substr(a + 1, str.length()));
		if (st.count(ac) == 0) {
			letters.insert(make_pair(ac, test));
		}
		st.insert(ac);
		std::getline(std::cin, str);
	}
	for (auto f : st) {
		std::cout << "Аккаунт " << f << ", Результат теста - " << letters[f] << '\n';
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	task_set();
}
