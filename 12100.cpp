#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int ans = 0;

void Moving(vector<int> &v, vector<vector<int>> table, int col, int row, int &A)
{
	if (table[col][row])
	{
		if (A != table[col][row])
		{
			if (A)
				v.push_back(A);
			A = table[col][row];
		}
		else
		{
			v.push_back(table[col][row] * 2);
			A = 0;
		}
	}
}

bool Pointing(vector<vector<int>>& table, int dir)
{
	vector<vector<int>> N_table(table.size(), vector<int>(table[0].size(), 0));

	switch (dir)
	{
	case 0:
		//Down
		for (int row = 0;row < table[0].size();row++)
		{
			vector<int> v;
			int A = table.back()[row];
			for (int col = table.size() - 2;col >= 0;col--)
				Moving(v, table, col, row, A);
			v.push_back(A);
			for (int i = 0;i < v.size();i++)
				N_table[table.size() - 1 - i][row] = v[i];
		}
		break;
	case 1:
		//Up
		for (int row = 0;row < table[0].size();row++)
		{
			vector<int> v;
			int A = table.front()[row];
			for (int col = 1;col < table.size();col++)
				Moving(v, table, col, row, A);
			v.push_back(A);
			for (int i = 0;i < v.size();i++)
				N_table[i][row] = v[i];
		}
		break;
	case 2:
		//Left
		for (int col = 0;col < table.size();col++)
		{
			vector<int> v;
			int A = table[col].front();
			for (int row = 1;row < table[0].size();row++)
				Moving(v, table, col, row, A);
			v.push_back(A);
			for (int i = 0;i < v.size();i++)
				N_table[col][i] = v[i];
		}
		break;
	case 3:
		//Right
		for (int col = 0;col < table.size();col++)
		{
			vector<int> v;
			int A = table[col].back();
			for (int row = table[0].size() - 2;row >= 0;row--)
				Moving(v, table, col, row, A);
			v.push_back(A);
			for (int i = 0;i < v.size();i++)
				N_table[col][table[0].size() - 1 - i] = v[i];
		}
		break;
	}
	if (N_table==table)	return 0;

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