#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	this->size = 0;
	this->elem = nullptr;
}

Matrix::Matrix(const Matrix& temp)
{
	this->size = temp.size;
	this->elem = new int[3 * this->size];
	for (int i = 0; i < 3 * this->size; i++) {
		this->elem[i] = temp.elem[i];
	}
}

Matrix::~Matrix()
{
	if (this->elem != nullptr) {
		delete[] this->elem;
	}
}

void Matrix::input() {
	if (this->elem != nullptr) {
		delete[] this->elem;
	}
	int n;
	std::cout << "Пожалуйста введите размер >>> ";
	std::cin >> n;
	this->elem = new int[3 * n];
	this->size = n;
	for (int i = 0; i < 3 * n; i++) {
		std::cin >> this->elem[i];
	}
	this->elem[n - 1] = 0;
	this->elem[2 * n] = 0;
}

void Matrix::input(int n) {
	if (this->elem != nullptr) {
		delete[] this->elem;
	}
	this->elem = new int[3 * n];
	this->size = n;
	for (int i = 0; i < 3 * n; i++) {
		this->elem[i] = i;
	}
	this->elem[n - 1] = 0;
	this->elem[2 * n] = 0;
}

int Matrix::get_elem(int i, int j) const {
	if (i == j) {
		return this->elem[this->size + i];
	}
	else if (i == j - 1) {
		return this->elem[i];
	}
	else if (i == j + 1) {
		return this->elem[2 * this->size + i];
	}
	else {
		return 0;
	}
}

void Matrix::print() const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

int Matrix::trace() const {
	int trace = 0;
	for (int i = 0; i < this->size; ++i) {
		trace += elem[i * this->size + i];
	}
	return trace;
}

int Matrix::det(int* matr, int R) {
	int* p;
	p = new int[R];
	int k = 1;
	int d = 0;
	int n = R - 1;
	switch (R) {
	case 1: {
		return matr[0 * this->size + 0];
	}
	case 2: {
		return matr[0 * this->size + 0] * matr[1 * this->size + 1] - matr[0 * this->size + 1] * matr[1 * this->size + 0];
	}
	default: {
		for (int i = 0; i < R; ++i) {
			getmatr(matr, p, i, 0, R);
			d = d + k * matr[i * this->size + 0] * det(p, n);
			k = -k;
		}
		return d;

	}

	}
}

double Matrix::det() {
	double d = det(this->elem, this->size);
	return d;
}

void Matrix::getmatr(int* matr, int* p, int i, int j, int rows) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < rows - 1; ki++) {
		if (ki == i) {
			di = 1;
		}
		dj = 0;
		for (kj = 0; kj < rows - 1; kj++) {
			if (kj == j) {
				dj = 1;
			}
			int y = ki + di;
			int q = kj + dj;
			p[ki * this->size + kj] = matr[y * this->size + q];
		}
	}

}

int Matrix::get_size() const {
	return this->size;
}

void Matrix::operator- (const Matrix& temp) {
	if (this->size == temp.size) {
		for (int i = 0; i < 3 * this->size; i++) {
			this->elem[i] -= temp.elem[i];
		}
	}
	else {
		std::cout << "\nError... Размер не совпадает. Операция недоступна :( \n";
	}
}

void Matrix::operator+(const Matrix& temp)
{
	if (this->size == temp.size) {
		for (int i = 0; i < 3 * this->size; i++) {
			this->elem[i] += temp.elem[i];
		}
		std::cout << std::endl;
	}
}

void Matrix::operator- () {
	for (int i = 0; i < 3 * this->size; i++) {
		if (this->elem[i] < 0 || this->elem[i] > 0) this->elem[i] = 0 - this->elem[i];
		else if (this->elem[i] == 0) this->elem[i] = -this->elem[i];
		 
	}
}

void Matrix::operator+=(const Matrix& temp) {
	if (this->size == temp.size) {
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if ((this->get_elem(i, j) == 0) || (temp.get_elem(i, j) == 0)) { 
					std::cout << "0   ";
				}
				else {
					std::cout << this->get_elem(i, j) << "+" << temp.get_elem(i, j) << " ";
				}
			}
			std::cout << std::endl;
		}

	}
}

void Matrix::operator-= (const Matrix& temp) {
	if (this->size == temp.size) {
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if ((this->get_elem(i, j) == 0) || (temp.get_elem(i, j) == 0)) {
					std::cout << "0   ";
				}
				else {
					std::cout << this->get_elem(i, j) << "-" << temp.get_elem(i, j) << " ";
				}
			}
			std::cout << std::endl;
		}

	}
}

void Matrix::operator*(const Matrix& temp) {
	double* c;
	c = new double[this->size * 3];
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < temp.size; j++)
		{
			c[i * temp.size + j] = 0;
			for (int k = 0; k < this->size; k++) {
				int k1 = k;
				if (k == this->size) k1++;
				c[i * temp.size + j] += this->get_elem(i, k) * temp.get_elem(k, j);
			}
		}
	}
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (this->get_elem(i, j)) {
				this->elem[i * this->size + j] = c[i * this->size + j];
			}
		}
	}
}


void Matrix::operator*(int num) {
	int res;
	for (int i = 0; i < this->get_size(); i++) {
		for (int j = 0; j < this->get_size(); j++) {
			res = this->elem[i * this->get_size() + j] * num;
			std::cout << res << " ";
		}
		std::cout << std::endl;
	}
}

std::ostream& operator<<(std::ostream& cout, const Matrix& temp) {
	std::cout << "\nТрехдиагональная матрица\n";
	int n = temp.get_size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp.get_elem(i, j) << " ";
		}
		cout << std::endl;
	}
	return cout;
}

std::istream& operator>>(std::istream& cin, Matrix& temp) {
	std::cout << "\nВведите размер трехдиагональной матрицы >>> ";
	cin >> temp.size;
	if (temp.elem != nullptr)
		delete[] temp.elem;
	temp.elem = new int[temp.size * 3];
	for (int i = 0; i < temp.size * 3; i++)
		std::cin >> temp.elem[i];
	return std::cin;
}