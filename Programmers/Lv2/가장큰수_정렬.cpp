//https://programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include<iostream>
#include <vector>
#include <queue>
#include<sstream>

using namespace std;

typedef pair<int, int> ii; //Revised, Original

struct cmp {
	bool operator()(int op1, int op2) {
		stringstream str1, str2, str3;
		str1 << op1; str2 << op2;
		str1.str(str1.str() + str2.str());
		str3 << op1;
		str2.str(str2.str() + str3.str());
		return (stoi(str1.str()) < stoi(str2.str()));
	}
};

string solution(vector<int> numbers) {
	string answer = "";
	priority_queue<int, vector<int>, cmp> pq;
	int i = 0;
	for (i = 0;i < numbers.size();i++)
		pq.push(numbers[i]);

	//Append to String
	if (!(pq.top()))  return "0";
	while (!pq.empty()) {
		stringstream itos;
		itos << pq.top(); pq.pop();
		answer.append(itos.str());
	}

	return answer;
}