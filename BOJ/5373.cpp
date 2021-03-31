//https://www.acmicpc.net/problem/17140
//2021.03.31
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class sol
{
public:
	vector<vector<int>> t;
	vector<vector<vector<char>>> cube;
	sol()
	{
		vector<int> temp(4, 0);
		temp[0] = 2;temp[1] = 4;temp[2] = 3;temp[3] = 5;
		t.push_back(temp);
		temp[0] = 5;temp[1] = 3;temp[2] = 4;temp[3] = 2;
		t.push_back(temp);
		temp[0] = 0;temp[1] = 5;temp[2] = 1;temp[3] = 4;
		t.push_back(temp);
		temp[0] = 4;temp[1] = 1;temp[2] = 5;temp[3] = 0;
		t.push_back(temp);
		temp[0] = 0;temp[1] = 2;temp[2] = 1;temp[3] = 3;
		t.push_back(temp);
		temp[0] = 3;temp[1] = 1;temp[2] = 2;temp[3] = 0;
		t.push_back(temp);

		char c_temp[6] = { 'w','y','r','o','b','g' };
		for (int i = 0;i < 6;i++)
		{
			vector<vector<char>> vvc_temp(3, vector<char>(3, c_temp[i]));
			cube.push_back(vvc_temp);
		}
	};

	void Rotation(char face, char wise);
	int Char2Int(char a)
	{
		switch (a)
		{
		case 'U':
			return 0;
		case 'D':
			return 1;
		case 'F':
			return 2;
		case 'B':
			return 3;
		case 'R':
			return 4;
		case 'L':
			return 5;
		default:
			return -1;
		}
	};
};

void sol::Rotation(char face, char wise)
{
	vector<char> R_F_temp(3);
	vector<char> R_S_temp(3);
	bool dir = (wise == '-') ? 1 : 0;
	int loop = 0;
	for (int i = 3 - 3 * dir;(i >= 0) && (i < 4);i += (-1 + 2 * dir))
	{
		int Face = t[Char2Int(face)][i];
		R_S_temp = cube[Face][2 * (Face % 2)];
		if (!loop)
		{
			int End_Face = t[Char2Int(face)][dir ? 3 : 0];
			cube[Face][2 * (Face % 2)] = cube[End_Face][2 * (Face % 2)];
		}
		else
			cube[Face][2 * (Face % 2)] = R_F_temp;
		R_F_temp = R_S_temp;
		loop++;
	}
}


int main(int argc, char** argv)
{


	freopen("input.txt", "r", stdin);
	int tc, num;
	cin >> tc;
	for (int i = 0;i < tc;i++)
	{
		cin >> num;
		sol _sol;
		for (int j = 0;j < num;j++)
		{
			char a, b;
			cin >> a >> b;
			_sol.Rotation(a, b);
		}
		for (int j = 0;j < 3;j++)
		{
			for (int k = 0;k < 3;k++)
			{
				cout << _sol.cube[0][j][k];
			}
			cout << endl;
		}
	}
	return 0;
}