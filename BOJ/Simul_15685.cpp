//https://www.acmicpc.net/problem/15685
//2021.03.15
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
vector<vector<bool>> table;
void PP()
{
	for (int i = 0;i < table.size();i++)
	{
		cout << endl;
		for (int j = 0;j < table[0].size();j++)
		{
			cout << table[i][j] << " ";
		}
	}
	cout << "\n-------------------------------------" << endl;
}
void Gen(vector<ii> ancestor, int cnt,int maxi)
{
	//PP();
	if (cnt >= maxi)	return;

	ii last = ancestor.back();
	int len = ancestor.size();
	for (int i = len-2;i >=0;i--)
	{
		ii offspring = ancestor[i];
		//Parallel Translation
		offspring.first  -= last.first;
		offspring.second -= last.second;
		//Rotation
		offspring = ii(-1 * offspring.second, offspring.first);
		//Parallel Translation
		offspring.first  += last.first;
		offspring.second += last.second;
		//Push
		ancestor.push_back(offspring);
		//Marking
		table[offspring.second + 100][offspring.first + 100] = 1;
	}
	return Gen(ancestor, cnt + 1, maxi);
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	table.assign(250, vector<bool>(250, 0));
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
	int num, ans=0;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		int x, y, dir, gen;
		cin >> x >> y >> dir >> gen;
		vector<ii> temp;
		temp.push_back(ii(x, y));
		table[y + 100][x + 100] = 1;
		temp.push_back(ii(x + dx[dir], y + dy[dir]));
		table[y + dy[dir] + 100][x + dx[dir] + 100] = 1;
		Gen(temp, 0, gen);
	}

	for (int i = 0;i < table.size()-1;i++)
	{
		for (int j = 0;j < table[0].size()-1;j++)
		{
			if (table[i][j]
				&& table[i + 1][j]
				&& table[i][j + 1]
				&& table[i + 1][j + 1])
				ans++;
		}
	}

	cout << ans;
	return 0;
}
