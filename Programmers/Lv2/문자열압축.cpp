//https://programmers.co.kr/learn/courses/30/lessons/60057
//2021.05.05

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int len=1;len<=s.size()/2;len++)
    {
        string str="";
        int left=0;
        while(left<s.size())
        {
            string token=s.substr(left,len);
            int right=left+len,num=1;
            while(right<s.size())
            {
                if(token!=s.substr(right,len))
                    break;
                right+=len;
                num++;
            }
            if(num!=1)
                str+=(to_string(num))+token;
            else
                str+=token;
            left=right;
        }
        answer=(str.size()<answer)?str.size():answer;
        //cout<<"End: "<<str<<", "<<str.size()<<endl;
    }
    return answer;
}
