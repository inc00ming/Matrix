#include "Matrix.h"
#include <iostream>
using namespace std;

int Matrix::getCol() const
{
	return col;
}

int Matrix::getRow() const
{
	return row;
}

vector< vector<double> > Matrix::getData() const
{
	return data;
}
Matrix::Matrix(int row, int col, double data): col(col), row(row)
{
	vector< vector<double> > res;

	for(int i = 0; i < row; i++)
	{
		vector<double> acol;

		for(int j = 0; j < col; j++)
			acol.push_back(data);

		res.push_back(acol);
	}

	(*this).data = res;
}

Matrix::Matrix(vector< vector <double> >& vec)
{
	row = vec.size();
	col = vec[0].size();
	data = vec;
}

Matrix::Matrix(const Matrix& rhs)
{
	col = rhs.getCol();
	row = rhs.getRow();
	data = rhs.getData();
}

double& Matrix::operator()(int row, int col)
{
	return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
        return data[row][col];
}


ostream& operator<<(ostream& os, Matrix const& m)
{
	int row, col;
	row = m.getRow();
	col = m.getCol();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			os << m(i,j) << " ";
		os << endl;
	}
	return os;
}
Matrix& Matrix::operator=(const Matrix& rhs)
{
	col = rhs.getCol();
	row = rhs.getRow();
	vector< vector<double> > res;
	/*for(int i = 0; i < row; i++)
	{
		vector<double> acol;
		for(int j = 0; j < col; j++)
			acol.push_back(rhs(i,j));
		res.push_back(acol);
	}*/
	data = rhs.getData();
	return (*this);
}

Matrix Matrix::operator+(const Matrix& rhs)
{
	Matrix result(row, col, 0.0);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			result(i,j) = (*this)(i,j) + rhs(i,j);
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& rhs)
{
        Matrix result(row, col, 0.0);
        for(int i = 0; i < row; i++)
        { 
                for(int j = 0; j < col; j++)
                        result(i,j) = (*this)(i,j) - rhs(i,j);
        }
        return result;
}

Matrix Matrix::operator+=(const Matrix& rhs)
{
        for(int i = 0; i < row; i++)
        { 
                for(int j = 0; j < col; j++)
                        (*this)(i,j) += rhs(i,j);
        }
        return (*this);
}

Matrix Matrix::operator-=(const Matrix& rhs)
{
        for(int i = 0; i < row; i++)
        { 
                for(int j = 0; j < col; j++)
                        (*this)(i,j) -= rhs(i,j);
        }
        return (*this);
}

Matrix Matrix::operator+(double rhs)
{
	Matrix result(row, col, 0.0);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			result(i,j) = (*this)(i, j) + rhs;
	}

	return result;
}

Matrix Matrix::operator-(double rhs)
{
        Matrix result(row, col, 0.0);
        for(int i = 0; i < row; i++)
        {
                for(int j = 0; j < col; j++)
                        result(i,j) = (*this)(i, j) - rhs;
        }

        return result;
}

Matrix Matrix::operator*(double rhs)
{
        Matrix result(row, col, 0.0);
        for(int i = 0; i < row; i++)
        {
                for(int j = 0; j < col; j++)
                        result(i,j) = (*this)(i, j) * rhs;
        }

        return result;
}

Matrix Matrix::operator/(double rhs)
{
        Matrix result(row, col, 0.0);
        for(int i = 0; i < row; i++)
        {
                for(int j = 0; j < col; j++)
                        result(i,j) = (*this)(i, j) / rhs;
        }

        return result;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
	Matrix result(row, rhs.getCol(), 0.0);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < rhs.getCol(); j++)
		{
			for(int k = 0; k < col; k++)
				result(i, j) += (*this)(i,k) * rhs(k,j);
		}
	}
	return result;
}

Matrix Matrix::operator*=(const Matrix& rhs)
{
	Matrix result(row, rhs.getCol(), 0.0);
	result = (*this) * rhs;
	(*this) = result;
	return (*this);
}

