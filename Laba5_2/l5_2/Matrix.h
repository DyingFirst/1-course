#pragma once
#include<iostream>
class Matrix
{
private:
	int size;
	int* elem;
	
public:
	Matrix();
	Matrix(const Matrix& matr);
	~Matrix();
	// дружественные перегрузки
	friend std::ostream& operator<<(std::ostream& cout, const Matrix& temp);
	friend std::istream& operator>>(std::istream& cin, Matrix& temp);
	// перегрузки ввода
	void input();
	void input(int n);
	// различные функции
	int get_elem(int i, int j) const;
	void print() const;
	int get_size() const;
	int trace() const;
	// определитель
	double det();
	int det(int* matr, int R);
	void getmatr(int* matr, int* p, int i, int j, int rows);
	// разные перегрузки
	void operator- (const Matrix& temp);
	void operator+= (const Matrix& temp);
	void operator+ (const Matrix& temp);
	void operator-= (const Matrix& temp);
	void operator*(int num);
	void operator- ();
	void operator* (const Matrix& temp);
};

