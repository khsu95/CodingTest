//https://programmers.co.kr/learn/courses/30/lessons/42885
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    sort(people.begin(),people.end(),greater<int>());
    pq.push(limit-people[0]);
    
    for(int i=1;i<people.size();i++){
        if((!pq.empty())&&(pq.top()>=people[i])){
            int ele=pq.top(); pq.pop(); answer++;
        }
        else
            pq.push(limit-people[i]);
    }
    answer+=pq.size();
    return answer;
}