//https://programmers.co.kr/learn/courses/30/lessons/12981
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<string>::iterator iter1 = words.begin();
	vector<string>::iterator iter2 = (++words.begin());
	int index = 1;
	while (iter2 != words.end()) {
		if ((*iter1++).back() != (*iter2).front()) {
			index++;
			break;
		}
		int i = 0;
		for (;i < index;i++)
			if ((*iter2) == words[i])
				break;
		if (i < index++)
			break;
		iter2++;
	}
	vector<int> answer(2, 0);
	if (iter2 == words.end())
		return answer;
	else {
		answer[0] = (index - 1) % n + 1;
		answer[1] = ((int)((index - 1) / n)) + 1;
	}

	return answer;
}