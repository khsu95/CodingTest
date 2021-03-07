//https://programmers.co.kr/learn/courses/30/lessons/42884
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
	return a[1]<b[1];
};


int solution(vector<vector<int>> routes) {
	int answer = 0;
	vector < vector<int>> pq;  pq = routes;

	//order by distance
	sort(pq.begin(), pq.end(), comp);

	while (!pq.empty()) {
		vector<vector<int>>::iterator iter2big = pq.begin();
        cout<<(*iter2big)[0]<<","<<(*iter2big)[1]<<" ";

		//Install Camera
		int camera;
		if (1) {
			answer++;
			int left = (*iter2big)[0], right = (*iter2big)[1];
			int leftcnt = 0, rightcnt = 0;
			for (int k = 0;k < pq.size(); k++) {
				if ((pq[k][0] <= left)
					&& (pq[k][1] >= left))    leftcnt++;

				if ((pq[k][1] >= right)
					&& (pq[k][0] <= right)) rightcnt++;
			}
			if (leftcnt > rightcnt) camera = left;
			else camera = right;
            //cout<<left<<"-"<<leftcnt<<" "<<right<<"-"<<rightcnt<<endl;
		}

		//Delete car
		vector<vector<int>>::iterator iter2small = pq.begin();
		do {
			if (((*iter2small)[1] >= camera)
				&& ((*iter2small)[0] <= camera)) pq.erase(iter2small);
			else iter2small++;
		} while (iter2small != pq.end());

	}
	return answer;
}