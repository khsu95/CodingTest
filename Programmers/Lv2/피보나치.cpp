//https://programmers.co.kr/learn/courses/30/lessons/12945
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> ans(n+1, 0);
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=(ans[i-1]+ans[i-2])%1234567;
    }
    return ans[n]%1234567;
}