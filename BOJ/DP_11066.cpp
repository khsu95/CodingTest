/*
 * 6087.cpp
 *
 *  Created on: 2022. 02. 13.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/6087
				USA Computing Olympiad > USACO January 2009 Contest > Silver 3
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;

class my_cls
{
public:
	vi arr;
	vvii memo;
	my_cls(vi &arr, int k) { this->arr = arr; memo.assign(k, vii(k, ii(MAX_INT, MAX_INT))); };
	ii my_func(int l, int r)
	{
		if (l == r)
		{
			return ii(arr[l],0);
		}
		if (memo[l][r].first != MAX_INT)	
			return memo[l][r];

		ii min(MAX_INT, MAX_INT);
		for (int i = l; i < r; i++)
		{
			ii left = my_func(l, i);
			ii right = my_func(i + 1, r);
			ii temp;
			temp.first = left.first + right.first;
			temp.second = temp.first + left.second + right.second;
			min = (temp.second < min.second) ? temp : min;
		}
		return memo[l][r] = min;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;		cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int k; cin >> k;
		vi arr(k, 0);
		for (int j = 0; j < k; j++)	cin >> arr[j];

		my_cls mc(arr, k);
		mc.my_func(0, k-1);
		int ans = mc.memo[0][k-1].second;
		cout << ans << endl;
	}
}