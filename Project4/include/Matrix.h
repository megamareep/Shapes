#ifndef MATRIX_H
#define MATRIX_H

#include <vector>


using namespace std;

class Matrix
{
private:
	unsigned int height;
	unsigned int width;
	vector<std::vector<double>> data;
public:
	Matrix();
	Matrix(int column,int row);
	void resizeTable();
	void createTable(); //!< sets the parameters of the table.
	unsigned int getWidth();
	unsigned int getHeight();
	void setHeight(unsigned int h);
	void setWidth(unsigned int w);
	void setElement(double newElement, int colunmN, int rowN);//!< Sets a number in the table
	double getElement(int columnN, int rowN)const;//!< finds the number in the table.
	Matrix add(Matrix& other);//!< Adds another matrix to this matrix
	Matrix subtract(Matrix& other) ;//!< Subtracts another matrix to this matrix
	Matrix matrixMultiplication(Matrix& other);//!< Multiplies another matrix to this matrix
	Matrix scalarMultiplication(double scalar);//!< Multiplies the matrix by a scalar.
};
#endif

