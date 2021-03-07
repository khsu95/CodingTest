//https://programmers.co.kr/learn/courses/30/lessons/42842
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total=brown+yellow;
    for(int i=1;i<=(int)total/2;i++){
        //cout<<i<<" ";
        if((total%i))   continue;
        int y=i,x=total/i;
        //cout<<x<<" "<<y<<" ";
        if((2*x+2*y-4)==brown){
            //cout<<"brown"<<" ";
            if((x-2)*(y-2)==yellow){
                //cout<<"yellow ";
                answer.push_back(x);answer.push_back(y);return answer;
            }
        }
        //cout<<endl;
    }
    return answer;
}