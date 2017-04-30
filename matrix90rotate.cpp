#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void rotate90(int **mat,int N)
{
	for(int i = 0; i < N/2; ++i)
	{
		for(int j = i; j < N - i - 1; ++j)
		{
			int temp = mat[i][j];
			mat[i][j] = mat[j][N - i - 1];
			mat[j][N - i -1] = mat[N - i -1][N - j - 1];
			mat[N - i - 1][N - j - 1] = mat[N - 1 - j][i];
			mat[N - 1 -j][i] = temp;
		}
	}
}

int main()
{
	int M, N;
	int **mat;
	cout << "enter the matrix.." << endl;
	
	cin >> M;
	mat = new int*[M];

	for (int i = 0; i < M; ++i)
		mat[i] = new int[M];

	for(int i = 0; i < M; ++i)
		for(int j = 0; j < M; ++j)
			cin >> mat[i][j];

	rotate90(mat,M);

    cout << "The matrix is" << endl;
	for (int i = 0; i < M; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}

	for(int i = 0; i < M; i++)
		delete[] mat[i];
	delete[] mat;

	return 0;
}