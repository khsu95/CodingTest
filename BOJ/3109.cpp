/*
 *
 * 3109.cpp
 *
 *  Created on: 2022. 12. 18.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/3109
				Croatian Highschool Competitions in Informatics 2009 > Nataional Competition 1 > Juniors 3
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/* right-up, right, right-down */
int dx[4] = { -1,0, 1 };
int dy[4] = { 1, 1, 1 };

int ans;

bool DFS(ii start, vvi &mat, int depth, int col)
{
	bool flag = true;


	ans = depth > ans ? depth : ans;

	if (!((start.first < mat.size())
		&& (start.second < mat[0].size()) && (start.second >= 0)))
	{
		return true;
	}

	if (mat[start.first][start.second] == '.')
	{
		mat[start.first][start.second] = '*';
	}
	else
	{
		return true;
	}

	if (start.second == mat[0].size() - 1)
	{
		for (int i = col + 1; (i < mat.size())&&flag; i++)
		{
			flag = DFS(ii(i, 0), mat, depth + 1, i);
		}
		return false;
	}
	else
	{
		

		for (int i = 0; (i < 3)&&flag; i++)
		{
			ii nNode = ii(start.first + dx[i], start.second + dy[i]);

			if ((nNode.first < mat.size())
				&& (nNode.second < mat[0].size()) && (nNode.second >= 0))
			{
				if (mat[nNode.first][nNode.second] == '.')
				{
					flag = DFS(nNode, mat, depth, col);
				}
			}
		}
	}
	return flag;


}

int main()
{
	//freopen("input.txt", "r", stdin);
	int row, col;
	cin >> row >> col;
	vvi mat(row, vector<int>(col, 0));

	for (int i = 0; i < row; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = str[j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		if (mat[i][0] == '.')
		{
			DFS(ii(i, 0), mat, 0,i);
		}
	}

	cout << ans;

	return 0;
}