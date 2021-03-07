//https://programmers.co.kr/learn/courses/30/lessons/68644
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int>::iterator iter=progresses.begin();
    int count=0;
    while(iter!=progresses.end()){
        for(int i=0;i<progresses.size();i++)    progresses[i]+=speeds[i];
        while(iter!=progresses.end()&&(*iter)>=100){
            cout<<(*iter)<<" ";
            iter++;
            count++;
        }
        if(count)   answer.push_back(count);
        count=0;
    }
    return answer;
}