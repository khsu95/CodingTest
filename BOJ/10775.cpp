/*
 * 10775.cpp
 *
 *  Created on: 2022. 03. 6.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/10775
				Canadian Computing Competition & Olympiad 2015 > Senior 3
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <bitset>

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

class node
{
public:
	node(int x, int y, int z)
	{
		left = x; self = y; right = z;
	};
	int left, self, right;
};

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	int iGate, iPlane;

	cin >> iGate >> iPlane;

	vi mxGate(iPlane + 1, 0);
	vector<node> sltGt(iGate + 2, node(-1, 0, 0));
	
	for (int i = 1; i < mxGate.size(); i++)
	{
		cin >> mxGate[i];
	}

	for (int i = 1; i < sltGt.size(); i++)
	{
		sltGt[i] = node(i - 1, 0, i + 1);
	}

	int ans;

	for (ans=1; (ans < mxGate.size()); ans++)
	{
		int nGate = mxGate[ans];
		
		int flag = false;
		
		while (nGate > 0)
		{
			if (!(sltGt[nGate].self))
			{

				sltGt[nGate].self = true;
				sltGt[nGate].left = (sltGt[nGate - 1].self) ? sltGt[nGate - 1].left : nGate - 1;
				sltGt[nGate].right = (sltGt[nGate + 1].self) ? sltGt[nGate + 1].right : nGate + 1;
				
				sltGt[nGate - 1].right = sltGt[nGate].right;
				sltGt[nGate + 1].left = sltGt[nGate].left;

				nGate = -1;
				flag = true;
			}
			else
			{
				nGate = sltGt[nGate].left;
			}
		}

		if (!flag)	break;
	}

	ans -= 1;

	cout << ans;

	return 0;
}