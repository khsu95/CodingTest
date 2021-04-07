//https://www.acmicpc.net/problem/17822
//2021.04.07
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

void Rotate(vector < vector<int>>& table, int th, int dir, int num)
{
	for (int i = th-1;i < table.size();i+=th)
	{
		vector<int> temp = table[i];
		if (!dir)
		{
			for (int j = 0;j < table[0].size();j++)
			{
				temp[(j + num) % table[0].size()] = table[i][j];
			}
		}
		else
		{
			for (int j = table[0].size()-1;j >= 0;j--)
			{
				//Problem said that num<table[0].size()
				temp[(j - num+table[0].size()) % table[0].size()] = table[i][j];
			}
		}
		table[i] = temp;
	}
}

bool DFS(vector<vector<int>>& table,vector<vector<int>> &memo,ii coor,bool &flag)
{
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	bool temp = 0;
	memo[coor.first][coor.second] = 1;
	for (int i = 0;i < 4;i++)
	{
		int x = coor.first + dx[i], y = coor.second + dy[i];
		if (y == -1)
			y = table[0].size() - 1;
		if (y == table[0].size())
			y = 0;
		if (!((x >= 0) && (x < table.size()) && (y >= 0) && (y < table[0].size())))	
			continue;
		if (table[coor.first][coor.second] == table[x][y] && table[x][y] && !memo[x][y])
		{
			temp = flag = 1;
			DFS(table, memo, ii(x, y), flag);
			table[x][y] = 0;
		}
	}
	if(temp)
		table[coor.first][coor.second] = 0;
	return flag;
}

void avg(vector<vector<int>>& table)
{
	int sum = 0, num = 0;
	for (int i = 0;i < table.size();i++)
	{

		for (int j = 0;j < table[0].size();j++)
		{
			if (table[i][j])
			{
				sum += table[i][j];
				num += 1;
			}
		}
	}

	double avg = ((double)sum / (double)num);
	for (int i = 0;i < table.size();i++)
	{
		for (int j = 0;j < table[0].size();j++)
		{
			if ((table[i][j] < avg) && (table[i][j]))
				table[i][j] += 1;
			else if((table[i][j]>avg)&&table[i][j])
				table[i][j] -= 1;
		}
	}
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int circle, num_circle, num_rot;
	cin >> circle >> num_circle >> num_rot;
	vector<vector<int>> table(circle, vector<int> (num_circle, 0));
	for (int i = 0;i < circle;i++)
	{
		for (int j = 0;j < num_circle;j++)
		{
			cin >> table[i][j];
		}
	}

	for (int i = 0;i < num_rot;i++)
	{
		int cir, dir, cnt;
		bool flag = 0;
		cin >> cir >> dir >> cnt;
		Rotate(table, cir, dir, cnt);
		vector<vector<int>> memo(table.size(), vector<int>(table[0].size(), 0));
		for (int j = 0;j < table.size();j++)
		{
			for (int k = 0;k < table[0].size();k++)
			{
				if (!memo[j][k])
					DFS(table, memo, ii(j, k), flag);
			}
		}
		if (!flag)
			avg(table);
	}
	int ans = 0;
	for (int i = 0;i < table.size();i++)
		for (int j = 0;j < table[0].size();j++)
			ans += table[i][j];
	cout << ans;
	return 0;
}