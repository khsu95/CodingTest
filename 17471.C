
//In&Out Strategy
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

class Run {
public:
	vector<vector<int>> adj_list;
	vector<int> people;
	bitset<10> temp;
	int ans = 999;
	void WouldYouJoinWithUs(bitset<10> party, int YourNum, int LastNum);
	void TimeToCalculate(bitset<10> party, int LastNum);
	bool IsThere3Forest(int LastNum);
};

bool Run::IsThere3Forest(int LastNum)
{
	vector<int> v(LastNum, 0);
	for (int i = 0;i < LastNum;i++)
		v[i] = i;
	for (int i = 0;i < adj_list.size();i++)
	{
		for (int j = 0;j < adj_list[i].size();j++)
		{
			int k = v[i];
			do
			{
				v[adj_list[i][j]] = k;
				k = v[k];
			} while (v[adj_list[i][j]] != k);
		}
	}
	set<int> s(v.begin(), v.end());
	if (s.size() > 2)	return 0;
	else return 1;
}


void Run::WouldYouJoinWithUs(bitset<10> party, int YourNum, int LastNum)
{
	if (YourNum >= LastNum)
		return  TimeToCalculate(party, LastNum);

	for (int i = 0;i < adj_list[YourNum].size();i++)
	{
		//Not Join
		WouldYouJoinWithUs(party, YourNum + 1, LastNum);
		//Join
		party[YourNum] = true;
		WouldYouJoinWithUs(party, YourNum + 1, LastNum);
	}

}

void Run::TimeToCalculate(bitset<10> party, int LastNum)
{
	int YaDang = 0, YeDang = 0, Diff = 0;
	bool Yaflag = false, Yeflag = false;
	for (int i = 0;i < LastNum;i++)
	{
		if (party[i])
		{
			int j = 0;
			while (j < adj_list[i].size())
			{
				if (party[adj_list[i][j]])
					break;
				j++;
			}
			if (j < adj_list[i].size())
				YaDang += people[i];
			else
				YaDang = -1;
		}
		else
		{
			int j = 0;
			while (j < adj_list[i].size())
			{
				if (!party[adj_list[i][j]])
					break;
				j++;
			}
			if (j < adj_list[i].size())
				YeDang += people[i];
			else
				YeDang = -1;
		}
	}
	if ((((party.count() != 1) && (YaDang == -1))) || (((LastNum - party.count()) != 1) && (YeDang == -1)))
		Diff = 9999;
	else if ((Diff = YeDang - YaDang) < 0)
		Diff = -1 * Diff;
	if (Diff < ans) {
		temp = party;
		ans = Diff;
	}
}

int main(int argc, char** argv)
{
	int vertices;
	freopen("input.txt", "r", stdin);
	scanf("%d", &vertices);

	vector<vector<int>> adj_list;
	vector<int> people(vertices, 0);

	for (int i = 0;i < vertices;i++)
		scanf("%d", &people[i]);
	for (int i = 0;i < vertices;i++)
	{
		int edge;
		scanf("%d", &edge);
		vector<int> list(edge, 0);
		for (int j = 0;j < edge;j++) {
			int temp;
			scanf("%d", &temp);
			list[j] = temp - 1;
		}
		adj_list.push_back(list);
	}
	Run obj;
	obj.adj_list = adj_list;
	obj.people = people;
	bitset<10> temp_bs;temp_bs[0] = true;
	if(obj.IsThere3Forest(vertices))
		obj.WouldYouJoinWithUs(temp_bs, 1, vertices);
	if (obj.ans == 999)	printf("%d", -1);
	else printf("%d\n", obj.ans);
	return 0;
}