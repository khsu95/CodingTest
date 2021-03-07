//https://programmers.co.kr/learn/courses/30/lessons/49994
#include <string>
#include <vector>
using namespace std;


int solution(string dirs) {
    int answer = 0; int x=5,y=5;
    //N,S,E,W
    vector<vector<vector<bool>>> table(11,vector<vector<bool>> (11, vector<bool> (4,0)));
    
    for(int i=0;i<dirs.size();i++){
        switch (dirs[i])
        {
            case 'U':
                if(y-1>=0){
                    if(!table[x][y-1][0]){
                        table[x][y-1][0]=true;
                        table[x][y][1]=true;
                        answer++;
                    }
                    y--;
                }
                break;
            case 'D':
                if(y+1<=10){
                    if(!table[x][y+1][1]){
                        table[x][y+1][1]=true;
                        table[x][y][0]=true;
                        answer++;
                    }
                    y++;
                }
                break;
            case 'R':
                if(x+1<=10){
                    if(!table[x+1][y][2]){
                        table[x+1][y][2]=true;
                        table[x][y][3]=true;
                        answer++;
                    }
                    x++;
                }
                break;
            case 'L':
                if(x-1>=0){
                    if(!table[x-1][y][3]){
                        table[x-1][y][3]=true;
                        table[x][y][2]=true;
                        answer++;
                    }
                    x--;
                }
                break;  
        }
    }
    return answer;
}