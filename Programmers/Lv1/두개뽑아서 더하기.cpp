//https://programmers.co.kr/learn/courses/30/lessons/68644
#include <string>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bitset<1000> memo;
    priority_queue<int,vector<int>,greater<int>> pq;
    memo.reset();
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            int num=numbers[i]+numbers[j];
            if(!memo[num])  {
                memo[num]=true;
                pq.push(num);
            }
        }
    }
    
    while(!pq.empty()){
        answer.push_back(pq.top()); pq.pop();
    }
    return answer;
}