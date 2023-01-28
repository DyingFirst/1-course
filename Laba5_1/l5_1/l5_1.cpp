// lab 5.1
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Matrix {

public:
	int Row; // строки
	int Column; // столбцы
	double* Array; // динамический массив

public:
	void sum(const Matrix mat2);
	void mult(const Matrix mat2);
	double trace();
	double det();
	void mult_by_num(double num);
	void input();
	void print();
	int get_columns();
	int get_rows();
	double get_elem(int i, int j);
	Matrix();
	Matrix(int i, int j);
};

void Matrix::input() {
	cout << "Введите кол - во строк : ";
	cin >> Row;
	cout << "Введите кол - во столбцов : ";
	cin >> Column;
	cout << "Заполните массив : \n";
	this->Array = new double[Row * Column];
	for (int i = 0; i < Row * Column; i++) {
		cin >> Array[i];
	}
}

void Matrix::print() {
	cout << "Матрица равна :" << endl;
	for (int i = 0; i < Row * Column; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

double Matrix::trace() {
	double sum = 0;
	if (Row == Column) {
		int counter = 0;
		for (int i = 0; i < Row * Column; i++) {
			if (i == counter) {
				sum += Array[i];
				counter += Column + 1;
			}
		}
		return sum;
	}
	else {
		cout << "Матрица не является квадратной ! \n";
		return sum;
	}
}

int Matrix::get_rows() {
	return Row;
}
int Matrix::get_columns() {
	return Column;
}
double Matrix::get_elem(int i, int j) {
	i--;
	j--;
	int tmp = (i * Column) + j;
	return Array[tmp];
}

void Matrix::mult_by_num(double umn) {
	for (int i = 0; i < Row * Column; i++) {
		cout << Array[i] * umn << " ";
	}
	cout << endl;
}

void Matrix::sum(const Matrix mat2) {
	if (Row == mat2.Row && Column == mat2.Column) {
		cout << "Сложение двух матриц = ";
		for (int i = 0; i < Row * Column; i++) {
			cout << Array[i] + mat2.Array[i] << " ";
		}
	}
	else {
		cout << "Размер матриц не совпадает((( ";
	}
}

Matrix::Matrix() {
	this->Row = this->Column = 0;
	this->Array = NULL;
}

Matrix::Matrix(int i, int j) {
	Row = i;
	Column = j;
	this->Array = new double[Row * Column];
	for (int i = 0; i < Row * Column; i++) {
		this->Array[i] = 1;
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	Matrix test;
	int n = 0;
	bool flag = true;
	double tri;
	int schet;
	int pyat;
	double umn;
	double result = 0;
	const Matrix mat2(3, 3);
	while (flag) {
		cout << "Введите 0 для выхода* \n";
		cout << "Введите номер задания : ";
		cin >> n;
		switch (n) {
		case 1: test.input();
			break;
		case 2: test.print();
			break;
		case 3:
			tri = test.trace();
			cout << tri << endl;
			break;
		case 4:
			schet = test.get_rows();
			cout << schet << endl;
			break;
		case 5:
			pyat = test.get_columns();
			cout << pyat << endl;
			break;
		case 6:
			cout << "Введите номер строки и номер столбца :" << endl;
			int i, j;
			cin >> i >> j;
			result = test.get_elem(i, j);
			cout << "Выбранный вами элемент - " << result << endl;
			break;
		case 7:
			cout << "Введите число на которое будет умножаться матрица : \n";
			cin >> umn;
			test.mult_by_num(umn);
			break;
		case 8:
			cout << "Заполните новую матрицу : \n";
			test.sum(mat2);
			break;
		case 0:
			flag = false;
			break;
		}
	}
}