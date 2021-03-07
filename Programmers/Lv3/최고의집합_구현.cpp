//https://programmers.co.kr/learn/courses/30/lessons/12938
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    int avg=(int)s/n;
    if(!avg)    return vector<int> (1,-1);
    vector<int> answer(n, avg);
    int left=s-n*avg;
    for(int i=answer.size()-1;answer.size()-i<=left;i--)
        answer[i]++;
    return answer;
}