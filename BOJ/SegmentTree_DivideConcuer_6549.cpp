/*
 * 6549.cpp
 *
 *  Created on: 2022. 02. 12.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/6549
				University of Ulm Local Contest 2003 H
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<bool>> vvb;
typedef vector<int> vi;

long long ans;

class SegmentTree
{
	vi sTree, arr;
	int arrSize;
	/* The Number gained from Multiplying by 2 points Child */
	int left(int p) { return p << 1; };
	int right(int p) { return (p << 1) + 1; };

	void build(int p, int l, int r)
	{
		if (l == r)
		{
			sTree[p] = l;
		}
		else
		{
			/* To Build Tree, A Segment Divied to 2 Segments(Left, Right) */
			build(left(p), l, (l + r) >> 1);
			build(right(p), ((l + r) >> 1) + 1, r);
			int lChild = sTree[(left(p))], rChild = sTree[right(p)];
			sTree[p] = (arr[lChild] <= arr[rChild]) ? lChild : rChild;
		}
	};

	int query(int p, int l, int r, int i, int j)
	{
		/* Segment(l-r) is Out of Boundary(i-j)*/
		if (i > r || j < l)	return -1;
		/* Segment of Interest*/
		if (l >= i && r <= j) return sTree[p];

		/* Segment includs much more information User didn't require*/
		int lChild = query(left(p), l, (l + r) >> 1, i, j);
		int rChild = query(right(p), ((l + r) >> 1) + 1, r, i, j);

		
		if (lChild == -1)	return rChild;
		if (rChild == -1)	return lChild;

		/* Return Index pointing Min Value*/
		return (arr[lChild] < arr[rChild]) ? lChild : rChild;
	}

public:
	SegmentTree(const vi& _arr)
	{
		arr = _arr; arrSize = (int)arr.size();
		/* Size Shuld be Enough to Save Segments */
		sTree.assign(4 * arrSize, 0);
		build(1, 0, arrSize - 1);
	}
	/* Overloading was Used. This makes user call this function more Easily*/
	int query(int i, int j)
	{
		return query(1, 0, arrSize - 1, i, j);
	}
	long long my_func(int l, int r)
	{
		if (l > r)	return 0;
		if (l == r)	return (long long)arr[l];
		int minIdx = query(l, r);
		long long expArea = (long long)arr[minIdx] * (long long)(r - l + 1);
		long long leftArea = my_func(l,minIdx - 1);
		long long rightArea = my_func(minIdx + 1, r);
		return (expArea < leftArea) ? ((leftArea < rightArea) ? rightArea : leftArea) : ((expArea < rightArea) ? rightArea : expArea);
	}
};

int main()
{
	freopen("input.txt","r", stdin);

	int punc = 1;

	while (1)
	{
		cin >> punc;
		if (!punc)	break;
		vi arr(punc, 0);
		ans = 0;
		for (int i = 0; i < punc; i++)
		{
			cin >> arr[i];
		}
		SegmentTree st(arr);

		ans = st.my_func(0, punc - 1);

		cout << ans << "\n";
	}
}