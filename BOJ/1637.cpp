
/*
 * 1637.cpp
 *
 *  Created on: 2022. 12. 19.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/1637
				ICPC >> SEEERC 2007 E
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int how_many(unsigned int mid, vector<vector<unsigned int>> ranges)
{
	if (!mid)	return 0;

	unsigned int ret = 0;

	for (int i = 0; i < ranges.size(); i++)
	{
		unsigned int num = min(mid, ranges[i][1]);

		if (num >= ranges[i][0])
		{
			ret += ((num - ranges[i][0]) / ranges[i][2]) + 1;
		}
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	unsigned int num = 0, ans = 0, cnt = 0;
	cin >> num;
	vector<vector<unsigned int>> ranges(num, vector<unsigned int>(3, 0));
	for (int i = 0; i < num; i++)
	{
		cin >> ranges[i][0] >> ranges[i][1] >> ranges[i][2];
	}

	unsigned int left = 1, right = 2147483647 + 1, mid;
	while (left < right)
	{
		mid = (left + right) >> 1;

		if (how_many(mid, ranges) % 2)
		{
			right = mid;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (ans)
	{
		cnt = how_many(ans, ranges) - how_many(ans - 1, ranges);
		cout << ans << " " << cnt;
	}

	else
		cout << "NOTHING";
}
