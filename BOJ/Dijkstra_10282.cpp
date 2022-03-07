/*
 * 10282.cpp
 *
 *  Created on: 2022. 03. 7.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/10282
				ICPC > Northwestern European Regional Contest > BAPC 2014 Preliminaries B
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	
	int nTcs, nCom, nDep, pInf;
	
	cin >> nTcs;

	for (int i = 0; i < nTcs; i++)
	{
		cin >> nCom >> nDep >> pInf;

		vvii adjLst(nCom + 1);

		for (int j = 0; j < nDep; j++)
		{
			int edgeA, edgeB, dst;
			cin >> edgeA >> edgeB >> dst;

			adjLst[edgeB].push_back(ii(edgeA, dst));
		}

		vi dijDst(nCom + 1, MAX_INT);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push(ii(0, pInf));	dijDst[pInf] = 0;

		while (!pq.empty())
		{
			ii elem = pq.top(); pq.pop();

			if (elem.first > dijDst[elem.second])	continue;

			for (int k = 0; k < adjLst[elem.second].size(); k++)
			{
				int nCost = elem.first + adjLst[elem.second][k].second;
				int nEdge = adjLst[elem.second][k].first;

				if (nCost < dijDst[nEdge])
				{
					pq.push(ii(nCost, nEdge));
					dijDst[nEdge] = nCost;
				}
			}
		}

		priority_queue<int, vector<int>, greater<int>> ansPq(dijDst.begin(), dijDst.end());
		int ansNum = 0, ansTm;
		while (!ansPq.empty())
		{
			if (ansPq.top() == MAX_INT)
				break;

			ansNum += 1;
			ansTm = ansPq.top();	ansPq.pop();
		}
		cout << ansNum << " " << ansTm << "\n";
	}
	return 0;
}