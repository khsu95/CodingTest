//https://www.acmicpc.net/problem/15685
//2021.03.15
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
typedef pair<int, int> ii;

int Min(vector<int> home, vector<bool> store)
{
	int min = 9999;
	for (int i = 0;i < home.size();i++)
		if (store[i])
			min = (home[i] < min) ? home[i] : min;
	return min;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<ii> store_list, home_list;
	vector<vector<int>> dist;
	vector<vector<int>> table(n, vector<int>(n, 0));
	
	//Input Part
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 1)
			{
				home_list.push_back(ii(i, j));
				vector<int> temp;
				for (int k = 0;k < store_list.size();k++)
					temp.push_back(abs(store_list[k].first - i) + abs(store_list[k].second - j));
				dist.push_back(temp);
			}
			if (table[i][j] == 2)
			{
				store_list.push_back(ii(i, j));
				for (int k = 0;k < home_list.size();k++)
					dist[k].push_back(abs(home_list[k].first - i) + abs(home_list[k].second - j));
			}
		}
	}

	//Combination
	vector<bool> comb(store_list.size(),0);
	fill(comb.end() - m, comb.end(), true);
	int ans = 9999;
	do
	{
		int temp_ans = 0;
		for (int i = 0;i < home_list.size();i++)
		{
			temp_ans += Min(dist[i], comb);
		}
		ans = (temp_ans < ans) ? temp_ans : ans;

	} while (next_permutation(comb.begin(), comb.end()));
	cout << ans;
	return 0;
}