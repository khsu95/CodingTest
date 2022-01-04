//In&Out Strategy
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <bitset>
#include <set>
#include <cstdlib>

using namespace std;

class Run 
{
public:
	vector<vector<int>> adj_list;
	vector<int> people;
	int ans = 999;
	Run(int LastNum) { people.assign(LastNum, 0); }
	bool WouldYouJoinWithUs(bitset<10> party, int YourNum, int LastNum);
	bool TimeToCalculate(bitset<10> party, int LastNum);
	void DFS(bitset<10> party,bitset<10> &visit, int vertice, int LastNum);
};

void Run::DFS(bitset<10> party, bitset<10> &visit, int vertice, int LastNum)
{
	if (visit[vertice])	return;
	visit[vertice] = true;
	for (int i = 0;i < adj_list[vertice].size();i++)
		if (party[adj_list[vertice][i]] == party[vertice])
			DFS(party, visit, adj_list[vertice][i], LastNum);
	return;
}


bool Run::WouldYouJoinWithUs(bitset<10> party, int YourNum, int LastNum)
{
	if (YourNum >= LastNum)
		return  TimeToCalculate(party, LastNum);

	//Not Join
	WouldYouJoinWithUs(party, YourNum + 1, LastNum);
	//Join
	party[YourNum] = true;
	WouldYouJoinWithUs(party, YourNum + 1, LastNum);
	return 0;
}

bool Run::TimeToCalculate(bitset<10> party, int LastNum)
{
	bitset<10> visit;
	DFS(party, visit, 0, LastNum);
	if (visit != party) return 0;

	int i = 0;
	while (++i < LastNum)
		if (!party[i])
			break;
	if (i == LastNum)	return 0;
	visit.reset();
	DFS(party, visit, i, LastNum);
	for (int j = 0;j < LastNum;j++)
		if (party[j] != !visit[j])
			return 0;

	int YaDang = 0, YeDang = 0, Diff = 0;
	for (int i = 0;i < LastNum;i++)
	{
		if (party[i])	YaDang += people[i];
		else YeDang += people[i];
	}
	Diff = abs(YaDang - YeDang);
	if (Diff < ans)	ans = Diff;
	return 1;
}

int main(int argc, char** argv)
{
	int vertices;
	freopen("input.txt", "r", stdin);
	scanf("%d", &vertices);
	Run obj(vertices);

	for (int i = 0;i < vertices;i++)
		scanf("%d", &obj.people[i]);
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
		obj.adj_list.push_back(list);
	}

	bitset<10> temp_bs;
	temp_bs[0] = true;
	obj.WouldYouJoinWithUs(temp_bs, 1, vertices);
	if (obj.ans == 999)	
		printf("%d", -1);
	else 
		printf("%d", obj.ans);
	return 0;
}
