//https://programmers.co.kr/learn/courses/30/lessons/42898
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <iostream>

using namespace std;

int memo[101][101];

int fnd(int m, int n);

int solution(int m, int n, vector<vector<int>> puddles) {

	for (int i = 0;i < 101;i++)
		memset(memo[i], 0, sizeof(&memo[i]));

	int answer = 0;
	for (int i = 0;i < puddles.size();i++)
		memo[puddles[i][0]][puddles[i][1]] = -1;

	fnd(m, n);
	answer = memo[m][n];
	return answer%1000000007;
}

int fnd(int m, int n) {
	if (memo[m][n] == -1)	return 0;//paddles
	if (m == 1 && n == 1)	return 1;    //
	if (m < 1 || n < 1)	return 0;
	if (memo[m][n] > 0) return memo[m][n]%1000000007;
	memo[m][n] = (fnd(m - 1, n) + fnd(m, n - 1))%1000000007;
	return memo[m][n];
}