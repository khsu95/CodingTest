//https://programmers.co.kr/learn/courses/30/lessons/64063
//2021.04.19
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number)
{
	vector<long long> answer;
	map<long long, long long> s;
	map<long long, long long>::iterator iter_left, iter_right;
	for (int i = 0;i < room_number.size();i++)
	{
		long long n = room_number[i];
		iter_left = iter_right = s.find(n);
		while (iter_right != s.end())
		{
			n = iter_right->second;
			iter_right = s.find(n);
		}
		iter_right = s.insert(make_pair(n, n+1)).first;
		if (s.find(n + 1) != s.end())
			iter_right->second = s.find(n + 1)->second;
		
        if(iter_left!=s.end())
			(*iter_left).second = (*iter_right).second;
        
		answer.push_back(n);
	}
	return answer;
}