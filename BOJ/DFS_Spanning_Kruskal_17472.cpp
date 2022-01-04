//DFS->Bridge Check(Make Graph)->Kruskal
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;

bool DFS_Numbering(ii coor,int island_num, vector<vector<int>> &matrix,vector<vector<int>> &visit)
{
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	if (!visit[coor.first][coor.second])	return 0;
	visit[coor.first][coor.second] = 0;
	matrix[coor.first][coor.second] = island_num;

	for (int i = 0;i < 4;i++)
	{
		int x = coor.first + dx[i], y = coor.second + dy[i];
		if ((x >= 0) && (x < matrix.size()) && (y >= 0) && (y < matrix[0].size()))
			DFS_Numbering(ii(x, y), island_num, matrix, visit);
	}
	return 1;
}

ii Find_One(vector<vector<int>> visit)
{
	int x = 0, y = 0;
	while (x < visit.size())
	{
		y = 0;
		while (y < visit[0].size())
		{
			if (visit[x][y])
				return ii(x, y);
			y++;
		}
		x++;
	}
	return ii(999, 999);
}

void Bridge_Check(vector<vector<int>> matrix, vector<vector<int>> &graph_matrix)
{
	int start = 0, i = 0, j = 0;
	while(i < matrix.size())
	{
		//Landing
		while (j < matrix[i].size())
			if (matrix[i][j++])
				break;
		j--;
		while(j < matrix[0].size()-1)
		{
			//Boundary
			if (matrix[i][j] != matrix[i][j + 1])
			{
				//Meet Seashore
				if (matrix[i][j + 1] == 0)
					start = j;
				//Land
				//Bay
				else if (matrix[i][j + 1] == matrix[i][start])
					start = j;
				//Another Island
				else
					break;
			}
			j++;
		}
		j++;
		//End of Col
		if (j == matrix[0].size()) {
			j = 0;
			i++;
		}
		//Construct Bridge
		else if ((j - start >= 3) && (j - start-1 < graph_matrix[matrix[i][start]][matrix[i][j]])) //This Line Was Problem
			graph_matrix[matrix[i][start]][matrix[i][j]] = j - start - 1;
	}
}

vector<vector<int>> Transpose(vector<vector<int>> matrix)
{
	vector<vector<int>> Trans(matrix[0].size(), vector<int>(matrix.size()));
	for (int i = 0;i < matrix.size();i++)
	{
		vector<int> col = matrix[i];
		for (int j = 0;j < col.size();j++)
			Trans[j][i] = col[j];
	}
	return Trans;
}

struct comp {
	bool operator()(iii v1, iii v2)
	{
		return v1.first > v2.first;
	}
};

class Kruskal {
public:
	vector<int> parent;
	vector<vector<int>> matrix;
	priority_queue<iii,vector<iii>,comp> pq;
	Kruskal(vector<vector<int>> matrix)
	{
		this->matrix = matrix;
		for (int i = 0;i < matrix.size();i++)
			for (int j = 0;j < matrix.size();j++)
				if (matrix[i][j] != 999)
					pq.push(iii(matrix[i][j], ii(i, j)));
		parent.assign(matrix.size(), 0);
		for (int i = 0;i < parent.size();i++)
			parent[i] = i;

	};
	void Merge(int v1, int v2)
	{
		int boss = parent[v1], sub = parent[v2];
		for (int i = 1;i < parent.size();i++)
			if (parent[i] == sub)	parent[i] = boss;
	};
	int Find(int i)
	{
		if (parent[i] == i)	return i;
		else return Find(parent[i]);
	};
	int Kruskal_Run()
	{
		int ans = 0;
		while (!pq.empty())
		{
			iii v = pq.top();pq.pop();
			if (Find(v.second.first) == Find(v.second.second))
				continue;
			Merge(v.second.first, v.second.second);
			ans += v.first;
		}
		
		//Check Vertical(Not Enough to Check Only Edge)
		for (int i = 2;i < parent.size();i++)
			if (parent[i] != parent[i - 1])
				return -1;
		if (!ans)	return -1;
		return ans;
	};
};



int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int col, row;
	cin >> col >> row;

	vector<vector<int>> matrix(col, vector<int>(row, 0));
	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> matrix[i][j];

	//DFS->Island Numbering
	vector<vector<int>> visit = matrix;
	ii coor(0, 0);
	int island_num = 0;
	coor = Find_One(visit);
	while (coor.first != 999)
	{
		island_num++;
		DFS_Numbering(coor, island_num, matrix, visit);
		coor = Find_One(visit);
	}

	//Convert to Graph
	vector<vector<int>> graph_matrix(island_num+1, vector<int>(island_num+1, 999));
	Bridge_Check(matrix, graph_matrix);
	//Transpose
	Bridge_Check(Transpose(matrix), graph_matrix);

	//Kruskal
	Kruskal K(graph_matrix);
	cout << K.Kruskal_Run();
	return 0;

}
