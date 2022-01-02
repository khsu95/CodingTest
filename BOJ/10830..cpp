//https://www.acmicpc.net/problem/10830
//
//2022.01.02
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

vvi matMul(vvi a, vvi b)
{
	vvi ans(a.size(), vector<int>(b[0].size(), 0));
	int i, j, k;
	for (i = 0; i < a.size(); i++)
	{
		for (j = 0; j < a[0].size(); j++)
		{
			for (ans[i][j] = k = 0; k < a.size(); k++)
			{
				ans[i][j] += (a[i][k] * b[k][j] % 1000);
			}
			ans[i][j] %= 1000;
			//(A+B)%C = ((A%C)+(B%C))%C
		}
	}
	return ans;
}

vvi matPow(vvi base, long long p)
{
	vvi ans(base.size(), vector<int>(base[0].size(), 0));
	int i, j;

	//Identity Matrix
	for (i = 0; i < base.size(); i++)
	{
		for (j = 0; j < base[0].size(); j++)
		{
			ans[i][j] = (i == j);
		}
	}

	while (p)
	{
		//Odd A^n = A^(n-1)*A
		if (p & 1)
		{
			ans = matMul(ans, base);
			p -= 1;
		}
		//Even A^n = (A^(n/2))^2
		else
		{
			base = matMul(base, base);
			p >>= 1;
		}

	}
	return ans;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int row;
	long long p;
	cin >> row >> p;
	vector<vector<int>> mat(row, vector<int>(row, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> mat[i][j];
		}
	}

	mat = matPow(mat, p);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << mat[i][j];
			if (j + 1 < row)    cout << " ";
		}
		cout << endl;
	}
}
