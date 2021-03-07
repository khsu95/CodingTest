//https://programmers.co.kr/learn/courses/30/lessons/12951
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool flag=1;
    for(int i=0;i<s.size();i++){
        if((s[i]<='z')&&(s[i]>='a')&&(flag))
            s[i]-=32;
        else if((s[i]<='Z')&&(s[i]>='A')&&(!flag))
            s[i]+=32;
        if(s[i]==' ')
            flag=1;
        else
            flag=0;
    }
    return s;
}