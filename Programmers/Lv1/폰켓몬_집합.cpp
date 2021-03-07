//https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for(int i=0;i<nums.size();i++)
        if(s.find(nums[i])==s.end())
            s.insert(nums[i]);
    if(s.size()>(nums.size()/2))
        return nums.size()/2;
    return answer=s.size();
}