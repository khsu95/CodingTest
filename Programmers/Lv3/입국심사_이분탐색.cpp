//https://programmers.co.kr/learn/courses/30/lessons/43238
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

typedef pair<long long, int> li;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	
	long long maxi = 0;

	for (int i = 0;i < times.size();i++)	if (maxi < times[i])	maxi = times[i];
	maxi = maxi * (long long)n;


	long long ncal = 0;
	long long right = maxi, left = 1, mid = 0;
	while (left<=right) {
		mid = (right + left) / 2;
		ncal = 0;
		for (int i = 0;i < times.size();i++)
			ncal += mid / times[i];
		if (ncal >= n)  {
            if(!answer) answer=mid;
            else    answer=min(answer,mid);
            right=mid-1;;
        }
		else left = mid+1;
	}

	return answer;
}