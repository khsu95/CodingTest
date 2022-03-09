/*
 * 2887.cpp
 *
 *  Created on: 2022. 03. 10.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/2887
				Croatian Open Competition in Informatics > COCI 2009/2010 > Contest#7 4
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
#include <algorithm>
#include <list>
#include <map>

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
	vector<int> rank;
	my_set(int num)
	{
		setA.assign(num + 1, 0);
		rank.assign(num + 1, 0);
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
	int a, b, dis;
	Edge(int a, int b, int dis) { this->a = a; this->b = b; this->dis = dis; };
	bool operator< (const Edge& other) const { return this->dis < other.dis; };
};

class Node
{
public:
	int x, y, z, id;
	Node(int x, int y, int z, int id) { this->x = x; this->y = y; this->z = z; this->id = id; };
	int operator- (const Node& other) { return min({ abs(this->x - other.x), abs(this->y - other.y), abs(this->z - other.z) }); };
};

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	int nNode;
	cin >> nNode;
	vector<Node> nodesX(nNode, Node(0, 0, 0, 0));
	vector<Node> nodesY(nNode, Node(0, 0, 0, 0));
	vector<Node> nodesZ(nNode, Node(0, 0, 0, 0));

	for (int i = 0; i < nNode; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		nodesX[i] = (Node(x, y, z, i));
		nodesY[i] = (Node(x, y, z, i));
		nodesZ[i] = (Node(x, y, z, i));
	}

	sort(nodesX.begin(), nodesX.end(), [](const Node& a, const Node& b) -> bool {return a.x > b.x; });
	sort(nodesY.begin(), nodesY.end(), [](const Node& a, const Node& b) -> bool {return a.y > b.y; });
	sort(nodesZ.begin(), nodesZ.end(), [](const Node& a, const Node& b) -> bool {return a.z > b.z; });

	list<Edge> ls;

	map<ii, int> m;
	for (int i = 0; i < nodesX.size() - 1; i++)
	{
		int a = nodesX[i].id, b = nodesX[i + 1].id;
		m.insert(iii(ii(a > b ? a : b, a <= b ? a : b), nodesX[i] - nodesX[i + 1]));
		a = nodesY[i].id; b = nodesY[i + 1].id;
		m.insert(iii(ii(a > b ? a : b, a <= b ? a : b), nodesY[i] - nodesY[i + 1]));
		a = nodesZ[i].id; b = nodesZ[i + 1].id;
		m.insert(iii(ii(a > b ? a : b, a <= b ? a : b), nodesZ[i] - nodesZ[i + 1]));
	}
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		ls.push_back(Edge(iter->first.first, iter->first.second, iter->second));
	}

	my_set s(nNode);

	ls.sort();

	int ans = 0;
	while (!ls.empty())
	{
		Edge edge = ls.front(); ls.pop_front();
		if (s.whoParent(edge.a) != s.whoParent(edge.b))
		{
			s.union_set(edge.a, edge.b);
			ans += edge.dis;
		}
	}

	cout  << ans;

	return 0;
}