#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> ii;

vector<int> Dij(int n, int s, vector<vector<int>> &map)
{
    priority_queue<ii> pq;
    vector<int> v(n+1,9999999);
    pq.push(ii(0,s));
    while(!pq.empty())
    {
        ii elem=pq.top();pq.pop();
        if(elem.first>=v[elem.second])  continue;
        v[elem.second]=elem.first;
        for(int i=0;i<map.size();i++)
        {
            if(map[i][0]==elem.second)
            {
                if(elem.first+map[i][2]<v[map[i][1]])
                    pq.push(ii(elem.first+map[i][2],map[i][1]));
            }
            else if(map[i][1]==elem.second)
            {
                if(elem.first+map[i][2]<v[map[i][0]])
                    pq.push(ii(elem.first+map[i][2],map[i][0]));
            }
        }
    }
    return v;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 9999999;
    vector<int> d=Dij(n,s,fares);
    vector<int> e=Dij(n,a,fares);
    vector<int> f=Dij(n,b,fares);
    for(int i=1;i<=n;i++)
    {
        answer=(d[i]+e[i]+f[i]<answer)?d[i]+e[i]+f[i]:answer;
    }
    return answer;
}