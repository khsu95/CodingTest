//https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	bitset<200> visited;
	queue<int> bfs;
	visited.reset();
	for (int i = 0;i < n;i++) {
		if (visited[i])   continue;
		bfs.push(i);
		while (!bfs.empty()) {
			int token = bfs.front();  bfs.pop();
			visited[token] = true;
			for (int j = 0;j < n;j++) {
				if (!computers[token][j])    continue;
                if(visited[j]) continue;
				bfs.push(j);
			}
		}
		answer++;
	}
	return answer;
}