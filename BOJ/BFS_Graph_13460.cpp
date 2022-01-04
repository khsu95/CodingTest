//BFS
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };

typedef struct elem
{
	vector<vector<char>> table;
	ii red;
	ii blue;
	int cnt = 0;
	int dir = -1;
} Elem;

bool Move(vector<vector<char>> table, ii& ball, int dir)
{
	int x = ball.first, y = ball.second;
	while ((x >= 0) && (x < table.size()) && (y >= 0) && (y < table[0].size()))
	{
		//This is Possible, Because Table' Boundary is #
		if ((table[x + dx[dir]][y + dy[dir]] != '.') && (table[x + dx[dir]][y + dy[dir]] != 'O'))	break;
		x += dx[dir];
		y += dy[dir];
		if (table[x][y] == 'O')	break;
	}
	if (ii(x, y) == ball)	return 0;
	ball = ii(x, y);
	return 1;
}

bool Swap(vector<vector<char>>& table, ii a, ii b, ii dest)
{
	if (b == dest)
	{
		table[a.first][a.second] = '.';
		return 1;
	}
	else
	{
		char temp = table[a.first][a.second];
		table[a.first][a.second] = table[b.first][b.second];
		table[b.first][b.second] = temp;
	}
	return 0;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col, row, ans = -1;
	ii dest;
	cin >> col >> row;
	Elem First_Stage;
	First_Stage.table.assign(col, vector<char>(row, 0));
	for (int i = 0;i < col;i++)
	{
		for (int j = 0;j < row;j++)
		{
			cin >> First_Stage.table[i][j];
			if (First_Stage.table[i][j] == 'R')	First_Stage.red = ii(i, j);
			if (First_Stage.table[i][j] == 'B')	First_Stage.blue = ii(i, j);
			if (First_Stage.table[i][j] == 'O')	dest = ii(i, j);
		}
	}

	queue<Elem> q;q.push(First_Stage);
	while (!q.empty())
	{
		Elem Now = q.front();q.pop();
		if (Now.cnt >= 10)
			continue;
		//Try Down, Up, Left, Right, respectively
		for (int i = 0;i < 4;i++)
		{
			if (Now.dir == i)	continue;
			if ((Now.dir == 0) && (i == 1))	continue;
			if ((Now.dir == 1) && (i == 0))	continue;
			if ((Now.dir == 2) && (i == 3))	continue;
			if ((Now.dir == 3) && (i == 2))	continue;
			Elem Next = Now;
			//Must Go to The END
			if (Move(Next.table, Next.blue, i))
				if (Swap(Next.table, Now.blue, Next.blue, dest))
					continue;
			if(Move(Next.table, Next.red, i))
				Swap(Next.table, Now.red, Next.red, dest);
			ii bl = Next.blue; //This was the Key
			if (Move(Next.table, Next.blue, i))
				if (Swap(Next.table, bl, Next.blue, dest))
					continue;
			Next.dir = i;
			Next.cnt = Now.cnt + 1;

			//This is Possible, Because Coordination of Destination is Stored in dest
			if (Next.red == dest)
			{
				ans = Next.cnt;
				i = 5;
				while (!q.empty())	q.pop();
			}
			else q.push(Next);
		}
	}
	cout << ans;
	return 0;
}
