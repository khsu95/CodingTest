//https://programmers.co.kr/learn/courses/30/lessons/12980
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans=0;
    while(n>0){
        if(n%2){
            ans++;
            n--;
        }
        else{
            n=n/2;
        }
    }
    return ans;
}