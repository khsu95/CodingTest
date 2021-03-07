//https://programmers.co.kr/learn/courses/30/lessons/43105
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int i=triangle.size()-2;
    for(i;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            int dl=triangle[i][j]+triangle[i+1][j];
            int dr=triangle[i][j]+triangle[i+1][j+1];
            if(dl>dr)   triangle[i][j]=dl;
            else triangle[i][j]=dr;
        }
    }
    
    answer=triangle[0][0];
    return answer;
}