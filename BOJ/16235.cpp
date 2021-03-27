//https://www.acmicpc.net/problem/16235
//2021.03.22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct comp {
	bool operator () (iii a, iii b) {
		return a.first > b.first;
	}
};

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> furtile_table(n, vector<int>(n, 5));
	vector<vector<int>> table(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> table[i][j];

	priority_queue<iii, vector<iii>, comp> pq;
	for (int i = 0; i < m; i++) 
	{
		int x, y, age;
		cin >> x >> y >> age;
		pq.push(iii(age, ii(x - 1, y - 1)));
	}

	for (int i = 0; i < k; i++)
	{
		priority_queue<iii, vector<iii>, comp> next_pq;
		queue<iii> died;
		queue<ii> propagation;
		//Spring
		while (!pq.empty())
		{
			iii tree = pq.top(); pq.pop();
			if (furtile_table[tree.second.first][tree.second.second] >= tree.first)
			{
				furtile_table[tree.second.first][tree.second.second] -= tree.first;
				tree.first += 1;
				if (!(tree.first % 5))
					propagation.push(tree.second);
				next_pq.push(tree);
			}
			else
			{
				died.push(iii(tree.first / 2, tree.second));
			}
		}
		//Summer
		while(!died.empty())
		{
			iii tree = died.front(); died.pop();
			furtile_table[tree.second.first][tree.second.second] += tree.first;
		}
		//Fall
		while(!propagation.empty())
		{
			int dx[8] = { 1,1,1,-1,-1,-1,0,0 }, dy[8] = { 0,1,-1,0,1,-1,-1,1 };
			ii coor = propagation.front(); propagation.pop();
			for (int kk=0; kk < 8; kk++)
			{
				int x = coor.first + dx[kk], y = coor.second + dy[kk];
				if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
					next_pq.push(iii(1, ii(x, y)));
			}
		}
		//Winter
		for (int j = 0; j < n; j++)
			for (int kk = 0; kk < n; kk++)
				furtile_table[j][kk] += table[j][kk];
		pq = next_pq;
	}
	cout << pq.size();
	return 0;
	
}
