//https://programmers.co.kr/learn/courses/30/lessons/68645
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> seq;
    for(int i=0;i<n;i++){
        vector<int> temp(i+1,0);
        seq.push_back(temp);
    }
    int up=0,down=n-1,left=0,right=n-1;
    int se=1;
    int limit=n*(n+1)/2+1;
    bool flag=0;
    while(1){
       for(int i=up;i<=down;i++){
           seq[i][left]=se++;
           if(se==limit) {flag=1;break;}
           }
        if(flag) break;
        for(int i=left+1;i<=right;i++){
            seq[down][i]=se++;
            if(se==limit) {flag=1;break;}
        }
        if(flag) break;
        int j=right-1;
        for(int i=down-1;i>=up+1;i--){
            seq[i][j--]=se++;
            if(se==limit) {flag=1;break;}
        }
        if(flag) break;
        up+=2;down-=1;left+=1;right-=2;
    }
    
    for(int i=0;i<seq.size();i++)
        for(int j=0;j<seq[i].size();j++)
            //cout<<seq[i][j]<<" ";
            answer.push_back(seq[i][j]);
    
    return answer;
}