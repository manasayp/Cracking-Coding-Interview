#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void setall0s(int **mat,int M, int N)
{
	int *row = new int[M]();
	int *col = new int[N]();
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if(mat[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if(col[j] == 1 || row[i] == 1)
				mat[i][j] = 0;
		}
	}

	delete[] row;
	delete[] col;
}

int main()
{
	int M, N;
	int **mat;
	cout << "enter the matrix.." << endl;
	
	cin >> M >> N;
	mat = new int*[M];

	for (int i = 0; i < M; ++i)
		mat[i] = new int[N];

	for(int i = 0; i < M; ++i)
		for(int j = 0; j < N; ++j)
			cin >> mat[i][j];

	setall0s(mat,M,N);

    cout << "The matrix is" << endl;
	for (int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
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