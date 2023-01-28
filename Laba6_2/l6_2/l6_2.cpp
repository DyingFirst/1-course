// lab 6.2

#include <iostream>
#include <deque>
#include <string>

void task_1(std::string line) {
    // Полиндром деком
    bool answ = true;
    std::deque <char> deq_line;
    for (auto i : line)
        deq_line.push_back(i);

    // пробегаемся по деку 
    int len = round(deq_line.size() / 2.0);
    for (int i = 0; i < len; i++) {
        if (deq_line.front() == deq_line.back()) {
            //std::cout << deq_line.front() << '+' << deq_line.back() << '\n';
            if (deq_line.size() != 1) {
                deq_line.pop_front();
                deq_line.pop_back();
            }
            else if (deq_line.size() == 1) {
                deq_line.pop_front();
            }
        }
        else {
            //std::cout << deq_line.front() << '-' << deq_line.back() << '\n';
            answ = false;
        }
    }
    // проверка пустоты дека
    if (not deq_line.empty())
        answ = false;

    // вывод ответа
    if (answ)
        std::cout << "-> Yes";
    else
        std::cout << "-> No";
}

int main()
{
    std::cout << "Enter libe: ";
    std::string line_task1;
    getline(std::cin, line_task1);
    task_1(line_task1);

} // декью - двусторонняя очередь (можно прийти в начало и в конце и уйти можно и из начала и из конца)