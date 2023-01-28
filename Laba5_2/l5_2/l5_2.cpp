#include "Matrix.h"
#include <iostream>

// Очистка экрана
void clear_screen() {
    std::cout << "\nСейчас будет очищен экран и выполнен переход в меню.\n";
    system("pause");
    system("cls");
}

// Меню.
int start_menu(Matrix& main_matrix, Matrix& auxiliary_matrix, int& temp, int& i, int& j) {
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    // реализация вывода меню и его функционирования
    while (true) {
        //Вывод на экран меню
        std::cout << "Меню." << std::endl;
        std::cout << "1. Ввод трехдиагональной матрицы." << std::endl;
        std::cout << "2. Ввод трехдиагональной матрицы с заданным размером." << std::endl;
        std::cout << "3. Печать трехдиагональной матрицы." << std::endl;
        std::cout << "4. Вывод определеного элемента трехдиагональной матрицы." << std::endl;
        std::cout << "5. Бинарный минус." << std::endl;
        std::cout << "6. Унарный минус." << std::endl;
        std::cout << "7. Сложение трехдиагональных матриц." << std::endl;
        std::cout << "8. Умножение трехдиагональной матрицы на число." << std::endl;
        std::cout << "9. След трехдиагональной матрицы." << std::endl;
        std::cout << "10. Умножение трехдиагональных матриц." << std::endl;
        std::cout << "11. Определитель трехдиалгональной матрицы." << std::endl;
        std::cout << "12. >> перегрузка ввод." << std::endl;
        std::cout << "13. << перегрузка вывод." << std::endl;
        std::cout << "14. += перегрузка поэлементное представление сложения трехдиагональной матрицы." << std::endl;
        std::cout << "15. -= перегрузка поэлементное представление вычитания трехдиагональной матрицы." << std::endl;
        std::cout << "16. Выход." << std::endl;
        std::cout << "\nВыберите номер задания >>> ";
        std::cin >> choice;
        std::cout << std::endl;
        //Проверка выбора от 1-4, где 1-3 задания, а 4 выход из тела основной функции
        switch (choice) {
        case 1:
        {
            main_matrix.input();
            break;
        }
        case 2:
        {
            std::cout << "Введите размер >>> ";
            std::cin >> temp;
            main_matrix.input(temp);
            break;
        }
        case 3:
        {
            main_matrix.print();
            break;
        }
        case 4:
        {
            std::cout << "Введите индексы i, j >>> ";
            std::cin >> i >> j;
            std::cout << main_matrix.get_elem(i, j);
            break;
        }
        case 5:
        {
            auxiliary_matrix.input();
            main_matrix - auxiliary_matrix;
            break;
        }
        case 6:
        {
            -main_matrix;
            break;
        }
        case 7:
        {
            auxiliary_matrix.input();
            main_matrix + auxiliary_matrix;
            break;
        }
        case 8:
        {

            std::cout << "Пожалуйста введите число >>> ";
            std::cin >> temp;
            main_matrix* temp;
            break;
        }
        case 9:
        {
            std::cout << main_matrix.trace() << std::endl;
            break;
        }
        case 10:
        {
            auxiliary_matrix.input();
            main_matrix* auxiliary_matrix;
            break;
        }
        case 11:
        {
            std::cout << main_matrix.det() << std::endl;
            break;
        }
        case 12:
        {/*
            int n;
            std::cout << "Please, enter a size: ";
            std::cin >> n;*/

            std::cin >> main_matrix;
            break;
        }
        case 13:
        {
            std::cout << main_matrix;
            break;
        }
        case 14:
        {
            auxiliary_matrix.input();
            main_matrix += auxiliary_matrix;
            break;
        }
        case 15:
        {
            auxiliary_matrix.input();
            main_matrix -= auxiliary_matrix;
            break;
        }
        case 16: {
            return 0;
        }
        default: {
            std::cout << "\nВведено неверное значение. Допустимый диапазон 1-16\n";
        }
        }
        clear_screen();
    }
}

// Тело основной функции
int main()
{
    // Контроль закрытия меню.
    int result_start_menu;

    Matrix main_matrix;  // главная матрица
    Matrix auxiliary_matrix;  // вспомогательная матрица
    int temp = 0;  // используется для хранения временных значений (например для хранения размера матрицы при ее вводе)
    // создание переменных для хранения индексов массива
    int i = 0;
    int j = 0; 

    result_start_menu = start_menu(main_matrix, auxiliary_matrix, temp, i, j);
    if (result_start_menu == 0) { return 0; }
}