/*
 * 15991.cpp
 *
 *  Created on: 2022. 12. 4.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/15591
				USA Computing Olympiad > USACO 2018 January Contest > Silver 2
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/* down, up, right, left*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	//freopen("input.txt", "r", stdin);
	int nNode, nQuery;
	cin >> nNode >> nQuery;
	vvii mat(nNode + 1);

	for (int i = 1; i < nNode; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		mat[x].push_back(ii(y, cost));
		mat[y].push_back(ii(x, cost));
	}
    
	vvi  cost(nNode + 1, vi(nNode + 1, MAX_INT));

	for (int i = 0; i < nQuery; i++)
	{

		int start, threshold, ans = 0;
		cin >> threshold >> start;

		/* BFS */
		queue<ii> q;
		for (int j = 0; j < mat[start].size(); j++)
		{
			q.push(mat[start][j]);
			cost[start][mat[start][j].first] = mat[start][j].second;
		}

		while (!q.empty())
		{
			ii token = q.front(); q.pop();

			for (int k = 0; k < mat[token.first].size(); k++)
			{
				ii nNode = mat[token.first][k];
				if (cost[start][nNode.first] == MAX_INT)
				{
					cost[start][nNode.first] = cost[start][token.first] > nNode.second ? nNode.second : cost[start][token.first];
					q.push(nNode);
				}
			}
		}
        

		for (int k = 1; k < cost[start].size(); k++)
		{
			if (cost[start][k] != MAX_INT && cost[start][k] >= threshold && start != k)	ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}/*
 * 15991.cpp
 *
 *  Created on: 2022. 12. 4.
 *      Author: HyoSung
	   Problem: https://www.acmicpc.net/problem/15591
                USA Computing Olympiad > USACO December 2007 Contest > Silver 2
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INT 2100000000
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

/* down, up, right, left*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	freopen("input.txt", "r", stdin);
	int nNode, nQuery;
	cin >> nNode >> nQuery;
    vvii mat(nNode+1);

	for (int i = 1; i < nNode; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
        mat[x].push_back(ii(y, cost));
        mat[y].push_back(ii(x, cost));
	}

    for(int i =0;i<nQuery;i++)
    {
        int start, threshold, ans = 0;
        cin>>start>>threshold;

        for(int j =0;j<mat[start].size();j++)
        {
            /* BFS */
            queue<ii> q;
            vvi  cost(nNode + 1, vi(nNode + 1, MAX_INT));
            q.push(mat[start][j]);
            cost[start][mat[start][j].first] = mat[start][j].second;

            while(!q.empty())
            {
                ii token = q.front();q.pop();

                for(int k =0;k<mat[token.first].size();k++)
                {
                    ii nNode = mat[token.first][k];
                    if(cost[start][nNode.first] > nNode.second)
                    {
                        cost[start][nNode.first] = nNode.second;
                        q.push(nNode);
                    }
                }
            }
            if(cost[start][mat[start][j].first] >= threshold) ans++;
        }

        cout<<ans<<endl;
    }

	return 0;
}