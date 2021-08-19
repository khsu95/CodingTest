//https://www.acmicpc.net/problem/17779
//2021.08.19
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
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
			for (int d1 = 1;d1 + col < N;d1++)
			{
				if (row - d1 < 0)	continue;

				for (int d2 = 1;d2 + row < N;d2++)
				{
					if (col + d1 + d2 >= N)	continue;

					int min = 9999, max = 0;
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
						if (ccol == col + d1)
						{
							min = (zone1 < min) ? zone1 : min;
							max = (zone1 > max) ? zone1 : max;
						}

						if (ccol >= col && ccol <= col + d2)
						{
							zone2 += (table[ccol][N - 1] - table[ccol][row + cnt2-1]);
							cnt2++;
						}
						if (ccol == col + d2)
						{
							min = (zone2 < min) ? zone2 : min;
							max = (zone2 > max) ? zone2 : max;
							if (max - min > ans)	break;
						}




						if (ccol >= col + d1 && ccol <= col + d1 + d2)
						{
							if (row - d1 - 1 + cnt3 - 1 < 0)	continue;
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
					min = zone3 < min ? zone3 : min;
					max = zone3 > max ? zone3 : max;
					min = zone4 < min ? zone4 : min;
					max = zone4 > max ? zone4 : max;
					if (max - min > ans)	break;

					int zone5 = super_sum - (zone1 + zone2 + zone3 + zone4);
					min = zone5 < min ? zone5 : min;
					max = zone5 > max ? zone5 : max;

					ans = (max - min) < ans ? (max - min) : ans;

					//cout << "at (" << col << ", " << row << ")" << " dis: "<<d1<<", "<<d2<<endl;
					//cout << "answer is..." << ans << endl;
					//cout << max << ", " << min << endl;
					//cout << zone1 << ", " << zone2 << ", " << zone3 << ", " << zone4 <<","<< zone5 << endl;
				}
			}
		}
	}
	cout << ans;
	return 0;
}