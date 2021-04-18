#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> ii;

void Dij(int n, int s, vector<vector<ii>> &map, vector<int> &v)
{
    priority_queue<ii,vector<ii>, greater<ii>> pq;
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
    
    vector<int> d(n+1,99999999),e(n+1,99999999),f(n+1,99999999);
    Dij(n,s,table,d);
    Dij(n,a,table,e);
    Dij(n,b,table,f);
    for(int i=1;i<=n;i++)
    {
        int dist=d[i]+e[i]+f[i];
        if(dist<answer)
            answer=dist;
    }
    return answer;
}