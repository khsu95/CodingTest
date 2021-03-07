//https://programmers.co.kr/learn/courses/30/lessons/42860
#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    for(int i=0;i<name.size();i++){
        if(name[i]<'N') answer+=name[i]-'A';
        else answer+='Z'-name[i]+1;
    }
    int i=0,j=name.size()-1;
    if(name[1]=='A')
        while((name[i+1]=='A')&&(i+1)!=j) i++;
    if(name[j]=='A')
        while((name[j]=='A')&&j!=0) j--;
    int b=name.size()-1;
    int start=2,end=2,maxi=0;
    int r_start=2,r_end=2;
    while((name[1]!='A')&&(name[b]!='A')){
        start=end;
        while((name[end]=='A')&&(name[end+1]=='A'))
            end++;
        maxi=max(maxi,end-start);
        if(maxi==0&&end!=b){ end++; continue;}
        if(maxi==(end-start))  {
            r_start=start; r_end=end;
        }
        maxi++;
        if(end==b)  break;
        end++;
    }
    cout<<maxi<<" ";
    r_end=min(r_start-1,b-r_end);
    cout<<r_end<<" ";
    if(maxi>r_end)    answer=r_end+answer+r_end+r_start;
    else    answer=answer+name.size()-max(i,b-j)-1;
    return answer;
}