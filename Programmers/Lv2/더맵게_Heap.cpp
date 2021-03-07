//https://programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>,greater<int>> pq;
    for(int i=0;i<scoville.size();i++)   pq.push(scoville[i]);
    while(pq.top()<K)  {
        if(pq.empty())  return -1;
        int op1=pq.top();pq.pop();
        if(pq.empty()) return -1;
        int op2=pq.top();pq.pop();
        pq.push(op1+2*op2);
        answer++;
    }
    return answer;
}