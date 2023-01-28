#include "matrix.h"
#include <iostream>

matrix::matrix()
{
	this->size = 0;
	this->elem = nullptr;
}
matrix::matrix(const matrix& temp)
{
	this->size = temp.size;
	this->elem = new int[3 * this->size];
	for (int i = 0; i < 3 * this->size; i++) {
		this->elem[i] = temp.elem[i];
	}
}
matrix::~matrix()
{
	if (this->elem != nullptr) {
		delete[] this->elem;
	}
}

void matrix::input() {
	if (this->elem != nullptr) {
		delete[] this->elem;
	}
	int n;
	std::cout << "Enter size: ";
	std::cin >> n;
	this->elem = new int[3 * n];
	this->size = n;
	for (int i = 0; i < 3 * n; i++) {
		std::cin >> this->elem[i];
	}
	this->elem[n - 1] = 0;
	this->elem[2 * n] = 0;
}

void matrix::input(int n) {
	if (this->elem != nullptr) {
		delete[] this->elem;
	}
	this->elem = new int[3 * n];
	this->size = n;

	for (int i = 0; i < 3 * n; i++) {
		this->elem[i] = rand() % 9 + 1;
	}

	this->elem[n - 1] = 0;
	this->elem[2 * n] = 0;
}


int matrix::get_elem(int i, int j) const {
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

int matrix::get_size() {
	return this->size;
}

void matrix::print() const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

int matrix::trace() const {
	int trace = 0;
	for (int i = 0; i < this->size; ++i) {
		trace += elem[i * this->size + i];
	}
	return trace;
}

int matrix::det(int* matr, int R) {
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

double matrix::det() {
	double d = det(this->elem, this->size);
	return d;
}

void matrix::getmatr(int* matr, int* p, int i, int j, int rows) {
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


void matrix::operator- (const matrix& temp) {
	if (this->size == temp.size) {
		for (int i = 0; i < 3 * this->size; i++) {
			this->elem[i] -= temp.elem[i];
		}
	}
}

void matrix::operator+(const matrix& temp)
{
	if (this->size == temp.size) {
		for (int i = 0; i < 3 * this->size; i++) {
			this->elem[i] += temp.elem[i];
		}
		std::cout << endl;
	}
}

void matrix::operator- () {
	for (int i = 0; i < 3 * this->size; i++) {
		if (this->elem[i] < 0 || this->elem[i] > 0) this->elem[i] = 0 - this->elem[i];
		else if (this->elem[i] == 0) this->elem[i] = -this->elem[i];

	}
}

void matrix::operator+=(const matrix& temp) {
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
			std::cout << endl;
		}

	}
}

void matrix::operator-= (const matrix& temp) {
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
			std::cout << endl;
		}

	}
}

void matrix::operator*(const matrix& temp) {
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

int matrix::get_size() const {
	return this->size;
}

void matrix::operator*(int num) {
	int res;
	for (int i = 0; i < this->get_size(); i++) {
		for (int j = 0; j < this->get_size(); j++) {
			res = this->elem[i * this->get_size() + j] * num;
			std::cout << res << " ";
		}
		std::cout << endl;
	}
}

ostream& operator<<(ostream& out, const matrix& temp) {
	int n = temp.get_size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << temp.get_elem(i, j) << " ";
		}
		out << endl;
	}
	return out;
}


istream& operator>>(istream& in, matrix& temp) {
	in >> temp.size;
	if (temp.elem != nullptr)
		delete[] temp.elem;

	temp.elem = new int[temp.size * 3];
	for (int i = 0; i < temp.size * 3; i++)
		cin >> temp.elem[i];
	return cin;
}