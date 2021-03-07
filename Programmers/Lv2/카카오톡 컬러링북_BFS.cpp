//https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <bitset>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int size = 0;
	int dx[4] = { -1,1,0,0 };  int dy[4] = { 0,0,-1,1 };
	queue<ii> q;

	int row = picture[0].size(); int col = picture.size();
	vector<bitset<101>> memo(col);
	for (int i = 0;i < col;i++)
		for (int j = row;j < 101;j++)
			memo[i][j] = 1;

	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			if (!picture[i][j]) {
				memo[i][j] = 1;
				size++;
			}

	while (size != row * col) {
		int this_size = 1;
		number_of_area;
		for (int i = 0;i < col;i++) {
			for (int j = 0;j < row;j++) {
				if (!memo[i][j]) {
					q.push(ii(i, j));
					memo[i][j] = 1;
					size++;
					j = 200;i = 200;
				}
			}
		}

		//cout<<q.size()<<endl;
		number_of_area++;
		while (!q.empty()) {
			ii elem = q.front(); q.pop();
			//cout<<elem.first<<", "<<elem.second<<endl;
			for (int i = 0;i < 4;i++) {
				ii item = elem;   item.first += dx[i];  item.second += dy[i];
				if ((item.first < col) && (item.first >= 0) && (item.second < row) && (item.second >= 0)) {
					if (picture[item.first][item.second] == picture[elem.first][elem.second]) {
						if (!memo[item.first][item.second]) {
							q.push(item);
							memo[item.first][item.second] = 1;
							this_size++;
							size += 1;
						}
					}
				}
			}
			//End of 4Dir
		}
		//End of One Area
		if (this_size > max_size_of_one_area)  max_size_of_one_area = this_size;
	}


	vector<int> answer(2);
	answer[0] = number_of_area ;
	answer[1] = max_size_of_one_area;
	return answer;
}