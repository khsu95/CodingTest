//https://programmers.co.kr/learn/courses/30/lessons/42883
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

char ma(string n){
    int maxi=0;
    for(int j=1;j<n.size();j++)
        if(n[maxi]<n[j])   maxi=j; 
    return maxi;
}

string solution(string number, int k) {
    string answer="";
    int right=(number.size()-1),left=0;
    for(int res=(number.size()-k);res>0;res--){
        right=number.size()-res;
        left=ma(number.substr(left,right-left+1))+left;
        answer+=number[left++];
    }
    return answer;
}