//https://programmers.co.kr/learn/courses/30/lessons/42584
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int c=0;
    for(int i=0;i<prices.size()-1;i++){
        for(int j=i+1;j<prices.size();j++){
            c++;
            if(!(prices[i]<=prices[j])) break;
        }
        answer.push_back(c);
        c=0;
    }
    answer.push_back(0);
    return answer;
}