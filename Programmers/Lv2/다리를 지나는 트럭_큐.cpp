//https://programmers.co.kr/learn/courses/30/lessons/42583
#include <string>
#include <vector>
#include<queue>

using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int now = 0;
	queue<int> q;
	for (int i = 0;i < bridge_length;i++) {
		truck_weights.push_back(0);   q.push(0);
	}
	vector<int>::iterator iter = truck_weights.begin();
	do {
		if (now+(*iter)-q.front() <= weight) {
			q.push((*iter));
			now += (*iter);
			iter++;
		}
		else
			q.push(0);
		now -= q.front(); q.pop();
		answer++;
	} while (iter!=truck_weights.end());
	return answer;
}