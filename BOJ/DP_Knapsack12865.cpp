//https://www.acmicpc.net/problem/12865

/*
 * 12865.c
 *
 *  Created on: 2021. 12. 24.
 *      Author: HyoSung
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

void my_func(int nval, int nwgt, int depth);

vector<ii> v;
vector<vector<int>> memo;
int num, wgt, ans;

int main()
{
    ans = 0;

	freopen("input.txt", "r", stdin);
	
    cin>>num>>wgt;
    v.assign(num, ii(0,0));
    memo.assign(num, vector<int> (100*1100, 0));
    for(int i=0;i< num; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    my_func(0, 0, 0);
    cout << ans;
}
//(wgt, val)
void my_func(int nwgt, int nval, int depth)
{
    
    if((depth >= num) || (nwgt == wgt))
    {
        ans = (nval > ans) ? nval : ans;
        return;
    }

    if((memo[depth][nval]==0)||(memo[depth][nval]> nwgt))
    {
        memo[depth][nval] = nwgt;
        for(int i = depth; i<num; i++)
        {
            if( memo[depth][nval]+ v[i].first > wgt)  return;
            ans = nval + v[i].second > ans ? nval + v[i].second : ans;
            my_func(memo[depth][nval]+ v[i].first, nval + v[i].second, i + 1);
        }
    } 
}
