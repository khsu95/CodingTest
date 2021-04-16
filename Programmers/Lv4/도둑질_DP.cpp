#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DFS_DP(vector<int> &memo, vector<bool> &visit, vector<int> &arr, int th)
{
    if(th>=memo.size()) return 0;
    if(visit[th])    return memo[th];
    visit[th]=1;
    return memo[th]=max(DFS_DP(memo, visit, arr, th+2),DFS_DP(memo, visit, arr, th+3))+arr[th];
}

int solution(vector<int> money) 
{
    int answer = 0;
    vector<int> ans(money.size()-1,0);
    vector<bool> visit(money.size(),0);
    DFS_DP(ans,visit, money, 0);
    answer=ans[0];
    
    fill(ans.begin(),ans.end(),0);ans.push_back(0);
    fill(visit.begin(),visit.end(),0);
    DFS_DP(ans, visit, money, 1);
    answer=(ans[1]>answer)?ans[1]:answer;
    
    DFS_DP(ans,visit, money,2);
    answer=(ans[2]>answer)?ans[2]:answer;
    return answer;
}