#include <iostream> 
using namespace std; 
#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public: 
	Matrix(); 
	Matrix(int rowtemp, int coltemp); 
	Matrix(const Matrix& m); 
	~Matrix();

	Matrix operator = (const Matrix& rhs);

	void create(int rowTemp, int colTemp); 
	void fillArray();
	void printArray() const; 
	void addition(const Matrix& rhs); 
	void substraction(const Matrix& rhs); 
	Matrix multiplication(const Matrix& rhs);
	void transpose() const;
	void trace() const; 
	int determinant() const; 
	void inverse() const; 
 
private: 
	int row; 
	int col; 
	int** value;
};



#endif MATRIX_H