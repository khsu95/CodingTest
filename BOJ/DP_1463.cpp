//More Information : https://kim-hs226.tistory.com/4
//https://www.acmicpc.net/problem/1463
//2022.01.19
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class my_class
{
public:
	vector<int> minimum;
	my_class(int num)
	{
		minimum.assign(num + 1, 999999);
	};
	int my_func(int num, int cnt)
	{
		if (cnt >= minimum[num])
		{
			return 0;
		}
		if (num <= 0)
		{
			return 0;
		}
		else
		{
			minimum[num] = cnt;
		}

		if (num % 3 == 0)
		{
			my_func(num / 3, cnt + 1);
		}
		if (!(num & 0x00000001))
		{
			my_func(num >> 1, cnt + 1);
		}
		my_func(num - 1, cnt + 1);
		return 0;
	};
};

int main()
{
	int num;
	cin >> num;
	
	my_class sol(num);
	sol.my_func(num, 0);

	cout << sol.minimum[1];
	return 0;
}