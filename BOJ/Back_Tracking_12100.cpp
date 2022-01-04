//https://www.acmicpc.net/problem/12100
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int ans = 0;

void Rotation(vector<vector<int>> table, vector<vector<int>> &rotation, int dir)
{
	switch (dir)
	{
	case 0:
		for (int col = 0;col < table.size();col++)
			for (int row = 0;row < table[0].size();row++)
				rotation[table.size() - 1 - row][col] = table[col][row];
		return;
	case 1:
		for (int col = 0;col < table.size();col++)
			for (int row = 0;row < table[0].size();row++)
				rotation[row][table.size() - 1 - col] = table[col][row];
		return;
	case 3:
		for (int col = 0;col < table.size();col++)
			for (int row = 0;row < table[0].size();row++)
				rotation[col][table.size() - 1 - row] = table[col][row];;
		return;
	}
}

bool Pointing(vector<vector<int>>& table, int dir)
{
	vector<vector<int>> N_table(table.size(), vector<int>(table[0].size(), 0));
	vector<vector<int>> Rotated_table(table.size(), vector<int>(table[0].size(), 0));
	if (dir != 2)
		Rotation(table, Rotated_table, dir);
	else
		Rotated_table = table;
	for (int col = 0;col < table.size();col++)
	{
		vector<int> v;
		int A = Rotated_table[col].front();
		for (int row = 1;row < Rotated_table[0].size();row++)
		{
			if (Rotated_table[col][row])
			{
				if (A != Rotated_table[col][row])
				{
					if (A)
						v.push_back(A);
					A = Rotated_table[col][row];
				}
				else
				{
					v.push_back(Rotated_table[col][row] * 2);
					A = 0;
				}
			}
		}
		v.push_back(A);

		for (int i = 0;i < v.size();i++)
			N_table[col][i] = v[i];
	}
	if (N_table == Rotated_table)	return 0;

	int hash[4] = { 1,0,2,3 };
	if (dir != 2)
		Rotation(N_table, table, hash[dir]);
	else
		table = N_table;

	return 1;
}

void DFS(vector<vector<int>> table, int cnt)
{
	for (int i = 0;i < table.size();i++)
		for (int j = 0;j < table[0].size();j++)
			if (table[i][j] > ans)
				ans = table[i][j];

	if (cnt >= 5)	return;

	for (int i = 0;i < 4;i++)
	{
		vector<vector<int>> N_table = table;
		//Move
		if(Pointing(N_table, i))
			DFS(N_table, cnt + 1);
	}
	return;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col;
	cin >> col;
	vector<vector<int>> table(col, vector<int>(col, 0));
	for (int i = 0;i < col;i++)
		for (int j = 0;j < col;j++)
			cin >> table[i][j];
	DFS(table, 0);
	cout << ans;
	return 0;
}
