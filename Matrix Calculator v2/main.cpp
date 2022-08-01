#include <iostream> 
#include "matrix.h"
using namespace std; 

int main()
{
	Matrix m1;
	m1.create(3, 3);
	Matrix m3 = m1; 

	m1.fillArray();
	m1.printArray();

	m3.printArray();
	Matrix m2(3, 1);
	m2.fillArray(); 
	m2.printArray(); 

	Matrix m4;
	m4 = m3.multiplication(m2);
	m4.printArray(); 

	//m1.multiplication(m2);
	//m1.printArray(); 

	system("pause");
	return 0; 
}