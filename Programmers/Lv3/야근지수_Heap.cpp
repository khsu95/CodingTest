//https://programmers.co.kr/learn/courses/30/lessons/12927
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++)
        pq.push(works[i]);
    for(int i=0;i<n;i++){
        if(pq.empty())  continue;
        int elem=pq.top(); pq.pop();
        if(elem<=0) continue;
        pq.push(elem-1);
    }
    for(int i=0;pq.size();i++){
        answer+=pq.top()*pq.top();
        pq.pop();
    }
    return answer;
}