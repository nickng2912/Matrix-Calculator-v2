#include <iostream> 
#include <stdio.h>
using namespace std; 
#include "matrix.h"

Matrix::Matrix()
	:row(0), col(0)
{
	cout << "DEFAULT CONSTRUCTOR INVOKED" << endl; 
}

Matrix::Matrix(int rowtemp, int coltemp)
	: row(rowtemp), col(coltemp)
{
	value = new int* [row];
	for (int i = 0; i < row; i++)
		value[i] = new int[col];

	cout << "CONSTRUCTOR INVOKED" << endl; 
}

Matrix::Matrix(const Matrix& m)
{
	this->row = m.row;
	this->col = m.col;
	this->value = m.value;
	cout << "COPY CONSTRUCTOR INVOKED" << endl; 
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; i++)
		delete value[i];
	delete value; 

	cout << "DESTRUCTOR INVOKED " << endl;
}

Matrix Matrix::operator=(const Matrix& rhs)
{
	this->row = rhs.row; 
	this->col = rhs.col;
	this->value = rhs.value;

	cout << "OPERATOR = INVOKED" << endl; 
	return *this; 
}

void Matrix::create(int rowTemp, int colTemp)
{
	row = rowTemp; 
	col = colTemp; 
	value = new int* [row];
	for (int i = 0; i < row; i++)
		value[i] = new int[col];

	cout << "Matrix sucessfully created with " << row << " rows and "
		<< col << " columns!" << endl; 
}

void Matrix::fillArray()
{
	cout << "Now fill out the Matrix with " << row*col <<" integers: ";
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			cin >> value[i][j];

}

void Matrix::printArray() const
{
	if (row == 0 && col == 0)
	{
		cout << "FAIL TO PRINT YOUR MATRIX!";
		exit(1);
	}
	cout << "Here is your Matrix: " << endl;
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			cout << this->value[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::addition(const Matrix& rhs)
{
	if (this->row != rhs.row || this->col != rhs.col)
	{
		cout << "ERROR, CANT BE ADDED!"; 
		exit(1);
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				this->value[i][j] = this->value[i][j] + rhs.value[i][j];
		}
	}
	cout << "ADDITION SUCESSFULLY!" << endl; 
}

void Matrix::substraction(const Matrix& rhs)
{
	if (this->row != rhs.row || this->col != rhs.col)
	{
		cout << "ERROR, CANT BE SUBSTRACT!";
		exit(1);
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				this->value[i][j] = this->value[i][j] - rhs.value[i][j];
		}
	}
	cout << "SUBSTRACTION SUCESSFULLY!" << endl;
}

 Matrix Matrix::multiplication(const Matrix& rhs)
{
	 if (this->col != rhs.row)
	 {
		cout << "ERROR, CANT BE MULTIPLY!";
		exit(1);
	 }


	Matrix temp(this->row, rhs.col);

	if (this->col == rhs.row)
	{
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < rhs.col; j++)
			{
				temp.value[i][j] = 0; 
				for (int k = 0; k < this->col; k++)
					temp.value[i][j] = temp.value[i][j] + (this->value[i][k] * rhs.value[k][j]);
			}
		}
	}

	return temp; 

	cout << "MULTIPLICATION SUCESSFULLY!" << endl; 
}

