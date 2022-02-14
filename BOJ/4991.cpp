/*
 * 4991.cpp
 *
 *  Created on: 2022. 02. 15.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/4991
				ICPC >> 2005 Japan Domestic Contest F
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct comp
{
	bool operator() (iii a, iii b)
	{
		return a.second > b.second;
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
	int row, col;
	cin >> col >> row;

	while (col)
	{
		vvi t(row, vi(col, -1));
		vii spot;
		int startIdx;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				char temp;
				cin >> temp;
				if (temp == 'o')
				{
					startIdx = spot.size();
					t[i][j] = startIdx;
					spot.push_back(ii(i, j));
				}
				if (temp == '*')
				{
					t[i][j] = spot.size();
					spot.push_back(ii(i, j));
				}
				if (temp == 'x')
				{
					t[i][j] = 789789;
				}
			}
		}

		//Make Graph
		vvii adj(spot.size());
		for (int idx = 0; idx < spot.size(); idx++)
		{
			vvi arr(t);
			queue<iii> q;
			q.push(iii(spot[idx], 0));
			arr[spot[idx].first][spot[idx].second] = 789789;
			while (!q.empty())
			{
				iii elem = q.front(); q.pop();
				for (int j = 0; j < 4; j++)
				{
					int nx = elem.first.first + dx[j];
					int ny = elem.first.second + dy[j];
					if ((nx >= 0) && (nx < arr.size()) && (ny >= 0) && (ny < arr[0].size()))
					{
						if (arr[nx][ny] == 789789)	continue;
						if (arr[nx][ny] != -1)
						{
							adj[idx].push_back(ii(arr[nx][ny], elem.second + 1));
						}
						q.push(iii(ii(nx, ny), elem.second + 1));
						arr[nx][ny] = 789789;
					}
				}
			}
		}

		//Use Greedy
		vi costArr(2048, MAX_INT);
		priority_queue<iii,vector<iii>,comp> pq;
		pq.push(iii(ii(1 << startIdx, startIdx), 0));
		int ans = 789789;
		while (!pq.empty())
		{
			iii elem = pq.top(); pq.pop();
			ii state = elem.first; int cost = elem.second;
			if (state.first == ((1 << spot.size()) - 1))
			{
				ans = (cost < ans) ? cost : ans;
				continue;
			}
			if (elem.second > costArr[state.first])	continue;
			for (int i = 0; i < adj[state.second].size(); i++)
			{
				int sstate = (1 << (adj[state.second][i].first));
				int nextState = (state.first | (1 << (adj[state.second][i].first)));
				int nextCost = cost + adj[state.second][i].second;
				if ((state.first == nextState)&&(state.second==nextCost))	continue;
				if (nextCost < costArr[nextState])
				{
					costArr[nextState] = nextCost;
					pq.push(iii(ii(nextState, adj[state.second][i].first), nextCost));
				}
			}
		}
		ans = (ans == 789789) ? -1 : ans;
		cout << ans << endl;


		cin >> col >> row;
	}
}