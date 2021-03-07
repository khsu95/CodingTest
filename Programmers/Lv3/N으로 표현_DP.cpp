//https://programmers.co.kr/learn/courses/30/lessons/42895
#define MAX 99999999
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int solution(int N, int number) {
	vector<int> idx(99999999, 9); //number->chance
	vector<int> iidx; //index -> number
	queue<ii> st;//element waiting process, store number, store chance

	int temp = N;
	for (int i = 1;i <= 8;i++) {
		st.push(ii(i, temp));
		temp = 10 * temp + N;
	}

	while (!st.empty()) {
		ii element = st.front(); st.pop();
		int chance = element.first; int num = element.second;
		if ((num > MAX)||(num<=0))	continue;
		if ((chance >= idx[num]) || (chance > 8)) continue;
		iidx.push_back(num); idx[num] = chance;

		int fight_counter = iidx.size();
		for (int i = 0;i < fight_counter;i++) {
			int new_chc = idx[iidx[i]] + chance; int new_num = iidx[i];
			st.push(ii(new_chc, new_num + num));
			st.push(ii(new_chc, new_num * num));
			if (!(new_num % num) && (new_num / num > 0)) st.push(ii(new_chc, new_num / num));
			if ((new_num - num > 0)) st.push(ii(new_chc, new_num - num));
		}

		st.push(ii(chance + 1, num + N));
		st.push(ii(chance + 1, num * N));
		if (!(num % N) && (num / N > 0)) st.push(ii(chance + 1, num / N));
		if ((num - N > 0)) st.push(ii(chance + 1, num - N));
	}

	if (idx[number] != 9)  return idx[number];
	else return -1;
}