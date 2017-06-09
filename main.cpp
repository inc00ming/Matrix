#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix m(2, 2, 2);
	Matrix m1(2, 2, 3);
	cout << m << "############" << endl << m1;
	cout << m * m1 << endl;
	return 0;
}
