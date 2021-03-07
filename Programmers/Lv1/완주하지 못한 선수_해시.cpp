//https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> ms;
    for(int i=0;i<participant.size();i++)
        ms.insert(participant[i]);
    for(int i=0;i<completion.size();i++){
        multiset<string>::iterator iter=ms.find(completion[i]);
        if(iter!=ms.end())
            ms.erase(iter);
    }
    return *ms.begin();
}