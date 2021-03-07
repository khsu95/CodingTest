//https://programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> tc;
vector<int> ans;

bool dfs(vector<int> arr, int size) {
	if (arr.size() == tc.size())
	{
		ans = arr;
		return false;
	}

	for (int i = 0; i < size; i++)
	{
        //There is ticket depart from current location
		if (tc[arr.back()][1] == tc[i][0])
		{
			bool flag = 0;
            //Overlap
			for (int j = 0; j < arr.size(); j++)
				if (arr[j] == i)   flag = 1;
            //Next Location
			if (!flag)
			{
				vector<int> tt=arr; tt.push_back(i);
				if (!dfs(tt, size)) i = size + 1;
			}
		}
	}
	return true;
}

bool cmp(vector<string> op1, vector<string> op2)
{
	if (op1[0] == op2[0]) return op1[1] > op2[1];
	else return op1[0] > op2[0];
}


vector<string> solution(vector<vector<string>> tickets) {
	tc = tickets;

	sort(tc.begin(), tc.end(), cmp);

	for (int i = 0;i < tc.size();i++)
	{
		if (tc[i][0] == "ICN")
		{
			vector<int> temp(1, i);
			dfs(temp, tc.size());
		}

	}

	vector<string> answer;
	answer.push_back("ICN");
	for (int i = 0; i < ans.size();i++)
	{
		answer.push_back(tc[ans[i]][1]);
	}
	return answer;
}