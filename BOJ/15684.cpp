//https://www.acmicpc.net/problem/15684
//2021.07.22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
int ans = 4;
int maxi = 3;

bool Check(vector<vector<bool>>& table)
{
	for (int row = 1;row < table[0].size();row += 2)
	{
		int loc = row;
		for (int col = 1;col < table.size();col++)
		{
			if (table[col][loc - 1])
			{
				loc -= 2;
				continue;
			}
			if (loc < table[0].size() - 2)
			{
				if (table[col][loc + 1])
					loc += 2;
			}
		}
		if (loc != row)
			return 1;
	}
	return 0;
}

void Bridge(vector<vector<bool>> table, ii coor, int cnt)
{
	if (cnt >= ans || cnt >= maxi)
		return;


	table[coor.first][coor.second] = 1;

	if (!Check(table))
	{
		maxi = ans = cnt;
		return;
	}

	int row = cnt ? coor.second + 4 : coor.second;
	for (int col = coor.first;col < table.size();col++)
	{
		for (row;row < table[0].size() - 2;row += 2)
		{
			if (table[col][row])
			{
				row += 2;
				continue;
			}
			if (table[col][row + 2])
			{
				row += 4;
				continue;
			}
			Bridge(table, ii(col, row), cnt + 1);
			if ((cnt + 1 >= ans))
				return;
		}
		row = 2;
	}
}



int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int col, row, bridge;
	cin >> row >> bridge >> col;
	vector<vector<bool>> table(col + 1, vector<bool>(2 * row + 1, 0));
	for (int i = 1;i < table.size();i++)
		for (int j = 1;j < table[0].size();j++)
			table[i][j] = j % 2;
	for (int i = 0;i < bridge;i++)
	{
		int j, k;
		cin >> j >> k;
		table[j][2 * k] = 1;
	}

	Bridge(table, ii(0, 2), 0);
	if (ans == 4)	cout << -1;
	else cout << ans;

	return 0;
}