#include <iostream>

using namespace std;


int main()
{
	const int rows = 4, col = 4;

	int *matrix = new int[rows * col];

	for(int i = 0; i < rows * col; ++i)
	{
		matrix[i] = i;
	}

	delete []matrix;
	
	return 0;
}