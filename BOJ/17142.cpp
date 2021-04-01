//https://www.acmicpc.net/problem/17142
//2021.04.01
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
struct comp {
	bool operator() (iii a, iii b)
	{
		return a.first > b.first;
	}
};
int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int row, num,total=0;
	cin >> row >> num;
	vector<vector<int>> t(row, vector<int>(row, 0));
	vector<ii> virus;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < row;j++)
		{
			cin >> t[i][j];
			if (t[i][j] == 0)
				total++;
			if (t[i][j] == 2)
				virus.push_back(ii(i, j));
		}
	}

	if (!total)
	{
		cout << 0;
		return 0;
	}

	int _mini = 999999;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
	vector<bool> comb(virus.size(), 0);
	for (int i = 0;i < num;i++)    comb[comb.size()-1-i] = 1;
	do
	{
		int cnt = 0, flag = 0;
		vector<vector<int>> memo = t;
		priority_queue<iii,vector<iii>,comp> q;
		
		for (int i = 0;i < comb.size();i++)
		{
			if (comb[i])
			{
				memo[virus[i].first][virus[i].second] = 1;
				q.push(iii(0, virus[i]));
			}
		}

		while ((!q.empty()&&(!flag)))
		{
			ii elem = q.top().second;int dist = q.top().first;q.pop();
			if (dist >= _mini)	continue;
			if ((elem.first == 38)&&(elem.second==11))
				cout << "";

			for (int j = 0;j < 4;j++)
			{
				int x = elem.first + dx[j], y = elem.second + dy[j];
				if (!((x >= 0) && (x < row) && (y >= 0) && (y < row))) continue;
				if (memo[x][y] == 0)	cnt++;
				if (memo[x][y] != 1)
				{
					memo[x][y] = 1;
					q.push(iii(dist + 1, ii(x, y)));
				}
				if (cnt >= total)
				{
					flag = 1;
					_mini = (dist < _mini) ? dist : _mini;
					break;
				}
			}
		}
	} while (next_permutation(comb.begin(), comb.end()));
	_mini = (_mini == 999999) ? -1 : _mini+1;
	cout << _mini;
	return 0;
}