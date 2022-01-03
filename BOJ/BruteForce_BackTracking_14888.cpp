//https://www.acmicpc.net/problem/14888
//2021.03.11
#define _CRT_SECURE_NO_WARNINGS
#define MAX 2000000000
#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;
int ans1 = -1*MAX;//Max
int ans2 = MAX;//Min
bool flag = 0;

void DFS(vector<int> table, int sum, int index)
{
	if (index >= seq.size())
	{
		if (!flag)
		{
			ans1 = ans2 = sum;
			flag = 1;
		}
		ans1 = (sum > ans1) ? sum : ans1;
		ans2 = (sum < ans2) ? sum : ans2;
		return;
	}

	for (int i = 0;i < 4;i++)
	{
		vector<int> res = table;
		if (res[i] > 0)
		{
			res[i]--;
			switch (i)
			{
			case 0:
				DFS(res, sum + seq[index], index + 1);
				break;
			case 1:
				DFS(res, sum - seq[index], index + 1);
				break;
			case 2:
				DFS(res, sum * seq[index], index + 1);
				break;
			case 3:
				DFS(res, (int)(sum / seq[index]), index + 1);
				break;
			}
		}
	}
}


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col;
	cin >> col;
	seq.assign(col, 0);
	for (int i = 0;i < col;i++)
		cin >> seq[i];

	//+,-,*,/
	vector<int> op(4, 0);
	for (int i = 0;i < 4;i++)
		cin >> op[i];

	DFS(op, seq[0], 1);
	cout << ans1 << endl << ans2;

	return 0;
}
