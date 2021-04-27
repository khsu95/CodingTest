//https://programmers.co.kr/learn/courses/30/lessons/60060
//2021.04.27
#include <string>
#include <vector>
#include <map>

using namespace std;

//len of string, count
typedef pair<int, int> ii;

typedef struct _elem
{
	vector<ii> v;
	_elem(int len, int cnt)
	{
		v.push_back(ii(len, cnt));
	}
} Elem;

vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> answer;
	map<string, Elem> prefix, postfix;
	for (int i = 0;i < words.size();i++)
	{
		for (int j = 0;j <= words[i].size();j++)
		{
			map<string, Elem>::iterator iter = prefix.find(words[i].substr(0, j));
			if (iter == prefix.end())
			{
				prefix.insert(make_pair(words[i].substr(0, j), Elem(words[i].size(), 1)));
			}
			else
			{
				int k;
				for (k = 0;k < iter->second.v.size();k++)
				{
					if (iter->second.v[k].first == words[i].size())
					{
						iter->second.v[k].second++;
						break;
					}
				}
				if (k >= iter->second.v.size())
					iter->second.v.push_back(ii(words[i].size(), 1));
			}

			iter = postfix.find(words[i].substr(words[i].size() - j, j));
			if (iter == postfix.end())
			{
				postfix.insert(make_pair(words[i].substr(words[i].size() - j, j), Elem(words[i].size(), 1)));
			}
			else
			{
				int k;
				for (k = 0;k < iter->second.v.size();k++)
				{
					if (iter->second.v[k].first == words[i].size())
					{
						iter->second.v[k].second++;
						break;
					}
				}
				if (k >= iter->second.v.size())
					iter->second.v.push_back(ii(words[i].size(), 1));
			}
		}
	}

	for (int i = 0;i < queries.size();i++)
	{
		string q = "";
		int idx = -1;
		while (++idx < queries[i].size())
			if (queries[i][idx] != '?')
				q += queries[i][idx];
		if (queries[i][0] == '?')
		{
			map<string, Elem>::iterator iter = postfix.find(q);
			if (iter != postfix.end())
			{
				int j;
				for (j = 0;j < iter->second.v.size();j++)
				{
					if (iter->second.v[j].first == queries[i].size())
					{
						answer.push_back(iter->second.v[j].second);
						break;
					}
				}
				if (j >= iter->second.v.size())
					answer.push_back(0);
			}
			else
				answer.push_back(0);
		}

		else
		{
			map<string, Elem>::iterator iter = prefix.find(q);
			if (iter != prefix.end())
			{
				int j;
				for (j = 0;j < iter->second.v.size();j++)
				{
					if (iter->second.v[j].first == queries[i].size())
					{
						answer.push_back(iter->second.v[j].second);
						break;
					}
				}
				if (j >= iter->second.v.size())
					answer.push_back(0);
			}
			else
				answer.push_back(0);
		}
	}
	return answer;
}