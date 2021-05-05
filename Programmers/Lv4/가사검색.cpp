//https://programmers.co.kr/learn/courses/30/lessons/60060
//2021.04.27
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//len of string, count
typedef pair<int, int> ii;

typedef struct _elem
{
	unordered_map<int, int> m;
	_elem(int len, int cnt)
	{
		m.insert(ii(len, cnt));
	}
} Elem;

vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> answer(queries.size(),0);
	unordered_map<string, Elem> prefix, postfix;
	unordered_map<int, int>::iterator m_iter;
	unordered_map<string, Elem>::iterator iter;
	for (int i = 0;i < words.size();i++)
	{
		for (int j = 0;j <= words[i].size();j++)
		{
			string sub = words[i].substr(0, j);
			iter = prefix.find(sub);
			if (iter != prefix.end())
			{
				m_iter = iter->second.m.find(words[i].size());
				if (m_iter != iter->second.m.end())
					m_iter->second++;
				else
					iter->second.m.insert(ii(words[i].size(), 1));
			}
			else
			{
				prefix.insert(make_pair(sub, Elem(words[i].size(), 1)));
			}

			sub = words[i].substr(words[i].size() - j, j);
			iter = postfix.find(sub);
			if (iter != postfix.end())
			{
				m_iter = iter->second.m.find(words[i].size());
				if (m_iter != iter->second.m.end())
					m_iter->second++;
				else
					iter->second.m.insert(ii(words[i].size(), 1));
			}
			else
			{
				postfix.insert(make_pair(sub, Elem(words[i].size(), 1)));
			}
		}
	}

    
	for (int i = 0;i < queries.size();i++)
	{
		if (queries[i][0] == '?')
		{
			int idx = -1;
			while (idx < (int)queries[i].size())
				if (queries[i][++idx] != '?')	break;
			string q = queries[i].substr(idx);

			iter = postfix.find(q);
			if (iter != postfix.end())
			{
				m_iter = iter->second.m.find(queries[i].size());
				if (m_iter != iter->second.m.end())
					answer[i]=m_iter->second;
            }
		}

		else
		{

			int idx = queries[i].size();
			while (idx > 0)
				if (queries[i][--idx] != '?')	break;
			string q = queries[i].substr(0, idx+1);

			iter = prefix.find(q);
			if (iter != prefix.end())
			{
				m_iter = iter->second.m.find(queries[i].size());
				if (m_iter != iter->second.m.end())
					answer[i]=m_iter->second;
			}
		}
	}
    
	return answer;
}
