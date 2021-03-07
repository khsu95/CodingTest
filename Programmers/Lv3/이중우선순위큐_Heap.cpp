//https://programmers.co.kr/learn/courses/30/lessons/42628
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    list<int> mmq;
    list<int>::iterator iter=mmq.begin();
    
    for(int i=0;i<operations.size();i++){
            switch(operations[i][0]){
                //Case for Insert
                //descending order
                case 'I':
                    iter=mmq.begin();
                    while(iter!=mmq.end()){
                        if(*iter>stoi(operations[i].substr(2))){
                            mmq.insert(iter,stoi(operations[i].substr(2)));
                            break;
                        }
                        iter++;
                    }
                    if(iter==mmq.end())
                        //cout<<"LAST\n";
                        mmq.insert(mmq.end(),stoi(operations[i].substr(2)));
                    
                    //cout<<operations[i].substr(2)<<" "<<mmq.front()<<endl;
                    break;
                    
                //Case for Delete
                case 'D': 
                    //Delete Max
                    if(operations[i][2]=='1'){
                        if(!mmq.empty())    mmq.pop_back();
                    }
                    //Delete Min
                    else
                        if(!mmq.empty())    mmq.pop_front();
                    break;
                default:
                    break;
            }
    }
    
    //cout<<"Print Q"<<endl;
    //iter=mmq.begin();
    //while(iter!=mmq.end())
   //     cout<<*iter++<<endl;
    
    if(!mmq.empty()){
        answer.push_back(mmq.back());
        answer.push_back(mmq.front());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}