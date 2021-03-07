//https://programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
typedef pair<string, int> si;

bool comp1(vector<ii> a, vector<ii> b) {
	return a[0].second > b[0].second;
}

bool comp2(ii a, ii b) {
	if (a.second != b.second)  return a.second > b.second;
	else return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<string> gen;
	vector<string> temp = genres;
	sort(temp.begin(), temp.end());
	gen.push_back(temp[0]);
	for (int i = 1;i < temp.size();i++)
		if (temp[i] != temp[i - 1])  gen.push_back(temp[i]);
	vector<vector<ii>> table(gen.size(), vector<ii>(1, ii(-1, -1)));
	for (int i = 0;i < table.size();i++) {
		for (int j = 0;j < genres.size();j++) {
			if (gen[i] == genres[j]) {
				table[i].push_back(ii(j, plays[j]));
				table[i][0].second += plays[j];
			}
		}
	}
	sort(table.begin(), table.end(), comp1);
	for (int i = 0;i < table.size();i++) {
		sort(++table[i].begin(), table[i].end(), comp2);
		for (int j = 1;j < 3;j++) {
            if(!(j<table[i].size()))  break;
			answer.push_back(table[i][j].first);
		}
	}

	return answer;
}