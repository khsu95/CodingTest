//https://programmers.co.kr/learn/courses/30/lessons/12909
#include<string>
#include <iostream>
#include <stack>


using namespace std;

bool solution(string s)
{
    bool answer = true;
    int i;
    stack<int> stack;
    for(i=0;i<s.size();i++){
        if(s[i]=='(')   stack.push(1);
        else{
            if(stack.empty())   break;
            stack.pop();
        }
    }
    if((stack.empty())&&(i==s.size())) answer = true;
    else answer = false;

    return answer;
}