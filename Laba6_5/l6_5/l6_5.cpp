// lab 6.5

#include <iostream>
#include <list>
#include <map>
#include <string>


int main()
{
    std::map <std::string, std::string> poz;
    std::list <std::string> data;
    std::string line;

    std::cout << "Student: ";
    getline(std::cin, line);
    while (line != "-") {
        if (poz.find(line.substr(0, line.find(' '))) != poz.end()) {
            // слово есть
            auto num = ++find(data.begin(), data.end(), poz[line.substr(0, line.find(' '))]);
            data.insert(num, line);
            // меняем последню строку
            poz[line.substr(0, line.find(' '))] = line;
        }
        else {
            // слова нет 
            data.push_back(line);
            poz.insert(std::pair<std::string, std::string>(line.substr(0, line.find(' ')), line));
        }

        std::cout << "Student: ";
        getline(std::cin, line);
    }

    // вывод листа
    std::cout << "\nAnswer:\n";
    for (auto i = data.begin(); i != data.end(); i++) {
        std::cout << *i << '\n';
    }
}