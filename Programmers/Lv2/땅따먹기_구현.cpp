//https://programmers.co.kr/learn/courses/30/lessons/12913
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i=land.size()-2;i>=0;i--){
        for(int j=0;j<4;j++){
            int max=0;
            for(int k=0;k<4;k++){
                if(j==k) continue;
                if(max<land[i][j]+land[i+1][k]) max=land[i][j]+land[i+1][k];
            }
            land[i][j]=max;
        }
    }
    for(int i=0;i<4;i++){
        if(answer<land[0][i])   answer=land[0][i];
    }

    return answer;
}