//https://programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> m;
    map<string, int>::iterator iter;
    for(int i=0;i<clothes.size();i++){
        iter=m.find(clothes[i][1]);
        if(iter!=m.end())
            (*iter).second++;
        else
            m.insert(make_pair(clothes[i][1],1));
    }
    int answer = 1;
    for(iter=m.begin();iter!=m.end();iter++)
        answer*=(((*iter).second)+1);
    return answer-1;
}