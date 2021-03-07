//DFS->Bridge Check(Make Graph)->Kruskal
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;

int Advance(bitset<3> & on_base, int hit)
{
	int point = 0;
	//Forfunately, All batter on the ground move forward
	bitset<8> Base_Dugout;
	Base_Dugout[0] = true;
	for (int i = 0;i < 3;i++)
		Base_Dugout[i + 1] = on_base[i];
	//Get on Base
	Base_Dugout <<= hit;
	//Point Count
	int i = 4;
	while (i < 8)
		if (Base_Dugout[i++])
			point++;
	//Copy
	i = -1;
	while (++i < 3)
		on_base[i] = Base_Dugout[i + 1];

	return point;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int inning;
	cin >> inning;
	vector<vector<int>> Table(inning, vector<int>(9, 0));
	for (int i = 0;i < Table.size();i++)
		for (int j = 0;j < Table[0].size();j++)
			cin >> Table[i][j];

	vector<int> Permut(8, 0);
	for (int i = 0;i < Permut.size();i++)
		Permut[i] = i + 1;


	int ans = 0;
	do
	{
		int point = 0;
		int turn = 0;
		//Always N.1 Batter is 4th
		vector<int> Batter = Permut;
		vector<int>::iterator iter = (Batter.begin() + 3);
		Batter.insert(iter, 0);
		//Inning
		int inning_cnt = 0;
		while (inning_cnt < inning) 
		{
			bitset<3> on_base;
			int out_cnt = 0;
			while (out_cnt < 3)
			{
				if (!Table[inning_cnt][Batter[turn % 9]])
					out_cnt++;
				else
					point += Advance(on_base, Table[inning_cnt][Batter[turn % 9]]);
				turn++;
			}
			inning_cnt++;
		}
		if (point > ans)	ans = point;
	} while (next_permutation(Permut.begin(), Permut.end()));
	cout << ans;
	return 0;
}