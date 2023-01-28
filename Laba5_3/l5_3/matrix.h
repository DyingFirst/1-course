#pragma once
#include<iostream>
using namespace std;
class matrix
{
private:
	int size;
	int* elem;
	int det(int* matr, int R);
	void getmatr(int* matr, int* p, int i, int j, int rows);

public:
	matrix();
	matrix(const matrix& matr);
	~matrix();

	friend ostream& operator<<(ostream& out, const matrix& temp);
	friend istream& operator>>(istream& in, matrix& temp);
	int get_size();
	void input();
	void input(int n);

	int get_elem(int i, int j) const;
	void print() const;
	int get_size() const;
	int trace() const;

	double det();

	void operator- ();
	void operator- (const matrix& temp);
	void operator-= (const matrix& temp);
	void operator+ (const matrix& temp);
	void operator+= (const matrix& temp);
	void operator* (int num);
	void operator* (const matrix& temp);
};

class matrix
{
};
