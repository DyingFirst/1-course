// определитель матрицы

#include <vector>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");

    vector<vector<int>> array;

    cout << "Введите количество строк матрицы: " << endl;
    int n = 0, m = 0;
    cin >> n;
    cout << "Введите количество столбцов матрицы: " << endl;
    cin >> m;
    if (n != m) {
        cout << "Определитель найти невозможно!" << endl;
        return 0;
    }
    vector<int> row;
    int x = 0;
    cout << "Заполните матрицу: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            row.push_back(x);
        }
        array.push_back(row);
        row.clear();
    }

    cout << "Введённая матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int koef = 0;
    for (int t = 0; t < n - 1; t++) {
        for (int i = t; i < n - 1; i++) {
            koef = array[i + 1][t] / array[t][t];
            for (int j = i + 1; j < n; j++) {
                for (int y = 0; y < m; y++) {
                    array[j][y] -= array[t][y] * koef;
                }
                break;
            }
        }
    }
    cout << "Преобразованная матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Определитель матрицы: " << endl;
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= array[i][i];
    }
    cout << result;
}