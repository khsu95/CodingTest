//https://programmers.co.kr/learn/courses/30/lessons/12904
#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 1;
    int len_o=1, len_e=0;
    
    for (int j = 1; j < s.size() - 1; j++)
    {
        int len = 1;
        for (int k = 1;; k++)
        {
                if (!((0 <= (j - k)) && (j + k <= s.size())))  break;
                if (s[j - k] == s[j + k])
                    len += 2;
                else
                    break;
        }
        if(len>len_o)   len_o=len;
    }
    
    for (int j = 1; j < s.size() - 1; j++)
    {
        int len=0;
        for (int k = 1;; k++)
        {
                if (!((0 <= (j - k + 1)) && (j + k <= s.size())))  break;
                if (s[j - k + 1] == s[j + k])
                    len += 2;
                else
                    break;
        }
        if(len>len_e)   len_e=len;
    }
    
    return max(len_o,len_e);
}