/*
 * 3197.cpp
 *
 *  Created on: 2022. 01. 20.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/3197
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

class my_set
{
public:
	vector<int> setA;
	void init(int num)
	{
		setA.assign(num + 1, 0);
		for (int i = 0; i < setA.size(); i++)
		{
			setA[i] = i;
		}
	};
	int whoParent(int child)
	{
		if (setA[child] == child)
		{
			return child;
		}
		else
		{
			return whoParent(setA[child]);
		}
	};
	void union_set(int a, int b)
	{
		setA[whoParent(a)] = setA[whoParent(b)];
	};
};

class my_class
{
public:
	vector<vector<char>> table;
	queue<iii>			ice;
	my_set				ms;
	ii swanA, swanB;
	int ans = 0;
	int cnt = 3;
	my_class(int row, int col)
	{
		table.assign(row, vector<char>(col, 0));
		swanA = ii(9999, 9999);
	};
	void clustering()
	{
		table[swanA.first][swanA.second] = 1;
		DFS(swanA);
		table[swanB.first][swanB.second] = 2;
		DFS(swanB);

		for (int i = 0; i < table.size(); i++)
		{
			for (int j = 0; j < table[0].size(); j++)
			{
				if (table[i][j] == '.')
				{
					table[i][j] = cnt++;
					DFS(ii(i, j));
				}
				else if(table[i][j]=='X')
				{
					ice.push(iii(ii(i, j), 1));
				}
			}
		}
		ms.init(cnt - 1);
	};
	void DFS(ii coor)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = coor.first + dx[i];
			int ny = coor.second + dy[i];
			if ((nx >= 0) && (nx < table.size()) && (ny >= 0) && (ny < table[0].size()))
			{
				if (table[nx][ny] == '.')
				{
					table[nx][ny] = table[coor.first][coor.second];
					DFS(ii(nx, ny));
				}
			}
		}
	};
	void thaw()
	{
		queue<iii>			beIce;
		if (ms.whoParent(1) == ms.whoParent(2))
		{
			ans = 0;
			return;
		}

		while (!ice.empty())
		{
			ii aIce = ice.front().first;
			int cIce = ice.front().second;
			vector<int> beSet;
			ice.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = aIce.first  + dx[i];
				int ny = aIce.second + dy[i];
				if ((nx >= 0) && (nx < table.size()) && (ny >= 0) && (ny < table[0].size()))
				{
					if (table[nx][ny] != 'X')
					{
						beSet.push_back(table[nx][ny]);
					}
				}
			}

			vector<int>::iterator fIter = beSet.begin();
			vector<int>::iterator nIter = beSet.begin();

			if (fIter != beSet.end())
			{
				beIce.push(iii(aIce, cIce));
			}
			else
			{
				ice.push(iii(aIce, cIce + 1));
			}

			while (++nIter != beSet.end())
			{
				ms.union_set(*fIter, *nIter);
			}
			if (fIter != beSet.end())
			{
				table[aIce.first][aIce.second] = (*fIter);
			}

			if (ms.whoParent(1) == ms.whoParent(2))
			{
				ans = cIce;
				return;
			}
		}
	}
};

int main()
{
	freopen("input.txt","r", stdin);

	int row, col, ans;
	cin >> row >> col;

	my_class mc(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> mc.table[i][j];
			if (mc.table[i][j] == 'L')
			{
				if (mc.swanA != ii(9999, 9999))
				{
					mc.swanB = ii(i, j);
				}
				else
				{
					mc.swanA = ii(i, j);
				}
			}
		}
	}
	mc.clustering();
	mc.thaw();
	cout << mc.ans;
}