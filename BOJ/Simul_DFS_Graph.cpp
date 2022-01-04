//https://www.acmicpc.net/problem/16236
//2021.03.27
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<vector<int>> table;
struct comp
{
	bool operator ()(iii a, iii b)
	{
		if (a.first != b.first)
			return a.first > b.first;
		else
		{
			if (a.second.first != b.second.first)
				return a.second.first > b.second.first;
			else
				return a.second.second > b.second.second;
		}
	}
};

int main(int argc, char** argv)
{
	//Input
	freopen("input.txt", "r", stdin);
	int col;
	ii loc;
	cin >> col;
	table.assign(col, vector<int>(col, 0));
	for (int i = 0;i < col;i++)
	{
		for (int j = 0;j < col;j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 9)
				loc = ii(i, j);
		}
	}

	priority_queue<iii,vector<iii>,comp> q;
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int size_shark = 2, eated = 0, time = 0;
	bool flag = 0;

	while (!flag)
	{
		q.push(iii(0,loc));
		vector<vector<bool>> memo(col, vector<bool>(col, 0));
		flag = 1;

		while (!q.empty())
		{
			ii now_loc = q.top().second;int dist = q.top().first;q.pop();
			if (memo[now_loc.first][now_loc.second])	continue;
			memo[now_loc.first][now_loc.second] = 1;

			if ((table[now_loc.first][now_loc.second])&&(table[now_loc.first][now_loc.second] < size_shark))
			{
				while (!q.empty())	q.pop();
				table[loc.first][loc.second] = 0;
				table[now_loc.first][now_loc.second] = 99999;
				time += dist;
				eated++;
				loc = now_loc;
				flag = 0;
				if (eated >= size_shark)
				{
					size_shark++;
					eated = 0;
				}
				break;
			}

			for (int i = 0;i < 4;i++)
			{
				int x = now_loc.first + dx[i], y = now_loc.second + dy[i];
				if ((x >= 0) && (x < col) && (y >= 0) && (y < col))
				{
					if ((!memo[x][y])&&table[x][y]<=size_shark)
					{
							q.push(iii(dist+1,ii(x, y)));
					}
				}
			}
		}
	}

	cout << time;
	return 0;
}
