//https://programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string conv(int a) {
	string s = "";
	if (a < 0) {
		s = "-";
		a = a * (-1);
	}
	return s += (a + '0');
}

string solution(string s) {
	string answer = "";
    int left=0;
    s+=' ';
	vector<int> pq;
	for (int right = 0;right < s.size();right++) {
        if(s[right]==' '){
            pq.push_back(stoi(s.substr(left,right-left)));
            left=right;
        }
	}
	sort(pq.begin(), pq.end());
	answer = to_string(pq.front());
	answer += " ";
	answer += to_string(pq.back());
	return answer;
}