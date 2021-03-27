//https://www.acmicpc.net/problem/16236
//2021.03.27
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int main(int argc, char** argv)
{
	//Input
	freopen("input.txt", "r", stdin);
	int col;
	ii loc;
	cin >> col;
	vector<vector<int>> table(col, vector<int>(col, 0));
	for (int i = 0;i < col;i++)
	{
		for (int j = 0;j < col;j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 9)
				loc = ii(i, j);
		}
	}

	queue<ii> q;
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int size_shark = 2, eated = 0, time = 0;
	bool flag = 0;

	while (!flag)
	{
		q.push(loc);
		vector<vector<bool>> memo(col, vector<bool>(col, 0));
		flag = 1;

		while (!q.empty())
		{
			ii now_loc = q.front();q.pop();
			if (memo[now_loc.first][now_loc.second])	continue;
			memo[now_loc.first][now_loc.second] = 1;
			for (int i = 0;i < 4;i++)
			{
				int x = now_loc.first + dx[i], y = now_loc.second + dy[i];
				if ((x >= 0) && (x < col) && (y >= 0) && (y < col))
				{
					if (table[x][y])
					{
						if (table[x][y] < size_shark)
						{

							while (!q.empty())	q.pop();
							table[loc.first][loc.second] = 0;
							table[x][y] = 0;
							time += (abs(loc.first - x) + abs(loc.second - y));
							eated++;
							loc = ii(x, y);
							flag = 0;
							if (eated >= size_shark)
							{
								size_shark++;
								eated = 0;
							}
							break;
						}
						else if (table[x][y] == size_shark)
							q.push(ii(x, y));
					}
					else
					{
						q.push(ii(x, y));
					}
				}
			}
		}
	}

	cout << time;
	return 0;
}