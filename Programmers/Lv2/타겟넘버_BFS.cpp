//https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    q.push(numbers[0]); q.push(-1*(numbers[0]));
    for(int i=1;i<numbers.size();i++){
        for(int j=q.size();j>0;j--){
            int ele=q.front(); q.pop();
            q.push(ele-numbers[i]); q.push(ele+numbers[i]);
        }
    }
    while(!q.empty()){   
        if(q.front()==target) answer++;
        q.pop();
    }
    return answer;
}