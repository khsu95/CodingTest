//https://www.acmicpc.net/problem/9376
//2022.01.04
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void DFS(vector<vector<char>>& mat, ii poi, char zn)
{
	mat[poi.first][poi.second] = zn;

	for(int i=0;i<4;i++)
	{
		int nx = poi.first  + dx[i];
		int ny = poi.second + dy[i];
		if ((nx >= 0) && (nx < mat.size() && (ny >= 0) && (ny < mat[0].size())))
		{
			if (mat[nx][ny] == '$' || mat[nx][ny] == '.')
			{
				DFS(mat, ii(nx, ny), zn);
			}
		}
	}
}

vector<int> Dijk(priority_queue<ii> pq, int strt, vector<vector<int>> adj)
{
	vector<int> cost(adj.size(), 9999);
	pq.push(ii(0,strt));
	cost[strt] = 0;

	while (!pq.empty())
	{
		int nxt_cost = pq.top().first;
		int nxt_zn = pq.top().second;
		pq.pop();
		if (nxt_cost > cost[nxt_zn])
		{
			//goodbye
			continue;
		}

		for (int i = 0; i < adj[nxt_zn].size(); i++)
		{
			if (nxt_cost + adj[nxt_zn][i] < cost[i])
			{
				pq.push(ii(nxt_cost + adj[nxt_zn][i], i));
				cost[i] = nxt_cost + adj[nxt_zn][i];
			}
		}
	}

	return cost;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int cs;
	int col, row;
	char zn = 0;
	//cin >> cs;
	cin >> col >> row;
	vector<vector<char>> mat(col + 2, vector<char>(row + 2, '.'));
	queue<ii> prsn;
	queue<ii> dr;

	//Padding
	for (int i = 1; i < col+1; i++)
	{
		for (int j = 1; j < row+1; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == '#')
			{
				dr.push(ii(i, j));
			}
			if (mat[i][j] == '$')
			{
				prsn.push(ii(i, j));
			}
		}
	}

	//Make Cluster
	for (int i = 0; i < col+2; i++)
	{
		for (int j = 0; j < row+2; j++)
		{
			if (mat[i][j] == '$' || mat[i][j] == '.')
			{
				DFS(mat, ii(i, j), zn);
				zn=zn+1;
			}
		}
	}

	//make Minimum Cost Adj List
	//Use Dijkstra

	//cost
	vector<vector<int>> adj(zn, vector<int> (zn, 9999));
	while (!dr.empty())
	{
		queue<ii> us;
		int x = dr.front().first;
		int y = dr.front().second;
		dr.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0) && (nx < mat.size() && (ny >= 0) && (ny < mat[0].size())))
			{
				if (mat[nx][ny] != '#' && mat[nx][ny] != '*')
				{
					us.push(ii(nx, ny));
				}
			}
		}

		int x_zn, y_zn;
		if (!us.empty())
		{
			x_zn = us.front().first;
			y_zn = us.front().second;
			us.pop();
		}

		while (!us.empty())
		{
			int x_nbr = us.front().first;
			int y_nbr = us.front().second;
			us.pop();
			adj[mat[x_zn][y_zn]][mat[x_nbr][y_nbr]] = 1;
			adj[mat[x_nbr][y_nbr]][mat[x_zn][y_zn]] = 1;
		}
	}

	//dijkstra
	//is this right? too many lines
	//cost,zn_num
	priority_queue<ii> prsn1;
	priority_queue<ii> prsn2;
	priority_queue<ii> orz;
	vector<int> prsn_cost1(zn, 9999);
	vector<int> prsn_cost2(zn, 9999);
	vector<int> orz_cost(zn, 9999);

	prsn_cost1 = Dijk(prsn1, mat[prsn.front().first][prsn.front().second], adj);
	prsn.pop();
	prsn_cost2 = Dijk(prsn2, mat[prsn.front().first][prsn.front().second], adj);
	//cost from dest to another zn
	orz_cost = Dijk(orz, 0, adj);
	
	//On-Off BruteForce
	//Find which node is best they can join in
	int ans = prsn_cost1[0] + prsn_cost2[0];
	for (int i = 1; i < zn; i++)
	{
		int joint_cost = orz_cost[i] + prsn_cost1[i] + prsn_cost2[i] - 1;
		ans = (joint_cost < ans) ? joint_cost : ans;
	}

#if 1
	for (int i = 0; i < col+2; i++)
	{
		for (int j = 0; j < row+2; j++)
		{
			if (mat[i][j] == '#')	cout << '#' << " ";
			else if (mat[i][j] == '*')	cout << '*' << " ";
			else cout << (char)(mat[i][j]+'a') << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < prsn_cost1.size(); i++)
	{
		cout << prsn_cost1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < prsn_cost2.size(); i++)
	{
		cout << prsn_cost2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < orz_cost.size(); i++)
	{
		cout << orz_cost[i] << " ";
	}
	cout << endl;
	cout << ans;
#endif

	return 0;
}