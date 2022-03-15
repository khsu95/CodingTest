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
	int min, max, nCost;
	state(int x, int y, int nmin, int nmax) { l_x = x; l_y = y; min = nmin; max = nmax; nCost = max - min; };
	bool operator< (const state& a) const
	{
		if ((a.l_x + a.l_y) != (l_x + l_y))	return a.l_x + a.l_y > l_x + l_y;
		if (a.l_x != l_x)	return a.l_x > l_x;
		if (a.l_y != l_y)	return a.l_y > l_y;
		if (a.min != min)	return a.min > min;
		if (a.max != max)	return a.max < max;

		return false;
	};
};
int loop4 = 0;
struct comp
{
	bool operator() (const ii& a, const ii& b) const
	{
		loop4++;
		if (a.first != b.first) return a.first > b.first;
		if (a.second != b.second) return a.second < b.second;
		return false;
	}
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

	vector<vector<set<ii, comp>>> vvs(row, vector<set<ii, comp>>(row));
	int ans = MAX_INT;
	priority_queue<state> q;
	q.push(state(0, 0, t[0][0], t[0][0]));
	vvs[0][0].insert(ii(t[0][0], t[0][0]));
	int loop = 0;
	int loop1 = 0;
	int loop2 = 0;
	while (!q.empty())
	{
		loop++;
		state cState = q.top(); q.pop();
		if (vvs[cState.l_x][cState.l_y].find(ii(cState.max, cState.min)) != vvs[cState.l_x][cState.l_y].end())	continue;
		if ((cState.max - cState.min) >= ans)	continue;
		for (int i = 0; i < 4; i++)
		{
			loop1++;
			int nx = cState.l_x + dx[i];
			int ny = cState.l_y + dy[i];
			if ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < row))
			{
				int nMin = (t[nx][ny] < cState.min) ? t[nx][ny] : cState.min;
				int nMax = (t[nx][ny] > cState.max) ? t[nx][ny] : cState.max;
				int nCost = nMax - nMin;
				if ((nx == (row - 1)) && (ny == (row - 1)))
				{
					ans = (nCost < ans) ? (nCost) : ans;
					continue;
				}
				if (nCost >= ans)
					continue;
				if (!(vvs[nx][ny].insert(ii(nMin, nMax)).second))
					continue;
				q.push(state(nx, ny, nMin, nMax));
				loop2++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}