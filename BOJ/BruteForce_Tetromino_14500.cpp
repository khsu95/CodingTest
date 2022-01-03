//https://www.acmicpc.net/problem/14500
//2021.03.07
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int ans = 0;


//Type
// 4Square
void I_Type(vector<vector<int>> table)
{
	int sum = 0;
	for (int col = 0;col < table.size();col++)
	{
		for (int row = 0;row < table[0].size() - 3;row++)
		{
			sum = table[col][row] + table[col][row + 1] + table[col][row + 2] + table[col][row + 3];
			ans = (sum > ans) ? sum : ans;
		}
	}
}

//3 Square
void T_Type(vector<vector<int>> table)
{
	int sum = 0;
	for (int col = 0;col < table.size();col++)
	{
		for (int row = 0;row < table[0].size() - 2;row++)
		{
			sum = table[col][row] + table[col][row + 1] + table[col][row + 2];
			int up = 0, down = 0;
			for (int i = 0;i < 3;i++)
			{
				if(col-1>=0)
					if (table[col - 1][row + i] > up)
						up = table[col - 1][row + i];
				if(col+1<table.size())
					if (table[col + 1][row + i] > down)
						down = table[col + 1][row + i];
			}
			sum += ((up > down) ? up : down);
			ans = (sum > ans) ? sum : ans;
		}
	}
}

//2 Square
void Z_Type(vector<vector<int>> table)
{
	int sum = 0;
	for (int col = 1;col < table.size() - 1;col++)
	{
		for (int row = 0;row < table[0].size() - 1;row++)
		{
			sum = table[col][row] + table[col][row + 1];
			vector<int> v(4, 0);
			v[0] = table[col - 1][row];
			v[1] = table[col - 1][row + 1];
			v[2] = table[col + 1][row];
			v[3] = table[col + 1][row + 1];
			sort(v.begin(), v.end());
			sum += v[3] + v[2];
			ans = (sum > ans) ? sum : ans;
		}
	}
}


//Tanspose
vector<vector<int>> Transpose(vector<vector<int>> table)
{
	vector<vector<int>> trans(table[0].size(), vector<int>(table.size(), 0));
	for (int col = 0;col < table.size();col++)
		for (int row = 0;row < table[0].size();row++)
			trans[row][col] = table[col][row];
	return trans;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col, row;
	cin >> col >> row;
	vector<vector<int>> arr(col, vector<int>(row, 0));
	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> arr[i][j];

	T_Type(arr);
	I_Type(arr);
	Z_Type(arr);
	vector < vector<int>> trans = Transpose(arr);
	T_Type(trans);
	I_Type(trans);
	Z_Type(trans);
	cout << ans;
	return 0;
}
