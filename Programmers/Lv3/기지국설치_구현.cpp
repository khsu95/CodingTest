//https://programmers.co.kr/learn/courses/30/lessons/12979
#include <vector>

using namespace std;

int howmany(int space, int w){
    int quo=(int)(space/(2*w+1));
    int left=space%(2*w+1);
    
    if(quo==0)
        return 1;
    else if(left==0)
        return quo;
    else
        return quo+1;
}

int solution(int n, vector<int> stations, int w)
{
    int ans=0;

    int bs1=stations.back();
    if((n-(bs1+w))>0)
        ans+=howmany(n-(bs1+w),w);
    for(int i=stations.size()-2;i>=0;i--){
        int bs2=stations[i];
        int space=(bs1-w)-(bs2+w)-1;
        if(space>0)
            ans+=(howmany(space,w));
        bs1=bs2;
    }
    if((bs1-w)-1>0)
        ans+=(howmany(bs1-w-1,w));
    return ans;
}