//https://programmers.co.kr/learn/courses/30/lessons/42861
#define INF 10000
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> ii;

class UnionFind{
    private:
    vector<int> p, rank;
    public:
    UnionFind(int N){
        rank.assign(N,0);
        p.assign(N,0);
        for(int i=0;i<N;i++)    p[i]=i;
    }
    int findSet(int i){
        return ((p[i]==i)?i:p[i]=findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            int x=findSet(i),y=findSet(j);
            if(rank[x]>rank[y]) p[y]=x;
            else {
                p[x]=y;
                if(rank[x]==rank[y])    rank[y]++;
            }
        }
    }
};

struct cmp{
    bool operator()(ii a, ii b){
        return a.first>b.first;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<ii,vector<ii>,cmp> pq;//(Weight,vector index)
    for(int i=0;i<costs.size();i++)
        pq.push(ii(costs[i][2],i));
    UnionFind uf(n);
    while(!pq.empty()){
        int i=pq.top().second;pq.pop(); int v1=costs[i][0],v2=costs[i][1];
        if(uf.isSameSet(v1,v2)) continue;
        answer+=costs[i][2];
        uf.unionSet(v1,v2);
    }
    return answer;
}