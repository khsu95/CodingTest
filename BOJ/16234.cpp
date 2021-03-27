//https://www.acmicpc.net/problem/16234
//2021.03.22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int region_sum;
int region_num;
int L, R;
int cnt;
vector<vector<int>> region_table;
vector<vector<int>> after_table;
vector<vector<int>> table;

void DFS(ii coor)
{
	if (region_table[coor.first][coor.second])	return;
	region_table[coor.first][coor.second] = region_num;
	region_sum += table[coor.first][coor.second];
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int x = coor.first + dx[i], y = coor.second + dy[i];
		if ((x >= 0) && (x < region_table.size()) && (y >= 0) && (y < region_table[0].size()))
		{
			if ((abs(table[x][y] - table[coor.first][coor.second]) >= L) && (abs(table[x][y] - table[coor.first][coor.second]) <= R))
			{
				DFS(ii(x, y));
			}
		}
	}
}

void PP(vector<vector<int>> v)
{
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void Fill(ii coor,int avg, vector<vector<bool>> &v)
{
	after_table[coor.first][coor.second] = avg;
	if (v[coor.first][coor.second])	return;
	v[coor.first][coor.second] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x = coor.first + dx[i], y = coor.second + dy[i];
		if ((x >= 0) && (x < region_table.size()) && (y >= 0) && (y < region_table[0].size()))
		{
			if ((region_table[x][y] == region_table[coor.first][coor.second]))
			{
				Fill(ii(x, y), avg,v);
			}
		}
	}
}

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int _size;
	cin >> _size >> L >> R;
	region_table.assign(_size, vector<int>(_size, 0));
	after_table.assign(_size, vector<int>(_size, 0));
	table.assign(_size, vector<int>(_size, 0));

	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			cin >> table[i][j];
	int maxi = 0;
	while (maxi++<2000)
	{
		vector<vector<bool>> v_table(_size, vector<bool>(_size, 0));
		region_num = 0;
		//Find Start Point
		for (int x = 0; x < _size;x++)
		{
			for (int y = 0; y < _size; y++)
			{
				if (!region_table[x][y])
				{
					region_num++;
					cnt = 0;
					region_sum = 0;
					DFS(ii(x, y));
					Fill(ii(x, y), region_sum / cnt,v_table);
				}
			}
		}
		//PP(region_table);
		if (table==after_table) break;
		
		//End Stage
		table = after_table;
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				after_table[i][j] = 0;
				region_table[i][j] = 0;
			}
		}
	}
	maxi = (maxi == 2001) ? 0 : maxi;
	cout << maxi-1;
	return 0;
	
}
