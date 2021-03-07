//https://programmers.co.kr/learn/courses/30/lessons/68936
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tno[2];

vector<vector<int>> ar;

int qt(int x, int y, int len){
    bool flag=0;
    int i,j;
    //cout<<"("<<x<<","<<y<<","<<len<<")"<<endl;
    if(len==1){
        tno[ar[x][y]]++;
        return 0;
    }
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(ar[x][y]!=ar[x+i][y+j]){
                flag = 1;
                break;
            }
        }
        if(flag)    break;
    }
    if(flag){
        qt(x, y, len/2);
        qt(x+len/2, y, len/2);
        qt(x, y+len/2, len/2);
        qt(x+len/2, y+len/2, len/2);
    }
    else
        tno[ar[x][y]]++;
    return 0;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    ar=arr;
    tno[0]=0;tno[1]=0;
    qt(0,0,arr.size());
    answer.push_back(tno[0]);answer.push_back(tno[1]);
    return answer;
}