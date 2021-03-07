//https://programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
typedef pair<int,int> ii;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    bitset<100> memo;
    queue<ii> qu;
    priority_queue<int, vector<int>> pq;
    int max=0;
    for(int i=0;i<priorities.size();i++){
        qu.push(ii(priorities[i],i));
        pq.push(priorities[i]);
        
    }
    while(!qu.empty()){
        while(pq.top()>qu.front().first) {
            qu.push(qu.front());
            qu.pop();
        }
        pq.pop(); answer++;
        if(qu.front().second==location) break;
        qu.pop();
    }
    return answer;
}