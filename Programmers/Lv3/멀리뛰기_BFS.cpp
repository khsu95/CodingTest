//https://programmers.co.kr/learn/courses/30/lessons/12914
#include <string>
#include <vector>

using namespace std;

class sol {
public:
	sol(int n) { memo.assign(n + 1, 0); }
	vector<int> memo;
	long long answer = 0;
	long long bfs(int n);
};

long long sol::bfs(int n) {
	if (n < 0)   return 0;
	else if (memo[n] > 0)   return memo[n]%1234567;
	else if (n == 0)   return memo[n]=1;
	return memo[n] = (bfs(n - 1) + bfs(n - 2))%1234567;
}

long long solution(int n) {
	long long answer = 0;
	sol a(n);
	a.bfs(n);
	return a.memo[n];
}