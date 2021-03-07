//https://programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int len=citations.size();
    
    sort(citations.begin(),citations.end());
    
    for(int h=citations.back();h>=0;h--){
        int ind;
        for(ind=len-1;ind>=0;ind--)
            if(citations[ind]<h)    break;
        ind++;
        if((len-ind>=h)&&(ind<=h))  return h;
    }
    return false;
}