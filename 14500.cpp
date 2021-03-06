//https://www.acmicpc.net/problem/14500
//2021.03.07
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef struct node
{
	int x = 0;
	int y = 0;
	int cnt = 0;
	int sum = 0;
}Node;

int ans = 0;


//Another Type
void T_Type(vector<vector<int>> table)
{
	int sum = 0;
	for (int col = 0;col < table.size();col++)
	{
		for (int row = 1;row < table[0].size() - 1;row++)
		{
			sum = table[col][row - 1] + table[col][row] + table[col][row + 1];
			int up = 0, down = 0;
			if (col - 1 >= 0)
				up = table[col - 1][row];
			if (col + 1 < table.size())
				down = table[col + 1][row];

			sum += ((up > down) ? up : down);
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
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	cin >> col >> row;
	vector<vector<int>> arr(col, vector<int>(row, 0));
	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> arr[i][j];

	for (int i = 0;i < arr.size();i++)
	{
		for (int j = 0;j < arr[0].size();j++)
		{
			vector<vector<bool>> memo(arr.size(),vector<bool> (arr[0].size(),0));	memo[i][j] = 1;
			Node first = { i,j,1, arr[i][j] };
			queue<Node> q;q.push(first);
			while (!q.empty())
			{
				Node n = q.front();q.pop();
				if (n.cnt >= 4)
				{
					ans = (n.sum > ans) ? n.sum : ans;
					continue;
				}
				for (int k = 0;k < 4;k++)
				{
					int x = n.x + dx[i], y = n.y + dy[i];
					if ((x >= 0) && (x < memo.size()) && (y >= 0) && (y < memo[0].size()))
					{
						memo[i][j] = true;
						q.push(Node{x,y,n.cnt+1,n.sum+arr[x][y]});
					}

				}
			}
		}
	}

	T_Type(arr);
	T_Type(Transpose(arr));
	cout << ans;
	return 0;
}