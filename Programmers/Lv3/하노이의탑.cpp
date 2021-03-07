//https://programmers.co.kr/learn/courses/30/lessons/12946
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class sol {
public:
	vector<vector<int>> answer;
	void hannoi(int n, int depa, int via, int dest);
	void push(int a, int b);
};

void sol::hannoi(int n, int depa, int via, int dest) {
	if (n == 1) {
		push(depa, dest);
	}
	else {
		hannoi(n - 1, depa, dest, via);
		push(depa, dest);
		hannoi(n - 1, via, depa, dest);
	}
}

void sol::push(int a, int b) {
	vector<int> vec;
	vec.push_back(a);vec.push_back(b);
	answer.push_back(vec);
}

vector<vector<int>> solution(int n) {
	sol a;
	a.hannoi(n, 1, 2, 3);
	return a.answer;
}