/*
 * 6087.cpp
 *
 *  Created on: 2022. 02. 13.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/6087
				USA Computing Olympiad > USACO January 2009 Contest > Silver 3
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;

class node
{
public:
	int dir, cost, x, y;
	node(int dir, int cost, int x, int y) {
		this->dir = dir; this->cost = cost; this->x = x;	this->y = y;
	}
};

bool operator < (node a, node b) { return a.cost > b.cost; }

/* down, up, right, left*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main()
{
	freopen("input.txt", "r", stdin);

	int row, col;
	int ans = MAX_INT;
	/*dir, cost*/
	ii start;
	cin >> col >> row;
	vvii t(row, vii(col, ii(0, 0)));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			char temp;
			cin >> temp;
			if ((temp == 'C')||(temp=='c'))
			{
				start = ii(i, j);
				t[i][j] = ii(-5, -1);
			}
			if (temp == '.')	t[i][j] = ii(0, MAX_INT);
			if (temp == '*')	t[i][j] = ii(MAX_INT, MAX_INT);
		}
	}
	priority_queue<node> q;
	t[start.first][start.second] = ii(15,0);
	q.push(node(-5, -1, start.first, start.second));
	while (!q.empty())
	{
		node poped = q.top(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			if ((poped.dir != -5) && ((poped.dir >> 1) == (i >> 1)) && (poped.dir != i)) continue;
			int nx = poped.x + dx[i], ny = poped.y + dy[i], cost = poped.cost;
			if ((nx < 0) || (nx >= row) || (ny < 0) || (ny >= col))	continue;
			if (t[nx][ny].first == MAX_INT)	continue;
			if (poped.dir != i) cost = poped.cost + 1;
			if (t[nx][ny].first == -5) 
			{
				ans = (cost < ans) ? cost : ans;	continue;
			}
			if (cost < t[nx][ny].second) 
			{ 
				t[nx][ny] = ii((1 << i), cost);
				q.push(node(i, cost, nx, ny));
			}
			else if (cost == t[nx][ny].second)
			{
				if (!((t[nx][ny].first) & (1 << i)))
				{
					t[nx][ny].first |= (1 << i);
					q.push(node(i, cost, nx, ny));
				}
			}
		}
	}
	cout << ans;
}