//https://programmers.co.kr/learn/courses/30/lessons/70129
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int length(int a) {
	int i = 0;
	while (a / 2 > 0) {
		a = a / 2;
		i++;
	}
	if (i + 1 > 150000)	return 150000;
	return i+1;
}

void binary(bitset<150000> s, int len, int* count, int* deleted) {
	int i, j = 0;
	for (i = 0;i < len;i++)
		if (s[i])   j++;
	(*count)++;(*deleted) += (len - j);
	bitset<150000> temp(j);
	if (j > 1)    binary(temp, length(j),count, deleted);
}

vector<int> solution(string s) {
	vector<int> answer(2, 0);
	bitset<150000> temp;
	for (int i = 0;i < s.size();i++)
		if (s[i] == '1')   temp[i] = true;
	int a = 0, b = 0;
	binary(temp, s.size(),&a, &b);
	answer[0] = a;answer[1] = b;
	return answer;
}