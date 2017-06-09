#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;
class Matrix
{
private:
	int col;
	int row;
	vector< vector<double> > data;
public:
	int getCol() const;
	int getRow() const;
	vector< vector<double> > getData() const;
	Matrix(int row, int col, double data);
	Matrix(vector< vector <double> >& vec);
	Matrix(const Matrix& rhs);
	friend ostream& operator<<(ostream& os, Matrix const& m);
	double& operator()(int row, int col);
	const double& operator()(int row, int col) const;
	Matrix& operator=(const Matrix& rhs);
	Matrix operator+(const Matrix& rhs);
	Matrix operator-(const Matrix& rhs);
	Matrix operator+=(const Matrix& rhs);
	Matrix operator-=(const Matrix& rhs);
	Matrix operator*(const Matrix& rhs);
	Matrix operator*=(const Matrix& rhs);
	Matrix operator+(double rhs);
	Matrix operator-(double rhs);
	Matrix operator*(double rhs);
	Matrix operator/(double rhs);
	vector<double> diagVec();

};

#endif
