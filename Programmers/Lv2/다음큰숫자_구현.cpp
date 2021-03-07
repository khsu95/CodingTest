//https://programmers.co.kr/learn/courses/30/lessons/12911
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;
    bitset<100> op1(n);
    int i=1;
    while(1){
        bitset<100> op2(n+(i++));
        if(op1.count()==op2.count())    break;
    }
    answer = n+i-1;
    return answer;
}