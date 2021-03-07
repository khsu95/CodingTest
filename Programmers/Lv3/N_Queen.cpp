//https://programmers.co.kr/learn/courses/30/lessons/12952
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<vector<bool>> table);

bool bfs(vector<vector<bool>> table, int depth, int right, int n, int *count)
{
	if (depth == n-1)
	{
		(*count)++;
		return true;
	}
	for (int i = 0;i < n;i++)
	{
		table[depth][i] = true; table[i][right] = true;
		if (((right - depth + i) >= 0) && ((right - depth + i) < n))  table[i][right - depth + i] = true;
		if (((right + depth - i) < n) && ((right + depth - i) >= 0))  table[i][right + depth - i] = true;
	}
	for (int i = 0;i < n;i++)
	{
		if (table[depth+1][i]) continue;
		bfs(table, depth + 1, i, n, count);
	}
	return false;
}


int solution(int n) {
	int answer = 0;
	vector<vector<bool>> table(n, vector<bool>(n, 0));
    for(int i=0;i<n;i++)    
        bfs(table, 0, i, n, &answer);
	return answer;
}