#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<map>

using namespace std;
#define M 8
#define N 8

enum color
{
	red,green,blue,white,black
};


void fill_(color screen[][N],int x, int y, color oldC, color newC)
{
	if(x < 0 || x >= M || y < 0  || y >= N)
		return;
	if(screen[x][y] != oldC)
		return;
	screen[x][y] = newC;
	fill_(screen, x+1, y, oldC, newC);
	fill_(screen, x, y+1, oldC, newC);
	fill_(screen, x-1, y, oldC, newC);
	fill_(screen, x, y-1, oldC, newC);
}

void fill(color screen[][N],int x, int y, color newC)
{
	color oldC = screen[x][y];
	fill_(screen,x,y, oldC,newC);
}

// Driver program to test above function
int main()
{
	color screen[M][N] = {{green, green, green, green, green, green, green, green},
					{green, green, green, green, green, green, red, red},
					{green, red, red, green, green, red, green, green},
					{green, blue, blue, blue, blue, red, green, red},
					{green, green, green, blue, blue, red, green, red},
					{green, green, green, blue, blue, blue, blue, red},
					{green, green, green, green, green, blue, green, green},
					{green, green, green, green, green, blue, blue, green},
					};
	int x = 4, y = 4;
	color newC = white;
	fill(screen, x, y, newC);

	cout << "Updated screen after call to floodFill: \n";
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		/*{
		if(screen[i][j] == 0)
			cout << "red  ";
		else if(screen[i][j] == 1)
			cout << "green ";
		else if(screen[i][j] == 2)
			cout << "blue ";
		else if(screen[i][j] == 3)
			cout << "white ";
		else
			cout << "black ";
		}*/
		cout << screen[i][j] << " ";
		cout << endl;
	}
	return 0;
}

