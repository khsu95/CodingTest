//https://programmers.co.kr/learn/courses/30/lessons/43163
#include <string>
#include <vector>
#include<iostream>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool flag=0;
    vector<vector<int>> adj;
    words.push_back(begin);
    vector<int> v(1,0);
    for(int i=0;i<words.size();i++) adj.push_back(v);
    
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
            for(int k=0;k<words[i].size();k++){
                if(words[i][k]!=words[j][k]){
                    if(!flag)   flag=1;
                    else {flag=0;break;}
                }
            }
            if(flag)    adj[i].push_back(j);
            flag=0;
        }
    }
    
    for(int i=0;i<adj.size();i++)
        for(int j=0;j<adj[i].size();j++)
            cout<<i<<" "<<adj[i][j]<<endl;
    
    int b=words.size()-1;
    int t;
    for(t=0;t<words.size();t++)
        if(!(words[t].compare(target))) break;
    cout<<b<<" "<<t<<endl;
    queue<ii> q;q.push(ii(b,0));
    while(!q.empty()){
        int v=q.front().first;int dist=q.front().second;q.pop();
        for(int i=1;i<adj[v].size();i++){
            int nv=adj[v][i];
            if(adj[nv][0]!=0)   continue;
            if(nv==t)
                return dist+1;
            q.push(ii(nv,dist+1));
        }
    }

    return answer;
}