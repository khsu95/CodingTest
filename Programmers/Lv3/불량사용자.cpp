//https://programmers.co.kr/learn/courses/30/lessons/64064
//2021.05.06

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <set>

using namespace std;

set<unsigned long>  s;

void DFS(int idx, bitset<9> bs, vector<vector<int>> &table)
{
    if(idx>=table.size())
    {
        if(s.find(bs.to_ulong())==s.end())
            s.insert(bs.to_ulong());
        return;
    }
    
    for(int i=0;i<table[idx].size();i++)
    {
        if(!bs[table[idx][i]])
        {
            bitset<9> temp=bs;temp[table[idx][i]] =true;
            DFS(idx+1, temp,table);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    vector<vector<int>> num(banned_id.size());
    
    for(int i=0;i<banned_id.size();i++)
    {
        for(int j=0;j<user_id.size();j++)
        {
            if(user_id[j].size()!=banned_id[i].size())
                continue;
            bool flag=1;
            for(int k=0;flag&&k<banned_id[i].size();k++)
            {
                if(banned_id[i][k]=='*')    
                    continue;
                if(banned_id[i][k]!=user_id[j][k])
                    flag=0;
            }
            if(flag)
                num[i].push_back(j);
        }
    }
    
    bitset<9> bs;
    DFS(0,bs,num);
    
    return s.size();
}