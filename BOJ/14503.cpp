//https://www.acmicpc.net/problem/14503
//2021.07.04
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,0, 1, 0 }, dy[4] = { 0,-1,0,1 };

typedef struct
{
	int x = 0, y = 0, dir = 0, num_cleaned = 0;
}_Robot;

int solution(vector<vector<int>>& table, int x, int y, int dir)
{
	_Robot robot = { x,y,dir,1 };

	while (1)
	{
		bool flag = 1;
		for (int i = 1;flag && i <= 4;i++)
		{
			int dir = (robot.dir + 1) % 4;
			if (table[robot.x + dx[dir]][robot.y + dy[dir]] == 0)
			{
				robot.x += dx[dir];
				robot.y += dy[dir];
				robot.dir = dir;
				robot.num_cleaned++;
				table[robot.x][robot.y] = 9;
				flag = 0;
			}
			else
				robot.dir = dir;
		}

		if (flag)
		{
			robot.x -= dx[robot.dir];
			robot.y -= dy[robot.dir];

			if (table[robot.x][robot.y] == 1)
				break;
		}
	}
	return robot.num_cleaned;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int col,row;
	cin >> col>>row;
	vector<vector<int>> table(col, vector<int> (row, 0));

	int x, y, dir;
	cin >> x>>y>>dir;

	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> table[i][j];

	table[x][y] = 9;

	if (dir == 3)	dir = 1;
	else if (dir == 1)	dir = 3;

	cout << solution(table, x,y,dir);
}