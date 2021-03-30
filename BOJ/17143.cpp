//https://www.acmicpc.net/problem/14888
//2021.03.30
/*
////Counter Case
4 2 2
2 2 3 1 1
4 2 3 1 2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
typedef struct
{
	int x = 0, y = 0, velo = 0, dir = 0, size = 0;
} Shark;

bool comp(Shark a, Shark b)
{
	if (a.x != b.x)
		return a.x < b.x;
	else if (a.y != b.y)
		return a.y < b.y;
	return a.size < b.size;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int col, row, num, answer = 0;
	cin >> col >> row >> num;
	vector<Shark> v(num);
	for (int i = 0;i < v.size();i++)
	{
		cin >> v[i].x >> v[i].y >> v[i].velo >> v[i].dir >> v[i].size;
	}

	for (int i = 1;i <= row;i++)
	{
		//Fishing
		sort(v.begin(), v.end(), comp);
		vector<Shark>::iterator iter = v.begin(), n_iter;
		while (iter != v.end())
		{
			if ((*iter).y == i)
			{
				answer += (*iter).size;
				v.erase(iter);
				break;
			}
			else
			{
				iter++;
			}
		}
		//Shift
		for (int j = 0;j < v.size();j++)
		{
			int rem = v[j].velo, loc = v[j].x, boundary = col;
			if (v[j].dir >= 3)
			{
				loc = v[j].y;
				boundary = row;
			}

			while (rem >= (row - 1) * 2)   rem -= (row - 1) * 2;
			while (rem > 0)
			{
				//Increased Dir
				if ((v[j].dir==2)|| (v[j].dir == 3))
				{
					if (rem <= (boundary - loc))
					{
						loc += rem;
						rem -= rem;
					}
					else
					{
						rem -= (boundary - loc);
						loc += (boundary - loc);
						v[j].dir = (v[j].dir == 2) ? 1 : 4;
					}
				}
				else
				{
					if (rem <= (loc - 1))
					{
						loc -= rem;
						rem -= rem;
					}
					else
					{
						rem -= (loc - 1);
						loc -= (loc - 1);
						v[j].dir = (v[j].dir == 1) ? 2 : 3;
					}
				}
			}
			if (v[j].dir >= 3)	v[j].y = loc;
			else v[j].x = loc;
		}
		//Eat
		if (v.size() < 2)	continue;
		sort(v.begin(), v.end(), comp);
		iter = v.begin(), n_iter = v.begin() + 1;
		while (n_iter != v.end())
		{
			ii a = ii((*iter).x, (*iter).y), b = ii((*n_iter).x, (*n_iter).y);
			if (a == b)
			{
				iter=v.erase(iter);
				n_iter=iter+1;
			}
			else
			{
				iter++;
				n_iter++;
			}
		}
	}
	cout << answer;
	return 0;
}