#pragma once
#include <iostream>
class Matrix {
public:
	int size_col, size_row;
	double* elem;

	Matrix();// конструктор
	Matrix(int i, int j);// конструктор
	Matrix(int i, int j, const double* arr);// конструктор
	Matrix(const Matrix& temp); // копирующий консткрутор
	~Matrix();// деконструктор
	bool sum(const Matrix* mat2); //
	bool sum(const double* arr, int row, int col);
	bool mult(const Matrix* mat2);//
	bool mult(const double* arr, int col, int row);
	double trace(); //
	double det();
	void mult_by_num(double num); //
	void input(); //
	void input(int i, int j);
	void input(int i, int j, double* arr);
	void print(); //
	int get_columns(); //
	int get_rows(); //
	double get_elem(int i, int j); //
};