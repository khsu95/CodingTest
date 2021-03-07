//https://programmers.co.kr/learn/courses/30/lessons/1844
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ii;

int solution(vector<vector<int> > maps)
{
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int answer = -1;
    vector<vector<int>> memo(maps.size(), vector<int> (maps[0].size(),0));
    for(int i=0;i<maps.size();i++)
        for(int j=0;j<maps[0].size();j++)
            if(!maps[i][j]) memo[i][j]=999;
    queue<ii> q;q.push(ii(0,0));
    while(!q.empty())
    {
        ii loc=q.front();q.pop();
        
        if((loc.first==(maps.size()-1))&&(loc.second==(maps[0].size()-1)))
        {
            answer=memo[loc.first][loc.second]+1;
            break;
        }
        
        for(int i=0;i<4;i++)
        {
            int x=loc.first+dx[i],y=loc.second+dy[i];
            if(x>=0&&x<maps.size()&&y>=0&&y<maps[0].size())
            {
                if(!memo[x][y])
                {
                    memo[x][y]=memo[loc.first][loc.second]+1;
                    q.push(ii(x,y));
                }
            }
        }
    }
    return answer;
}