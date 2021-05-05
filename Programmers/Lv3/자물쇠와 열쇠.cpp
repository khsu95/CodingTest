//https://programmers.co.kr/learn/courses/30/lessons/60059
//2021.04.27
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool _Chk(vector<vector<int>>& lock)
{
	for (int i = 0;i < lock.size();i++)
		for (int j = 0;j < lock.size();j++)
			if (!lock[i][j])
				return false;
	return true;
}

bool _Match(vector<vector<int>>& key, vector<vector<int>>& lock)
{
	for (int i = -1 * (key.size()-1);i < (int)lock.size();i++)
	{
		for (int j = -1 * (key.size()-1);j < (int)lock.size();j++)
		{
			vector<vector<int>> temp_lock = lock;
			//Check
			for (int k = 0;(k < key.size()) && ((i + k) < (int)lock.size());k++)
			{
				if (i + k < 0)   continue;
				for (int l = 0;(l < key.size()) && ((j + l) < (int)lock.size());l++)
				{
					if (j + l < 0)   continue;
					temp_lock[i + k][j + l] = lock[i + k][j + l] ^ key[k][l];
				}
			}
			if (_Chk(temp_lock))
				return true;
		}
	}
	return false;
}

void _Rot(vector<vector<int>>& key)
{
	//Because This is Square Matrix
	vector<vector<int>> temp = key;
	for (int i = 0;i < key.size();i++)
		for (int j = 0;j < key.size();j++)
			key[j][key.size() - 1 - i] = temp[i][j];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	if (_Chk(lock))
		return true;
    if(_Match(key,lock))
        return true;
	for (int i = 0;i < 3;i++)
	{
        _Rot(key);
		if (_Match(key, lock))
			return true;
	}
	return false;
}