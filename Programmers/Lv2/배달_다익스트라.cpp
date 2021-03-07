//https://programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> a(N+1, vector<int> (N+1,999999));
    //Pre-processing
    for(int i=0;i<road.size();i++){
        if(a[road[i][0]][road[i][1]]>road[i][2]){
            a[road[i][0]][road[i][1]]=road[i][2];
            a[road[i][1]][road[i][0]]=road[i][2];
        }
    }
    //Dijstra
    queue<ii> pq;
    vector<int> memo(N+1, 999999);
    pq.push(ii(1,0));
    while(!pq.empty()){
        ii node1=pq.front();pq.pop();
        if(node1.second>=memo[node1.first])  continue;
        memo[node1.first]=node1.second;
        for(int i=0;i<a[node1.first].size();i++){
            if(a[node1.first][i]==999999)   continue;
            ii node2=ii(i,a[node1.first][i]);
            node2.second+=node1.second;
            pq.push(node2);
        }
    }
    for(int i=2;i<memo.size();i++)
        if(memo[i]<=K)  answer++;

    return answer+1;
}