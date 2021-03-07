#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class RUN 
{
public:
	int ans;
	vector<vector<int>> table;
	RUN(int i)
	{
		ans = 0;
		table.assign(i, vector<int>(2, 0));
	};
	void DFS(int day, int cost);
};

void RUN::DFS(int day, int cost)
{
	if (!(day < table.size()))
	{
		if (cost > ans)
			ans = cost;
		return;
	}
	if((day+table[day][0]-1)<table.size())
		cost += table[day][1];
	else
	{
		if (cost > ans)
			ans = cost;
	}
	for (int i = day +table[day][0];i < table.size();i++) 
	{
			DFS(i, cost);
	}
	if (cost > ans)
		ans = cost;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	int s;
	cin >> s;
	RUN obj(s);
	for (int i = 0;i < s;i++)
		for (int j = 0;j < 2;j++)
			cin >> obj.table[i][j];

	for (int i = 0;i < s;i++)
		obj.DFS(i, 0);
	cout << obj.ans;
	return 0;
}
