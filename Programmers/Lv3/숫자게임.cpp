//https://programmers.co.kr/learn/courses/30/lessons/12987
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void sol(list<int> &a, list<int> &b, int *ans){
    while((a.front()>=b.front())&&(!a.empty())){
        a.pop_back(); b.pop_front();
    }
    if(!a.empty()){
        a.pop_front();  b.pop_front();
        (*ans)++;
        sol(a, b, ans);
    }
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    list<int> la(A.begin(), A.end());
    la.sort();
    list<int> lb(B.begin(), B.end());
    lb.sort();
    
    sol(la, lb, &answer);
    return answer;
}