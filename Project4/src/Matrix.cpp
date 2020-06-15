#include "Matrix.h"



Matrix::Matrix()
{
	height = 0;
	width = 0;
}

Matrix::Matrix (int column,int row)
{
	width =  column;
	height = row;
	createTable();
}
//!Creates a new Table of the Matrix when this is called.

//!Fills the table with 0's
void Matrix::resizeTable()
{
	data.resize(0);
}
void Matrix::createTable() 
{

	data.resize(width);
		for (int row = 0 ; row < width ; row++ )
		{
			data[row].resize(height);
		}
		
	//}
}

//!Adds together the matricies
Matrix Matrix::add(Matrix& other)
{
	Matrix result(width,height);
	
	//!Increases row.
	for ( int row = 0 ; row < height; row++ )
	{
		//!Increases the column size
		for ( int col = 0 ; col < width ; col++ )
		{
			result.setElement(data[col][row] += other.data[col][row],col,row);
		}
	}

	//!Returns the current matrix.
	return result;
}

Matrix Matrix::subtract(Matrix& other)
{
	Matrix result(width,height);
	
	
	for ( int row = 0 ; row < height ; row++ )
	{
		//!Increases the column size
		for ( int col = 0 ; col < width ; col++ ) 
		{
			result.setElement(data[col][row] -= other.data[col][row],col,row);

		}
	}
	//!Returns the current matrix back.
	return result;
}

Matrix Matrix::scalarMultiplication(double scalar)
{
	Matrix result(width,height);
	
	for (unsigned int row = 0 ; row < height ; row++ )
	{
		//!Increases the column size
		for (unsigned int col = 0 ; col < width ; col++ ) 
		{
			result.setElement(data[col][row] *= scalar, col,row);

		}
	}
	return result;
}


//I cant get this to work.
Matrix Matrix::matrixMultiplication(Matrix& other)
{	
	vector<std::vector<double>> result1;
	Matrix result(width,height);
	
	//Creates the size of the new vector
		result1.resize(width);
		for (int row = 0 ; row < width ; row++ )
		{
			result1[row].resize(height);
		}

	
	/*! 3 For loops to correctly work through the table. The first number will be element in data at 0,0 multiplied by 
	the element in other.data at 0,0. Next inner will count up so it will be element in data 1,0 multiplied by 
	the element in other.data 0,1. !*/
	for ( int row = 0 ; row < height ; row++ )
		{
			for ( int col = 0 ; col < width ; col++ )
				{
					
					for ( int inner =0; inner < height; inner++)
						{
							//!Row of data times the column of other. Then added to get the result.
							result1[col][row] += other.data[inner][row] * data[col][inner];
						}
				}
			
		}
	/*! This sets data back to the answers that are stored in results. Then returns back to the
	current matrix!*/
	for ( int row = 0 ; row < height ; row++ )
	{
			
			for ( int col = 0 ; col < width ; col++ )
			{
					
				result.setElement(data[col][row]= result1[col][row],col,row) ;
					
			}
			
	}

	return result;
	
}

// Sets the element inside the table at row.. and column...
void Matrix::setElement(double newElement, int columnN, int rowN)
{
	data[columnN][rowN] = newElement ;
}

double Matrix::getElement(int columnN, int rowN)const
{
	return data[columnN][rowN];
}

unsigned int Matrix::getHeight()
{
	return height;

}
unsigned int Matrix::getWidth()
{
	return width;
}

void Matrix::setHeight(unsigned int h)
{
	height = h;
}

void Matrix::setWidth(unsigned int w)
{
	width = w;
}




