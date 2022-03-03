/*
 * 9370.cpp
 *
 *  Created on: 2022. 02. 21.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/9370
				ICPC > Europe > Benelux Algortihm Programming Contest 2013 > D
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#if 1
/* down, up, right, left*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#endif

void dijkstra(int strt, vi& dDest, vvii& t)
{
	priority_queue<ii> pq;
	pq.push(ii(0, strt));
	dDest[strt] = 0;
	
	while (!pq.empty())
	{
		ii elem = pq.top(); pq.pop();
		if (elem.first > dDest[elem.second])
			continue;
		for (int i = 0; i < t[elem.second].size(); i++)
		{
			int nNode = t[elem.second][i].first;
			int nCost = elem.first + t[elem.second][i].second;
			if (nCost < dDest[nNode])
			{
				dDest[nNode] = nCost;
				pq.push(ii(nCost, nNode));
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int nNode, nEdge, nDest, pStart, pMmdt1, pMmdt2, dMmdt;
		cin >> nNode >> nEdge >> nDest >> pStart >> pMmdt1 >> pMmdt2;
		vvii t(nNode + 1);
		vi dest(nDest);
		for (int j = 0; j < nEdge; j++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			if (((a == pMmdt1) && (b == pMmdt2)) || ((a == pMmdt2) && (b == pMmdt1)))
			{
				dMmdt = d;
				continue;
			}
			t[a].push_back(ii(b, d));
			t[b].push_back(ii(a, d));
		}
		for (int j = 0; j < nDest; j++)
		{
			cin >> dest[j];
		}


		vvi dDest(2, vi(nNode + 1, MAX_INT>>1));
		dijkstra(pMmdt1, dDest[0], t);
		dijkstra(pMmdt2, dDest[1], t);

		t[pMmdt1].push_back(ii(pMmdt2, dMmdt));
		t[pMmdt2].push_back(ii(pMmdt1, dMmdt));
		
		vi cDest(nNode + 1, MAX_INT >> 1);
		dijkstra(pStart, cDest, t);

		set<int> s;
		for (int j = 0; j < dest.size(); j++)
		{
			int nAns = dDest[0][pStart] + dDest[1][dest[j]] + dMmdt;
			if (cDest[dest[j]] == nAns)
				s.insert(dest[j]);
		}
		for (int j = 0; j < dest.size(); j++)
		{
			int nAns = dDest[1][pStart] + dDest[0][dest[j]] + dMmdt;
			if (cDest[dest[j]] == nAns)
				s.insert(dest[j]);
		}

		for (set<int>::iterator iter = s.begin();iter!=s.end();iter++)
		{
			cout << *(iter)<<" ";
		}
		cout << endl;
	}
	return 0;
}