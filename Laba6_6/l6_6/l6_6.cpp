// lab 6.6

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map <std::string, int> data;
    data.insert({ "*", 0 });
    std::string line;
    std::cout << "Line: ";
    getline(std::cin, line);
    line += ' ';

    std::string tmp_line = "";
    for (auto i : line) {
        if (i != ' ' and i != ',' and i != '.')
            tmp_line += tolower(i);
        else {
            if (tmp_line != "") {
                // проверка вхождения слова в map
                if (data.find(tmp_line) != data.end()) {
                    // слово есть
                    data[tmp_line]++;
                }
                else {
                    data.insert({ tmp_line, 1 });
                }
                data["*"]++;
            }
            tmp_line = "";
        }
    }

    //
    std::cout << "\nAnswer:\n\tAll words: " << data["*"] << '\n';
    for (auto i = ++data.begin(); i != data.end(); i++) {
        std::cout << '\t' << i->first << ": " << i->second / (data["*"] / 100.0) << "%\n";
    }
}