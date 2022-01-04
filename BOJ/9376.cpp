//https://www.acmicpc.net/problem/9376
//2022.01.04
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void DFS(vector<vector<char>>& mat, ii poi, char zn)
{
	mat[poi.first][poi.second] = zn;

	for(int i=0;i<4;i++)
	{
		int nx = poi.first  + dx[i];
		int ny = poi.second + dy[i];
		if ((nx >= 0) && (nx < mat.size() && (ny >= 0) && (ny < mat[0].size())))
		{
			if (mat[nx][ny] == '$' || mat[nx][ny] == '.')
			{
				DFS(mat, ii(nx, ny), zn);
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int cs;
	int col, row;
	char zn = 'a';
	//cin >> cs;
	cin >> col >> row;
	vector<vector<char>> mat(col + 2, vector<char>(row + 2, '.'));
	
	//Padding
	for (int i = 1; i < col+1; i++)
	{
		for (int j = 1; j < row+1; j++)
		{
			cin >> mat[i][j];
		}
	}

	//Make Cluster
	for (int i = 0; i < col+2; i++)
	{
		for (int j = 0; j < row+2; j++)
		{
			if (mat[i][j] == '$' || mat[i][j] == '.')
			{
				DFS(mat, ii(i, j), zn);
				zn=zn+1;
			}
		}
	}

	//make Minimum Cost Adj List
	//Use Dijkstra

	//On-Off BruteForce
	//Find which node is best they can join in


#if 0
	for (int i = 0; i < col+2; i++)
	{
		for (int j = 0; j < row+2; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
#endif

	return 0;
}