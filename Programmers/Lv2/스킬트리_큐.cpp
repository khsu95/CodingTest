//https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;
typedef pair<int, int> ii;//value-index

int solution(string skill, vector<string> skill_trees) {
	priority_queue<ii, vector<ii>, greater<ii>> prio;
	bool flag = 1;
	int answer = 0;
	for (int i = 0;i < skill_trees.size();i++) {
		for (int j = 0;j < skill.size();j++) {
			int k = skill_trees[i].find(skill[j]);
			if (k == -1)	k += 100;
			prio.push(ii(k,j));
		}
		for (int j = 0;j < skill.size();j++) {
			if (prio.top().second != j) {
				flag = 0;
				break;
			}
			prio.pop();
		}
		if (flag)	answer++;
		flag = 1;
		while (!prio.empty())	prio.pop();
	}
	return answer;
}