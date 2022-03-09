/*
 * 9177.cpp
 *
 *  Created on: 2022. 03. 7.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/10282
				ICPC > Pacific Northwest Regional > 2004 B
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

class stt
{
public:
	string str;
	int aIdx, bIdx;
	stt(string str, int a, int b) { this->str = str; aIdx = a; bIdx = b; };
	bool operator< (const stt& other) const
	{
		if (str.size() != other.str.size())	return str.size() > other.str.size();
		if (str.compare(other.str))	return str.compare(other.str) < 0 ? 0 : 1;
		if (aIdx != other.bIdx)	return aIdx > other.aIdx;
		return bIdx > other.bIdx;
	}
};

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	int nTc;
	cin >> nTc;
	for (int i = 0; i < nTc; i++)
	{
		string strA, strB, strD;
		cin >> strA >> strB >> strD;

		set<stt> s;
		priority_queue<stt> pq;
		pq.push(stt(strA.substr(0, 1), 1, 0));
		pq.push(stt(strB.substr(0, 1), 0, 1));

		while (!pq.empty())
		{
			stt elem = pq.top(); pq.pop();
			if (elem.str == strD)
			{
				cout << "Data set " << i + 1 << ": yes\n";
				pq.push(stt("fck", 0, 0));
				break;
			}

			if (elem.aIdx < strA.size())
			{
				stt nStt = elem;
				nStt.str = elem.str + strA[elem.aIdx];
				nStt.aIdx = elem.aIdx + 1;
				
				if (nStt.str == strD.substr(0, nStt.aIdx + nStt.bIdx))
				{
					if ((s.insert(nStt)).second)
					{
						pq.push(nStt);
					}
				}
			}

			if (elem.bIdx < strB.size())
			{
				stt nStt = elem;
				nStt.str = elem.str + strB[elem.bIdx];
				nStt.bIdx = elem.bIdx + 1;

				if (nStt.str == strD.substr(0, nStt.aIdx + nStt.bIdx))
				{
					if ((s.insert(nStt)).second)
					{
						pq.push(nStt);
					}
				}
			}
		}
		if (pq.empty())
		{
			cout << "Data set " << i + 1 << ": no\n";
		}
	}
	return 0;
}