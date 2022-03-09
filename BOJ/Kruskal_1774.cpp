/*
 * 1774.cpp
 *
 *  Created on: 2022. 03. 9.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/1774
                USA Computing Olympiad > USACO December 2007 Contest > Silver 2
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

#if 1
/* down, up, right, left*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#endif

class my_set
{
public:
	vector<int> setA;
	my_set(int num)
	{
		setA.assign(num + 1, 0);
		for (int i = 0; i < setA.size(); i++)
			setA[i] = i;
	};
	int whoParent(int child)
	{
		if (setA[child] == child)
			return child;
		else
			return setA[child] = whoParent(setA[child]);
	};
	void union_set(int a, int b)
	{
		setA[whoParent(a)] = setA[whoParent(b)];
	};
};

class Edge
{
public:
	int a, b;
	double dis;
	Edge(int a, int b, double dis) { this->a = a; this->b = b; this->dis = dis; };
	bool operator< (const Edge& other) const { return this->dis > other.dis; };
};

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	int nNode, nEdge;
	cin >> nNode >> nEdge;
	vii nodes(nNode + 1, ii(0, 0));
	for (int i = 1; i <= nNode; i++)
	{
		int x, y;
		cin >> x >> y;
		nodes[i] = ii(x, y);
	}

	my_set s(nNode);
	for (int i = 0; i < nEdge; i++)
	{
		int a, b;
		cin >> a >> b;
		s.union_set(a, b);
	}

	priority_queue<Edge> pq;
	for (int i = 1; i < nodes.size(); i++)
		for (int j = i + 1; j < nodes.size(); j++)
			pq.push(Edge(i, j, sqrt((ll(nodes[i].first - nodes[j].first) * ll(nodes[i].first - nodes[j].first))
								+    ll(nodes[i].second - nodes[j].second) * ll(nodes[i].second - nodes[j].second))));
	
	double ans = 0;
	while (!pq.empty())
	{
		Edge edge = pq.top(); pq.pop();
		if (s.whoParent(edge.a) != s.whoParent(edge.b))
		{
			s.union_set(edge.a, edge.b);
			ans += edge.dis;
		}
	}

	ans = (round(ans * 100)) / 100;
	cout.precision(2);
	cout << fixed << ans;

	return 0;
}