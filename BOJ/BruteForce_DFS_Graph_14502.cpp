//https://www.acmicpc.net/problem/14500
//2021.03.10
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int ans = 0;

void DFS(vector<vector<int>>& table, ii coor)
{
	table[coor.first][coor.second] = 3;
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
	for (int i = 0;i < 4;i++)
	{
		int x = coor.first + dx[i], y = coor.second + dy[i];
		if ((x >= 0) && (x < table.size()) && (y >= 0) && (y < table[0].size()))
			if (table[x][y] == 0)
				DFS(table, ii(x, y));
	}
}

int HowMany(vector<vector<int>> table)
{
	int cnt = 0;
	//DFS
	for (int i = 0;i < table.size();i++)
		for (int j = 0;j < table[0].size();j++)
			if (table[i][j] == 2)
				DFS(table, ii(i, j));
	//Count
	for (int i = 0;i < table.size();i++)
		for (int j = 0;j < table[0].size();j++)
			if (table[i][j] == 0)
				cnt++;
	return cnt;
}

int Wall(vector<vector<int>> table,ii coor,int cnt)
{
	table[coor.first][coor.second] = 4;

	if (cnt >= 3)	return HowMany(table);
	int j = coor.second + 1;
	for (int i = coor.first;i < table.size();i++) {
		for (j;j < table[0].size();j++) {
			if (table[i][j] == 0) {
				int temp = Wall(table, ii(i, j), cnt + 1);
				ans = ans > temp ? ans : temp;
			}
		}
		j = 0;
	}
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col, row;
	cin >> col >> row;
	vector<vector<int>> table(col, vector<int>(row, 0));
	for (int i = 0;i < col;i ++)
		for (int j = 0;j < row;j++)
			cin >> table[i][j];

	for (int i = 0;i < col;i++) {
		for (int j = 0;j < row;j++) {
			if (table[i][j] == 0) {
				Wall(table, ii(i, j), 1);
			}
		}
	}
	cout << ans;

	return 0;
}
