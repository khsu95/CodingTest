//https://programmers.co.kr/learn/courses/30/lessons/42888
//2021.05.05

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, string> is;
typedef pair<string, string> ss;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    queue<is> q;
    map<string,string> m;
    for(int i=0;i<record.size();i++)
    {
        int idx=-1;
        vector<string> token;
        for(int j=0;j<record[i].size();j++)
        {
            if(record[i][j]==' ')
            {
                token.push_back(record[i].substr(idx+1,j-idx-1));
                idx=j;
            }
        }
        token.push_back(record[i].substr(idx+1));
        
        if(token[0]=="Enter")
        {
            if(m.find(token[1])==m.end())
                m.insert(ss(token[1],token[2]));
            else
                m.find(token[1])->second=token[2];
            q.push(is(0,token[1]));
        }
        else if(token[0]=="Leave")
            q.push(is(1,token[1]));
        else if(token[0]=="Change")
            m.find(token[1])->second=token[2];
    }
    
    while(!q.empty())
    {
        int enter=q.front().first;
        string id=q.front().second;
        q.pop();
        if(!enter)
            answer.push_back(m.find(id)->second+"님이 들어왔습니다.");
        else
            answer.push_back(m.find(id)->second+"님이 나갔습니다.");
    }
    return answer;
}
