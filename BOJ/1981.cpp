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
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class state
{
public:
	int l_x, l_y;
	int min, max;
	state(int x, int y, int nmin, int nmax) { l_x = x; l_y = y; min = nmin; max = nmax; };
	bool operator< (const state& a) const
	{
		if (l_x != a.l_x)	return l_x > a.l_x;
		if (l_y != a.l_y)	return l_y > a.l_y;
		if (min != a.min)	return min < a.min;
		if (max != a.max)	return max < a.max;
		return false;
	};
};

#if 1
/* down, up, right, left*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#endif

int main()
{
	freopen("input.txt", "r", stdin);
	int row;
	cin >> row;
	vvi t(row, vi(row, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> t[i][j];
		}
	}

	int ans = MAX_INT;
	queue<state> q;
	set<state> s;
	q.push(state(0, 0, t[0][0], t[0][0]));
	s.insert(state(0, 0, t[0][0], t[0][0]));
	while (!q.empty())
	{
		state cState = q.front(); q.pop();
		if ((cState.max - cState.min) >= ans)	continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = cState.l_x + dx[i];
			int ny = cState.l_y + dy[i];
			if ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < row))
			{
				int nMin = (t[nx][ny] < cState.min) ? t[nx][ny] : cState.min;
				int nMax = (t[nx][ny] > cState.max) ? t[nx][ny] : cState.max;
				state nState(nx, ny, nMin, nMax);
				if ((nx == (row - 1)) && (ny == (row - 1)))
				{
					ans = ((nMax - nMin) < ans) ? (nMax - nMin) : ans;
					continue;
				}
				if ((nMax - nMin) > ans)
					continue;
				if (!(s.insert(nState).second))
					continue;
				q.push(nState);
			}
		}
	}
	cout << ans << endl;
	return 0;
}