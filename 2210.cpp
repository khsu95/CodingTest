#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> ii;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
class RUN 
{
public:
	vector<vector<int>> table;
	set<string> s;
	set <string> ans;
	RUN()
	{
		table.assign(5, vector<int>(5, 0));
	};
	void DFS(string str, ii coor);
};
void RUN::DFS(string str,ii coor)
{
	if (str.size() ==6)
	{
		if(ans.find(str)==ans.end())
			ans.insert(str);
		return;
	}
	//if (s.find(str)!=s.end())	return;
	//s.insert(str);
	for (int i = 0;i < 4;i++)
	{
		int x = coor.first + dx[i];
		int y = coor.second + dy[i];
		if ((x >= 0) && (x < 5) && (y >= 0) && (y < 5))
			DFS(str + (char)(table[x][y] + '0'), ii(x, y));
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	RUN obj;
	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			cin >> obj.table[i][j];

	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			obj.DFS("", ii(i, j));
	cout << obj.ans.size();
	return 1;
}
