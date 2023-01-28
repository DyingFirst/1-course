// lab 5.3

#include "matrix.h"
#include <iostream>
#include <clocale>

int main() {
    std::cout << "1) Input\n"
        << "2) Auto input\n"
        << "3) Output\n"
        << "4) Get elim&size\n"
        << "5) Binary minus\n"
        << "6) Unary minus\n"
        << "7) Sum\n"
        << "8) Mult by num\n"
        << "9) Trace\n"
        << "10) Mult\n"
        << "11) Det\n"
        << "12) >>\n"
        << "13) <<\n"
        << "14) Element sum\n"
        << "15) Element difference\n"
        << "16) Exit\n";
    matrix matr_0;

    int num = 0;
    while (true) {
        std::cout << "\nEnter menu num: ";
        std::cin >> num;

        switch (num) {
        case 1: {
            // простой воод
            matr_0.input();
            break;
        }
        case 2: {
            // ввод с размерностью (автозаполнение) 
            int n;
            std::cout << "Enter size: ";
            std::cin >> n;
            matr_0.input(n);
            break;
        }
        case 3: {
            // Вывод 
            matr_0.print();
            break;
        }
        case 4: {
            // получение элемента
            int i, j;
            std::cout << "Enter i&j: ";
            std::cin >> i >> j;
            std::cout << matr_0.get_elem(i, j) << endl;
            std::cout << matr_0.get_size() << endl;
            break;
        }
        case 5: {
            // бинарный минус
            matrix matr_2;
            matr_2.input();
            matr_0 - matr_2;
            break;
        }
        case 6: {
            // унарный минус
            -matr_0;
            break;
        }
        case 7: {
            // сложение матриц
            matrix matr_2;
            matr_2.input();
            matr_0 + matr_2;
            break;
        }
        case 8: {
            // умножение на число
            int number;
            std::cout << "Enter num: ";
            std::cin >> number;
            matr_0* number;
            break;
        }
        case 9: {
            // след
            std::cout << matr_0.trace() << endl;
            break;
        }
        case 10: {
            // премножение
            matrix matr_2;
            matr_2.input();
            matr_0* matr_2;
            break;
        }
        case 11: {
            // детерменант
            std::cout << matr_0.det() << endl;
            break;
        }
        case 12: {
            // ввод перегруженный
            cin >> matr_0;
            break;
        }
        case 13: {
            // вывод перегрузка
            std::cout << matr_0;
            break;
        }
        case 14: {
            // поэлементное сложение
            matrix matr_2;
            matr_2.input();
            matr_0 += matr_2;
            break;
        }
        case 15: {
            // поэлементраня разница
            matrix matr_2;
            matr_2.input();
            matr_0 -= matr_0;
            break;
        }
        default: {
            return 1;
        }
        }
    }
}