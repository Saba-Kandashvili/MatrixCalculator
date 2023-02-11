#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix2D
{
public:
	vector<vector<int>> Matrix;

	Matrix2D(int m, int n)
	{
		vector<vector<int>> matrix(m, vector<int>(n));
		Matrix = matrix;
	}

	void SetIJ( int _i, int _j, int num)
	{
		Matrix[_i - 1][_j - 1] = num;
	}

	void FillMatrix(int num)
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
			for (size_t j = 0; j < Matrix[i].size(); j++)
			{
				cout << setw(4) << Matrix[i][j];
			}
			cout << endl;
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
int CoshBenFormulla(Matrix2D *, Matrix2D *);

int main()
{
	Matrix2D A(3, 1);
	A.FillMatrix(2);

	A.PrintMatrixSize();
	A.PrintMatrix();
	cout << endl << endl << endl << endl;

	Matrix2D B(1, 3);
	B.FillMatrix(9);
	B.PrintMatrixSize();
	B.PrintMatrix();
	cout << endl << endl << endl << endl;
	Matrix2D AB = MultiplyMatrix(&A, &B);
	AB.PrintMatrixSize();
	AB.PrintMatrix();


	// Possiblity of i-j mixup ;( NEED to use C (collum) R (row) instead of mxn bs
	

	return 0;
}

Matrix2D AddMatrix(Matrix2D* matrix, int additionNum)
{
	Matrix2D temp = *matrix;
	for (size_t i = 0; i < matrix->Matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix->Matrix[i].size(); j++)
		{
			temp.Matrix[i][j] += additionNum;
		}
	}
	return temp;
}

Matrix2D AddMatrix(Matrix2D* matrix1, Matrix2D* matrix2)
{
	if (matrix1->Size_M() == matrix2->Size_M() && matrix1->Size_N() == matrix2->Size_N())
	{
		Matrix2D temp(matrix1->Size_M(), matrix1->Size_N());
		for (size_t i = 0; i < matrix1->Matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix1->Matrix[i].size(); j++)
			{
				temp.Matrix[i][j] = matrix1->Matrix[i][j] + matrix2->Matrix[i][j];
			}
		}
		return temp;
	}
	else
	{
		//critical situition. NEEDS AVOIDING
	}
}

Matrix2D MultiplyMatrix(Matrix2D* matrix, int multiplicationNum)
{
	Matrix2D temp = *matrix;
	for (size_t i = 0; i < matrix->Matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix->Matrix[i].size(); j++)
		{
			temp.Matrix[i][j] *= multiplicationNum;
		}
	}
	return temp;
}

Matrix2D MultiplyMatrix(Matrix2D* matrix1, Matrix2D* matrix2)
{
	if (matrix1->Size_M() == matrix2->Size_N())
	{
		Matrix2D temp(matrix1->Size_M(), matrix2->Size_N());
		temp.FillMatrix(0);
		
		for (size_t i = 0; i < matrix1->Size_M(); i++)
		{
			for (size_t j = 0; j < matrix2->Size_N(); j++)
			{
				for (size_t k = 0; k < matrix1->Size_N(); k++)
				{
					temp.Matrix[i][j] += matrix1->Matrix[i][k] * matrix2->Matrix[k][j];
				}
			}
		}
		return temp;
	}
	else
	{
		Matrix2D Error(1, 1);
		Error.FillMatrix(0);
		return Error;
	}
}
