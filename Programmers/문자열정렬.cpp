//https://programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer(strings);
    N=n;
    struct {
        bool operator()(string a, string b)
        {   //해당 문자열의 문자가 동일한 경우
            //문자열의 기본적으로 사전순 정렬 지원
            if(a.at(N) == b.at(N)){return a<b;}
            else{return a.at(N) < b.at(N);}
        }
    } compare;
    //문자열의 기본적으로 사전순 정렬 지원
    sort(answer.begin(),answer.end(),compare);
    return answer;
}
