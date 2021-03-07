//https://programmers.co.kr/learn/courses/30/lessons/42627
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> ii;//request time, operating time

struct comppq {
	bool operator()(ii a, ii b) {
		return a.second > b.second;
	}
};

bool comp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	sort(jobs.begin(), jobs.end(), comp);
	priority_queue<ii, vector<ii>, comppq> pq;
	vector<vector<int>>::iterator iter = jobs.begin();
	int i = 0;
	for (int cnt = 0;cnt < jobs.size();) {
		while (iter != jobs.end()) {
			if ((*iter)[0] <= i)
				pq.push(ii((*iter)[0], (*iter)[1]));
			else
				break;
			iter++;
		}
        if(!pq.empty()){
            answer += ((i - pq.top().first)+pq.top().second);
		    i += pq.top().second;
		    pq.pop();
            cnt++;
        }
        else
            i++;
	}
	return (int)(answer / jobs.size());
}