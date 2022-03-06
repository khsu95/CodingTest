/*
 * 10775.cpp
 *
 *  Created on: 2022. 03. 3.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/10775
				Canadian Computing Competition & Olympiad 2015 > Senior 3
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

class my_set
{
public:
	vector<int> setA;
	my_set(int num)
	{
		setA.assign(num + 2, 0);
		for (int i = 0; i < setA.size(); i++)
		{
			setA[i] = i;
		}
	};
	int whoParent(int child)
	{
		if (setA[child] == child)
		{
			return child;
		}
		else
		{
			return setA[child] = whoParent(setA[child]);
		}
	};
	void union_set(int a, int b)
	{
		setA[whoParent(a)] = setA[whoParent(b)];
	};
};

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	int iGate, iPlane;

	cin >> iGate >> iPlane;

	vi mxGate(iPlane + 1, 0);
	vector<ii> bndry(iGate + 2, ii(-1,-1));
	vector<int> sltGt(iGate + 2, 0);
	my_set s(iGate);
	
	for (int i = 1; i < mxGate.size(); i++)
	{
		cin >> mxGate[i];
	}

	for (int i = 1; i < sltGt.size(); i++)
	{
		bndry[i] = ii(i, i);
	}

	int ans;

	for (ans=1; (ans < mxGate.size()); ans++)
	{
		int nGate = mxGate[ans];

		int flag = false;
		
		while (nGate > 0)
		{
			int prGate = s.whoParent(nGate);
			int prLGate = s.whoParent(nGate - 1);
			int prRGate = s.whoParent(nGate + 1);

			if (!(sltGt[nGate]))
			{
				sltGt[nGate] = nGate;

				int left  = bndry[prLGate].first;
				int right = bndry[prRGate].second;

				if(sltGt[nGate-1])
					s.union_set(nGate - 1, nGate);
				if (sltGt[nGate + 1])
					s.union_set(nGate + 1, nGate);

				int temp = s.whoParent(nGate);

				bndry[prGate] = ii(left, right);

				flag = true;
				break;
			}
			else
			{
				nGate = bndry[s.whoParent(nGate)].first;
			}
		}

		if (!flag)	break;
	}

	ans -= 1;

	cout << ans;

	return 0;
}