//https://www.acmicpc.net/problem/14889
//2021.03.12
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<vector<int>> table;
int people;
int ans = 99999999999999;

int calc(vector<bool> team)
{
	int team1 = 0, team2 = 0;
	for (int i = 0;i < team.size() - 1;i++)
	{
		for (int j = i + 1;j < team.size();j++)
		{
			if (team[i] == team[j])
			{
				if (team[i])
					team1 += (table[i][j] + table[j][i]);
				else
					team2 += (table[i][j] + table[j][i]);
			}
		}
	}
	return abs(team1 - team2);
}

void JoinMe(vector<bool> team, int idx, int team1, int team2, int maxi)
{
	if (idx >= team.size())
	{
		ans = (calc(team) < ans) ? calc(team) : ans;
		return;
	}
	if ((team1 > team2 ? team1 : team2) == maxi)
	{
		bool temp = 0;
		if (team1 > team2)
			temp = 1;
		else
			temp = 0;
		while (idx < team.size())
			team[idx++] = temp;
		ans = (calc(team) < ans) ? calc(team) : ans;
		return;
	}
	JoinMe(team, idx + 1, team1 + 1, team2, maxi);
	team[idx] = 1;
	JoinMe(team, idx + 1, team1, team2 + 1, maxi);
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	cin >> people;
	table.assign(people, vector<int> (people,0));
	for (int i = 0;i < people;i++)
		for (int j = 0;j < people;j++)
			cin >> table[i][j];
	
	vector<bool> team(people, 0);
	JoinMe(team, 1, 1, 0, people/2);
	cout << ans;
	return 0;
}
