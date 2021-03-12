//https://programmers.co.kr/learn/courses/30/lessons/17685
//2021303.12
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct comp {
	bool operator ()(string a, string b)
	{
		int i = 0;
		while (i < a.size())
		{
			if (a[i] != b[i])
				return a[i] > b[i];
			i++;
		}
		return a.size() < b.size();
	}
};

int solution(vector<string> words) {
	int answer = 0;
	priority_queue<string> pq;
	for (int i = 0;i < words.size();i++)
		pq.push(words[i]);

	string left = "";
	string center = pq.top();pq.pop();
	int l_c = 0;
	for (int i = 0;i < words.size();i++)
	{
		string right = "";
		if (!pq.empty())
		{
			right = pq.top();
			pq.pop();
		}
		//Relation Between Center and Right
		int c_r = 0;
		while (center[c_r] == right[c_r])
			c_r++;
		if (center.size() > ((l_c > c_r) ? (l_c + 1) : (c_r + 1)))
			answer += (l_c > c_r) ? (l_c + 1) : (c_r + 1);
		else
			answer += center.size();
		l_c = c_r;
		left = center;
		center = right;
	}
	return answer;
}