#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> ii;

vector<int> Dij(int n, int s, vector<vector<ii>> &map)
{
    priority_queue<ii> pq;
    vector<int> v(n+1,9999999);
    pq.push(ii(0,s));
    while(!pq.empty())
    {
        ii elem=pq.top();pq.pop();
        if(elem.first>=v[elem.second])  continue;
        v[elem.second]=elem.first;
        for(int i=0;i<map[elem.second].size();i++)
        {
            int dist=elem.first+map[elem.second][i].second;
            if(dist<v[map[elem.second][i].first])
                pq.push(ii(dist,map[elem.second][i].first));
        }
    }
    return v;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 9999999;
    vector<vector<ii>> table(n+1);
    for(int i=0;i<fares.size();i++)
    {
        table[fares[i][0]].push_back(ii(fares[i][1],fares[i][2]));
        table[fares[i][1]].push_back(ii(fares[i][0],fares[i][2]));
    }
    
    vector<int> d=Dij(n,s,table);
    vector<int> e=Dij(n,a,table);
    vector<int> f=Dij(n,b,table);
    for(int i=1;i<=n;i++)
    {
        answer=(d[i]+e[i]+f[i]<answer)?d[i]+e[i]+f[i]:answer;
    }
    return answer;
}