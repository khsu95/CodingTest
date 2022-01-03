#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
typedef pair<int, int> ii;

int ans;
vector<int> v(5, 0);

ii Where_One(vector<bitset<10>> table);

bool DFS(vector<bitset<10>> table, int cnt, vector<int> rem)
{
	//Check
	ii One = Where_One(table);
	if (One.second == -1)	ans = cnt;
	if (cnt >= ans)    return 0;
	//DFS
	for (int i = 0;i < 5;i++)
	{
		//Check
		if (rem[i] <= 0)	continue;
		vector<bitset<10>> temp = table;
		//Set Up
		int j = 0, k = 0;
		while ((j <= i) && (j + One.first < 10))
		{
			k = 0;
			while ((k <= i) && (k + One.second < 10))
			{
				if (!temp[j + One.first][k + One.second])
					j = k = 999;
				else
					temp[j + One.first][k + One.second] = false;
				k++;
			}
			j++;
		}
		if ((j == i + 1) && (k == i + 1))
		{
			rem[i]--;
			DFS(temp, cnt + 1, rem);
			rem[i]++;
		}
	}
	return 0;
}

ii Where_One(vector<bitset<10>> table) {
	int i = -1, j = 0;
	while (++i < 10)
	{
		j = -1;
		if (table[i].none())	continue;
		while (!table[i][++j]);
		break;
	}
	return ii(i, j);
}

int main(int argc, char** argv)
{
	vector<bitset<10>> table(10, bitset<10> (0));
	vector<int> rem(5, 5);
	//freopen("input.txt", "r", stdin);
	bool temp = 0;
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cin >> temp;
			table[i][j] = temp;
		}
	}
			
	ans = 999;
	DFS(table, 0, rem);

	if (ans == 999)	printf("%d", -1);
	else printf("%d", ans);
	return 0;
}
