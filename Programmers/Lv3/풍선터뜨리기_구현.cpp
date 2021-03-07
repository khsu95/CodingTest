//https://programmers.co.kr/learn/courses/30/lessons/68646
#define MAX 1000000000
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int minimum=MAX;
    vector<bool> table(a.size(),false);
    for(int i=0;i<a.size();i++){
        if(a[i]<minimum){
            minimum=a[i];
            table[i]=true;
        }
    }
    minimum=MAX;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<minimum){
            minimum=a[i];
            table[i]=true;
        }
    }
    for(int i=0;i<a.size();i++)
        if(table[i])    answer++;
    //HS
    return answer;
}