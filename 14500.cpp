//https://www.acmicpc.net/problem/14500
//2021.03.07
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;

int ans = 0;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
vector<vector<int>> arr;

//Four Type
void DFS(vector<vector<bool>> table, ii loc, int cnt, int sum)
{
	table[loc.first][loc.second] = 1;
	if (cnt >= 4)
	{
		if (sum > ans)
			ans = sum;
		return;
	}
	for (int i = 0; i < 4;i++)
	{
		int x = loc.first + dx[i], y = loc.second + dy[i];
		if ((x >= 0) && (x < table.size()) && (y >= 0) && (y < table[0].size()))
		{
			if (table[x][y])	continue;
			DFS(table, ii(x, y), cnt + 1, sum + arr[x][y]);
		}
	}
}

//Another Type
void T_Type(vector<vector<int>> table)
{
	int sum_ = 0, suml = 0;
	for (int col = 0;col < table.size();col++)
	{
		for (int row = 0;row < table[0].size();row++)
		{
			if ((row - 1 >= 0) && (row + 1 < table[0].size()))
			{
				sum_ = table[col][row - 1] + table[col][row] + table[col][row + 1];
				int up = 0, down = 0;
				if (col - 1 >= 0)
					up = table[col - 1][row];
				if (col + 1 < table.size())
					down = table[col + 1][row];
			
				sum_ += ((up > down) ? up : down);
			}
			if ((col - 1 >= 0) && (col + 1 < table.size()))
			{
				suml = table[col - 1][row] + table[col][row] + table[col + 1][row];
				int up = 0, down = 0;
				if (row - 1 >= 0)
					up = table[col - 1][row];
				if (row + 1 < table.size())
					down = table[col + 1][row];

				suml += ((up > down) ? up : down);
			}
			ans = (sum_ > ans) ? (sum_ > suml ? sum_ : suml) : ans;
		}
	}

}

//Tanspose
vector<vector<int>> Transpose(vector<vector<int>> table)
{
	vector<vector<int>> trans(table[0].size(), vector<int>(table.size(), 0));
	for (int col = 0;col < table.size();col++)
		for (int row = 0;row < table[0].size();row++)
			trans[row][col] = table[col][row];
	return trans;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col, row;
	cin >> col >> row;
	arr.assign(col, vector<int>(row, 0));
	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> arr[i][j];

	for (int i = 0;i < col;i++)
	{
		for (int j = 0;j < row;j++)
		{
			vector<vector<bool>> table(col, vector<bool>(row, 0));
			for (int k = 0;k <= i;k++)
				for (int l = 0;l <= j;l++)
					table[k][l] = true;
			DFS(table, ii(i, j), 1, arr[i][j]);
		}
	}

	T_Type(arr);
	T_Type(Transpose(arr));
	cout << ans;
	return 0;
}