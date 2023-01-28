#include "Matrix_reload.h"
Matrix::Matrix() {
	this->size_row = 0;
	this->size_col = 0;
	this->elem = nullptr;
};
Matrix::Matrix(int i, int j) {
	this->size_row = i;
	this->size_col = j;
	this->elem = new double[this->size_row * this->size_col];
	for (int i = 0; i < this->size_col * this->size_row; i++) {
		elem[i] = 0;
	}
}
Matrix::Matrix(int i, int j, const double* arr) {
	this->size_row = i;
	this->size_col = j;
	this->elem = new double[this->size_row * this->size_col];
	for (int i = 0; i < this->size_row * this->size_col; i++) {
		elem[i] = *&arr[i];
	}
}

Matrix::Matrix(const Matrix& temp)
{
	this->size_col = temp.size_col;
	this->size_row = temp.size_row;
	this->elem = new double[temp.size_col * temp.size_row];
	this->elem = temp.elem;
}

Matrix::~Matrix() {
	if (this->elem != nullptr)
	{
		delete[] this->elem;
	}
}

void Matrix::input() {
	std::cout << "¬ведите количество строк матрицы: ";
	std::cin >> this->size_row;
	std::cout << "¬ведите количество столбцов матрицы: ";
	std::cin >> this->size_col;
	if (this->elem != nullptr)
	{
		delete[] this->elem;
	}
	this->elem = new double[this->size_row * this->size_col];
	for (int i = 0; i < this->size_row * this->size_col; i++) {
		std::cin >> *&this->elem[i];
	}
}
void Matrix::input(int i, int j) {
	std::cout << "¬водите элементы матрицы последовательно: \n";
	this->size_row = i;
	this->size_col = j;
	if (this->elem != nullptr)
	{
		delete[] this->elem;
	}
	this->elem = new double[this->size_row * this->size_col];
	for (int i = 0; i < this->size_row * this->size_col; i++) {
		std::cin >> *&this->elem[i];
	}
}
void Matrix::input(int i, int j, double* arr) {
	this->size_row = i;
	this->size_col = j;
	if (this->elem != nullptr)
	{
		delete[] this->elem;
	}
	this->elem = new double[this->size_row * this->size_col];
	for (int i = 0; i < this->size_row * this->size_col; i++) {
		this->elem[i] = arr[i];
	}
}

void Matrix::print() {
	std::cout << "¬аша матрица: \n";
	for (int i = 0; i < this->size_row; i++) {
		for (int j = 0; j < this->size_col; j++) {
			std::cout << this->elem[i * this->size_col + j] << " ";
		}
		std::cout << '\n';
	}
}
int Matrix::get_columns() {
	return this->size_col;
}
int Matrix::get_rows() {
	return this->size_row;
}
double Matrix::get_elem(int i, int j) {
	return this->elem[i * this->size_col + j];
}
void Matrix::mult_by_num(double num) {
	for (int i = 0; i < this->size_row; i++) {
		for (int j = 0; j < this->size_col; j++) {
			this->elem[i * this->size_col + j] = this->elem[i * this->size_col + j] * num;
		}
	}
}
bool Matrix::sum(const Matrix* mat2) {
	if ((this->size_col == mat2->size_col) and (this->size_row == mat2->size_row)) {
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < this->size_col; j++) {
				this->elem[i * this->size_col + j] = this->elem[i * this->size_col + j] + mat2->elem[i * mat2->size_col + j];
			}
		}
		return 0;
	}
	else {
		return 1;
	}
}
bool Matrix::sum(const double* arr, int row, int col) {
	if ((this->size_col == col) && (this->size_row == row)) {
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < this->size_col; j++) {
				elem[i * this->size_col + j] += arr[i * this->size_col + j];
			}
		}
		return 0;
	}
	else {
		return 1;
	}
}
double Matrix::trace() {
	if (this->size_col == this->size_row) {
		double summ = 0;
		for (int i = 0; i < this->size_col; i++) {
			summ += this->elem[i * this->size_col + i];
		}
		return summ;
	}
	return 100000;
}
bool Matrix::mult(const Matrix* mat2) {
	if (this->size_row == mat2->size_col) {
		double* res = new double[this->size_row * mat2->size_col];
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < mat2->size_col; j++) {
				double summ = 0;
				for (int q = 0; q < this->size_col; q++) {
					summ += this->elem[i * this->size_col + q] * mat2->elem[q * mat2->size_col + j];
				}
				res[i * mat2->size_col + j] = summ;
			}
		}
		delete[] this->elem;
		this->elem = res;
		this->size_col = mat2->size_col;
		return 1;
	}
	else {
		return 0;
	}
}
bool Matrix::mult(const double* arr, int col, int row) {
	if (this->size_row == col) {
		double* res = new double[this->size_row * col];
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < col; j++) {
				double summ = 0;
				for (int q = 0; q < this->size_col; q++) {
					summ += this->elem[i * this->size_col + q] * arr[q * col + j];
				}
				res[i * col + j] = summ;
			}
		}
		delete[] this->elem;
		this->elem = res;
		this->size_col = col;
		return 1;
	}
	else {
		return 0;
	}
}