//https://www.acmicpc.net/problem/17779
//2021.08.19
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int N,temp,super_sum,ans;
	N = temp = super_sum=0;
	ans = 9999;

	cin >> N;
	vector<vector<int>> table(N, vector<int>(N, 0));
	for (int i = 0;i < N;i++)
	{
		int sum = 0;
		for (int j = 0;j < N;j++)
		{
			cin >> temp;
			sum += temp;
			table[i][j] = sum;
		}
		super_sum += sum;
	}

	for (int col = 0;col < N;col++)
	{
		for (int row = 0;row < N;row++)
		{
			for (int d1 = 1;(d1 + col < N)&&(row-d1>=0);d1++)
			{

				for (int d2 = 1;(d2 + row < N)&&(col+d1+d2<N);d2++)
				{
					int zone1, zone2, zone3, zone4;
					int cnt1, cnt2, cnt3, cnt4;
					zone1 = zone2 = zone3 = zone4 = 0;
					cnt1 = cnt2 = cnt3 = cnt4 = 1;

					for (int ccol = 0;ccol < N;ccol++)
					{
						if (ccol < col)
						{
							zone1 += table[ccol][row];
							zone2 += (table[ccol][N - 1] - table[ccol][row]);
						}

						if (ccol >= col && ccol < col + d1)
						{
							zone1+=table[ccol][row - cnt1];
							cnt1++;
						}

						if (ccol >= col && ccol <= col + d2)
						{
							if (row + cnt2 - 1 <= N - 1)
								zone2 += (table[ccol][N - 1] - table[ccol][row + cnt2 - 1]);
							cnt2++;
						}

						if (ccol >= col + d1 && ccol <= col + d1 + d2)
						{
							if (row - d1 - 1 + cnt3 - 1 >= 0)
								zone3 += table[ccol][row - d1 - 1 + cnt3 - 1];
							cnt3++;
						}

						if (ccol > col + d2 && ccol <= col + d1 + d2)
						{
							zone4 += (table[ccol][N - 1] - table[ccol][row + d2 - cnt4]);
							cnt4++;
						}

						if (ccol > col + d1 + d2)
						{
							zone3 += table[ccol][row - d1 + d2 - 1];
							zone4 += (table[ccol][N - 1] - table[ccol][row - d1 + d2 - 1]);
						}
					}

					int zone5 = super_sum - (zone1 + zone2 + zone3 + zone4);

					int _max = max({ zone1,zone2,zone3,zone4,zone5 });
					int _min = min({ zone1,zone2,zone3,zone4,zone5 });
					ans = (_max - _min) < ans ? (_max - _min) : ans;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
