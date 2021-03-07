//https://programmers.co.kr/learn/courses/30/lessons/12936
#include <string>
#include <vector>
#include <list>

using namespace std;
typedef unsigned long long ull;

void factorial(vector<ull>& a) {
	for (int i = 1;i < a.size();i++)
		a[i] = i * a[i - 1];
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector<ull> fact(n + 1, 1);
	list<int> lis;
	for (int i = 0;i < n;i++)
		lis.push_back(i + 1);
	list<int>::iterator iter = lis.begin();
	factorial(fact);

	ull left = 1, right = left, end = fact[n];
	int depth = n;
	while (depth > 0)
	{
		while (right <= end)
		{
			if (k < right + fact[depth - 1])
			{
				left = right; end = right+fact[depth-1]; depth--;
				answer.push_back((*iter));
				lis.erase(iter);
				iter = lis.begin();
				break;
			}
			else
			{
				right += fact[depth - 1];
				iter++;
			}
		}
	}
	return answer;
}