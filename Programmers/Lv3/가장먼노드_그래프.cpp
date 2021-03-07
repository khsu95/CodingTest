//https://programmers.co.kr/learn/courses/30/lessons/49189
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int max = 0;
	vector<vector<int>> adj;

	vector<int> v;v.push_back(10000);

	for (int i = 0;i <= n;i++)
		adj.push_back(v);

	for (int i = 0;i < edge.size();i++) {
		adj[edge[i][0]].push_back(edge[i][1]);
		adj[edge[i][1]].push_back(edge[i][0]);
	}

	queue<ii> que;  que.push(ii(1, 0));
    adj[1][0]=0;
	while (!que.empty()) {
		ii node = que.front();que.pop();
		int v = node.first, dista = node.second;
		for (int i = 1;i < adj[v].size();i++) {
			int nv = adj[v][i];
			if (adj[nv][0] > (dista+1)) {
				adj[nv][0] = dista + 1;
				if (adj[nv][0] > max)  max = adj[nv][0];
				que.push(ii(nv, dista + 1));
			}
		}
	}

	for (int i = 1;i <= n;i++)
		if (max == adj[i][0])  answer++;
	return answer;
}