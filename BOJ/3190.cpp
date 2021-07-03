#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

int dir_table[4][2] = {{2,3},  //Right to Up or Down
					   {3,2},  //Left to Down or Up
					   {1,0},  //Up to Left or Right
					   {0,1}}; //Down to Right or Left

int  Drive_Direction(int now_Time, int instruction_Time, int instruction,int* idx, int dir)
{
	if (now_Time == instruction_Time)
	{
		(*idx)++;
		return dir_table[dir][instruction];
	}
	else
		return dir;
}

int Select_Next_Lattice(vector<vector<ii>>& table, int dir,int &x, int &y)
{
	table[x][y].second = dir;
	x = x + dx[dir], y = y + dy[dir];
	if ((x < 0) || (x >= table.size()) || (y < 0) || (y >= table[0].size()))
		return 0;
	if (table[x][y].first == 9)
		return 0;
	if (table[x][y].first == 1)
	{
		table[x][y] = ii(9, dir);
		return 1;
	}
	else if (table[x][y].first == 0)
	{
		table[x][y] = ii(9, dir);
		return 2;
	}
}

ii Tail_Delete(vector<vector<ii>>& table, ii tail)
{
	int next_tail_dir = table[tail.first][tail.second].second;
	ii next_tail = ii(tail.first + dx[next_tail_dir], tail.second + dy[next_tail_dir]);
	table[tail.first][tail.second] = ii(0, 0);
	return next_tail;
}

int solution(vector<vector<ii>> table, vector<ii> instruction)
{
	int dir = 0, now_time = 0, idx = 0, x = 0, y = 0;
	ii tail(0,0);
	while (1)
	{
		if(idx<instruction.size())
			dir = Drive_Direction(now_time, instruction[idx].first, instruction[idx].second, &idx, dir);
		int state = Select_Next_Lattice(table, dir, x, y);

		if (!state)
			return now_time + 1;

		else if (state == 2)
			tail=Tail_Delete(table, tail);

		now_time++;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int table_size;
	cin >> table_size;
	vector<vector<ii>> table(table_size, vector<ii>(table_size, ii(0,0)));

	int num;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		int x, y;
		cin >> x >> y;
		table[x-1][y-1].first = 1;
	}

	cin >> num;
	vector<ii> inst(num);
	for (int i = 0;i < num;i++)
	{
		int time;char dir;
		cin >> time >> dir;
		inst[i].first = time;
		if (dir == 'D')
			inst[i].second = 1;
		else
			inst[i].second = 0;
	}

	table[0][0]=ii(9,2);
	cout << solution(table, inst);
}