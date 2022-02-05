/*
 * 3197.cpp
 *
 *  Created on: 2022. 01. 27.
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
			return setA[child] = whoParent(setA[child]);
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
	vector<vector<int>> table;
	queue<iii>			ice;
	my_set				ms;
	ii swanA, swanB;
	int ans = 0;
	int cnt = 302;
	my_class(int row, int col)
	{
		table.assign(row, vector<int>(col, 0));
		swanA = ii(9999, 9999);
	};
	void class_main()
	{
		while (!ice.empty())
		{
			ii unfrozen_ice = ice.front().first; 
			int cost = ice.front().second; ice.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = unfrozen_ice.first + dx[i];
				int ny = unfrozen_ice.second + dy[i];
				if ((nx >= 0) && (nx < table.size()) && (ny >= 0) && (ny < table[0].size()))
				{
					if (table[nx][ny] >= 300)
					{
						if (table[unfrozen_ice.first][unfrozen_ice.second] >= 300)
						{
							ms.union_set(table[unfrozen_ice.first][unfrozen_ice.second], table[nx][ny]);
						}
						else
						{
							table[unfrozen_ice.first][unfrozen_ice.second] = table[nx][ny];
						}
					}
					else if (table[nx][ny] == 'X')
					{
						table[nx][ny] = 'x';
						ice.push(iii(ii(nx, ny), cost + 1));
					}
				}
			}
			if (ms.whoParent(300) == ms.whoParent(301))
			{
				ans = cost;
				while (!ice.empty())	ice.pop();
			}
		}
	}
	void clustering()
	{
		table[swanA.first][swanA.second] = 300;
		DFS(swanA);
		table[swanB.first][swanB.second] = 301;
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
				else if (table[nx][ny] == 'X')
				{
					table[nx][ny] = 'x';
					ice.push(iii(ii(nx, ny),1));
				}
			}
		}
	};
};

int main()
{
	freopen("input.txt","r", stdin);

	int row, col;
	char temp;
	cin >> row >> col;

	my_class mc(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			if (temp == 'L')
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
			mc.table[i][j] = temp;
		}
	}
	mc.clustering();
	if (mc.ms.whoParent(300) == mc.ms.whoParent(301))	mc.ans = 0;
	else	mc.class_main();
	cout << mc.ans;
}