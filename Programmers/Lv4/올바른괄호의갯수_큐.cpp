//https://programmers.co.kr/learn/courses/30/lessons/12929
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int solution(int n) {
	int answer = 0;
	queue<ii> q;//(#of(,#ofTotal))
	q.push(ii(0, 0));
	while (!q.empty()) {
		ii elem = q.front();q.pop();
		if (elem.second == 2 * n) {
			if (elem.first == 0)
				answer++;
		}
		else {
			if (elem.first)
				q.push(ii(elem.first - 1, elem.second + 1));//Case of )
			q.push(ii(elem.first + 1, elem.second + 1));//Case of (
		}
	}
	return answer;
}