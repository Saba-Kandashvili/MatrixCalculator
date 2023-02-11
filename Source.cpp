#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix2D
{
public:
	vector<vector<int>> Matrix;

	Matrix2D(int size_i, int size_j)
	{
		vector<vector<int>> matrix(size_j, vector<int>(size_i));
		Matrix = matrix;
	}

	void SetIJ( int _i, int _j, int num)
	{
		Matrix[_i][_j] = num;
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
		cout << "Matrix Size: (" << Matrix[1].size() << "x" << Matrix.size() << ")" << endl;
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

	int Size_I()
	{
		return Matrix[1].size();
	}
	int Size_J()
	{
		return Matrix.size();
	}
};

Matrix2D AddMatrix(Matrix2D*, int);
Matrix2D AddMatrix(Matrix2D*, Matrix2D*);
Matrix2D MultiplyMatrix(Matrix2D*, int);
Matrix2D MultiplyMatrix(Matrix2D*, Matrix2D*);
int CoshBenFormulla(Matrix2D *, Matrix2D *);

int main()
{
	Matrix2D A(2, 3);
	A.SetIJ(0, 0, 2);
	A.SetIJ(0, 1, 5);
	A.SetIJ(1, 0, 3);
	A.SetIJ(1, 1, -1);
	A.SetIJ(2, 0, 8);
	A.SetIJ(2, 1, 6);

	Matrix2D B(3, 2);
	B.SetIJ(0, 0, 3);
	B.SetIJ(0, 1, 7);
	B.SetIJ(0, 2, 9);
	B.SetIJ(1, 0, -2);
	B.SetIJ(1, 1, -5);
	B.SetIJ(1, 2, 4);

	A.PrintMatrix();
	cout << endl << endl << endl << endl;
	B.PrintMatrix();
	cout << endl << endl << endl << endl;

	Matrix2D AB = MultiplyMatrix(&A, &B);
	AB.PrintMatrix();

	// Multiplication Doesn't work. Possiblt i-j mixup ;(

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
	if (matrix1->Size_I() == matrix2->Size_I() && matrix1->Size_J() == matrix2->Size_J())
	{
		Matrix2D temp(matrix1->Size_I(), matrix1->Size_J());
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
	if (matrix1->Size_I() == matrix2->Size_J())
	{
		Matrix2D temp(matrix1->Size_I(), matrix1->Size_J());
		temp.FillMatrix(0);
		for (size_t i = 0; i < matrix1->Size_I(); i++)
		{
			for (size_t j = 0; j < matrix2->Size_J(); j++)
			{
				for (size_t k = 0; k < matrix1->Size_I(); k++)
				{
					temp.Matrix[i][j] = matrix1->Matrix[i][k] * matrix2->Matrix[k][j];
				}
			}
		}
		return temp;
	}
}
