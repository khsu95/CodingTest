//https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <vector>
#include<cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    int q,r;
    q=n;
    while(1){
        r=q%3;
        q=floor(q/3);
        if(r==0)    {
            answer+=("4");
            q-=1;
        }
        if(r==1)    answer+=("1");
        if(r==2)    answer+=("2");
        if(q==0)    break;
    }
    string rev="";
    int j=answer.size()-1;
    for(int i=0;i<answer.size();i++)
        rev+=answer[j--];
    return rev;
}