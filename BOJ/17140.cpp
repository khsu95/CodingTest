//https://www.acmicpc.net/problem/17140
//2021.03.31
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

vector<vector<int>> trans(vector<vector<int>> t)
{
	vector<vector<int>> temp(t[0].size(), vector<int>(t.size(), 0));
	for (int i = 0;i < t.size();i++)
		for (int j = 0;j < t[0].size();j++)
			temp[j][i] = t[i][j];
	return temp;
}

bool Compare(ii a, ii b)
{
	if (a.second != b.second)
		return a.second > b.second;
	return a.first > b.second;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int t_row, t_col, t_num;
	cin >> t_row >> t_col >> t_num;
	t_row--;t_col--;

	int answer = 0;
	vector<vector<int>> b(3, vector<int>(3, 0));
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			cin >> b[i][j];

	while (b[t_row][t_col] != t_num)
	{
		if (answer > 100)
		{
			answer = -1;
			break;
		}

		bool flag = 0;
		if (b.size() < b[0].size())
		{
			b = trans(b);
			flag = 1;
		}

		vector<vector<int>> n_b;
		for (int i = 0;i < b.size();i++)
		{
			vector<ii> temp_row;
			for (int j = 0;j < b[0].size();j++)
			{
				int idx = 0;
				for (idx = 0;idx < temp_row.size();idx++)
				{
					if (temp_row[idx].first == b[i][j])
					{
						temp_row[idx].second++;
						idx--;
						break;
					}
				}
				if (idx >= temp_row.size())
					temp_row.push_back(ii(b[i][j], 1));
			}
	
			sort(temp_row.begin(), temp_row.end(), Compare);
			vector<ii>::iterator iter = temp_row.begin();
			vector<int> n_row;
			while (iter != temp_row.end())
			{
				int cnt = 0;
				while ((*iter).second > cnt)
				{
					n_row.push_back((*iter).first);
					cnt++;
				}
				if (cnt > 1)
					n_row.push_back((*iter).second);
				iter++;
			}
			n_b.push_back(n_row);
		}
		b = n_b;

		int maxi = 0;
		for (int i = 0;i < b.size();i++)
			maxi = (maxi > b[i].size()) ? maxi : b[i].size();
		for (int i = 0;i < b.size();i++)
			for (int j = b[i].size();j < maxi;j++)
				b[j].push_back(0);

		if (flag)
			b = trans(b);
		answer++;
	}

	cout << answer;
	return 0;

}