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
};

int main()
{
	Matrix2D test(2, 7);
	test.FillMatrix(7);
	test.PrintMatrix();
	test.PrintMatrixSize();

	return 0;
}
