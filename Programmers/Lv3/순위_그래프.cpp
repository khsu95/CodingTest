//https://programmers.co.kr/learn/courses/30/lessons/49191
#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

void merge(vector<int>& op1, vector<int> op2);

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	//Forest
	vector<vector<int>> table(n+1, vector<int>(1, 0));
	for (int i = 0; i < results.size(); i++)
		table[results[i][0]].push_back(results[i][1]);

	//Merge
	for (int i = 1; i < table.size(); i++)
	{
		for (int j = 1; j < table[i].size(); j++)
		{
			merge(table[i], table[table[i][j]]);
		}
	}

	//Ordering
	for (int i = 0; i < table.size(); i++)
		table[i][0] = table[i].size();

	for (int i = 1; i < table.size(); i++)
	{
		bitset<101> memo; memo.reset();
		memo[i] = true;
		//Find node not of current parent node
		//Parent node: i
		for (int j = 1; j < table[i].size(); j++)
			if (!memo[table[i][j]])  memo[table[i][j]] = 1;
		//parent node that has current i node must have child node as it isn't not in i i node
		for (int k = 1; k < table.size(); k++)
		{
			if (memo[k]) continue;
			//Child node Parent nodes didn't have
			else
			{
				for (int l = 1; l < table[k].size(); l++)
				{
					if (i == table[k][l])
					{
						memo[k] = true;
						break;
					}
				}

			}
		}
		bool flag = 0;
		for (int j = 1; j < (n + 1); j++)
		{
			if (!memo[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)	answer++;
	}

	return answer;
}

void merge(vector<int>& op1, vector<int> op2)
{
	int bound = op1.size();
	for (int i = 1; i < op2.size(); i++)
	{
		bool flag = true;
		for (int j = 1; j < bound; j++)
			if (op2[i] == op1[j])	flag = false;
		if (flag)
			op1.push_back(op2[i]);
	}
}