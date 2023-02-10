#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix2D
{
public:
	vector<vector<int>> Matrix;

	Matrix2D(string type) // stop laughing at me! this'll change!
	{
		if (type == "2x2")
		{
			Matrix = { {0, 0},
					   {0, 0} };
		}
		else if (type == "3x3")
		{
			Matrix = { {0, 0, 0},
					   {0, 0, 0},
					   {0, 0, 0} };
		}
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
	Matrix2D test("3x3");
	test.FillMatrix(6);
	test.PrintMatrix();

	return 0;
}
