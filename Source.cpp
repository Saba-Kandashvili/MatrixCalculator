#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix2D
{
public:
	vector<vector<double>> Matrix;

	Matrix2D(int R, int C)
	{
		vector<vector<double>> matrix(R, vector <double> (C));
		Matrix = matrix;
	}

	void SetIJ( int _i, int _j, double num)
	{
		Matrix[_i][_j] = num;
	}

	void FillMatrix(double num)
	{
		for (size_t i = 0; i < Matrix.size(); i++)
		{
			for (size_t j = 0; j < Matrix[i].size(); j++)
			{
				Matrix[i][j] = num;
			}
		}
	}

	void PrintMatrixSize()
	{
		cout << "Matrix Size: (" << Matrix.size() << "x" << Matrix[0].size() << ")" << endl;
	}

	void PrintMatrix()
	{
		for (size_t i = 0; i < Matrix.size(); i++)
		{
			cout << "\xB3";

			for (size_t j = 0; j < Matrix[i].size(); j++)
			{
				if (j < Matrix[i].size() - 1)
				{
					cout << Matrix[i][j] << ";" << setw(3);
				}
				else
				{
					cout << Matrix[i][j];
				}
			}
			cout << "\xB3" << endl;
		}
	}

	int Size_M()
	{
		return Matrix.size();
	}
	int Size_N()
	{
		return Matrix[0].size();
	}
};

Matrix2D AddMatrix(Matrix2D*, int);
Matrix2D AddMatrix(Matrix2D*, Matrix2D*);
Matrix2D MultiplyMatrix(Matrix2D*, int);
Matrix2D MultiplyMatrix(Matrix2D*, Matrix2D*);
Matrix2D ElementaryMatrixI(int);
void ElementaryMatrixL(Matrix2D* matrix, int i, int j, double num);

int main()
{
	Matrix2D test(3, 3);
	test = ElementaryMatrixI(3);
	ElementaryMatrixL(&test, 3, 3, 2.5);
	test.PrintMatrixSize();
	test.PrintMatrix();

	return 0;
}

Matrix2D AddMatrix(Matrix2D* matrix, int additionNum)
{
	Matrix2D ans = *matrix;
	for (size_t i = 0; i < matrix->Matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix->Matrix[i].size(); j++)
		{
			ans.Matrix[i][j] += additionNum;
		}
	}
	return ans;
}

Matrix2D AddMatrix(Matrix2D* matrix1, Matrix2D* matrix2)
{
	if (matrix1->Size_M() == matrix2->Size_M() && matrix1->Size_N() == matrix2->Size_N())
	{
		Matrix2D ans(matrix1->Size_M(), matrix1->Size_N());
		for (size_t i = 0; i < matrix1->Matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix1->Matrix[i].size(); j++)
			{
				ans.Matrix[i][j] = matrix1->Matrix[i][j] + matrix2->Matrix[i][j];
			}
		}
		return ans;
	}
	else
	{
		Matrix2D Error(1, 1);
		Error.FillMatrix(0);
		return Error;
	}
}

Matrix2D MultiplyMatrix(Matrix2D* matrix, int multiplicationNum)
{
	Matrix2D ans = *matrix;
	for (size_t i = 0; i < matrix->Matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix->Matrix[i].size(); j++)
		{
			ans.Matrix[i][j] *= multiplicationNum;
		}
	}
	return ans;
}

Matrix2D MultiplyMatrix(Matrix2D* matrix1, Matrix2D* matrix2)
{
	if (matrix1->Size_M() == matrix2->Size_N())
	{
		Matrix2D ans(matrix1->Size_M(), matrix2->Size_N());
		ans.FillMatrix(0);
		
		for (size_t i = 0; i < matrix1->Size_M(); i++)
		{
			for (size_t j = 0; j < matrix2->Size_N(); j++)
			{
				for (size_t k = 0; k < matrix1->Size_N(); k++)
				{
					ans.Matrix[i][j] += matrix1->Matrix[i][k] * matrix2->Matrix[k][j];
				}
			}
		}
		return ans;
	}
	else
	{
		Matrix2D Error(1, 1);
		Error.FillMatrix(0);
		return Error;
	}
}

Matrix2D ElementaryMatrixI(int size)
{
	Matrix2D ans(size, size);
	for (size_t i = 0; i < size; i++)
	{
		ans.SetIJ(i, i, 1);
	}
	return ans;
}

void ElementaryMatrixL(Matrix2D* matrix, int i, int j, double num)
{
	matrix->Matrix[i - 1][j - 1] = num;
}
