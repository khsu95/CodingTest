//https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
	return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end(), comp);
	for (int i = 0;i < phone_book.size();i++)
		for (int j = phone_book.size() - 1;j > i;j--)
			if (!phone_book[j].compare(0, phone_book[i].size(), phone_book[i]))  return false;
	return true;
}