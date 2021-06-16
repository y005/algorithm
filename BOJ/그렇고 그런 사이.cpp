//https://www.acmicpc.net/problem/20921
#include<iostream>
#include<algorithm>
#include<vector>
#include <set>
using namespace std;

int N,K;
vector<int> v;
//이미 배열에 넣은 수를 저장
set<int> entry;
//오름차순 배열에서 필요한 K를 충족하기 위해
//오른쪽 수를 앞으로 배치하는 전략
//[1,2,3,4,5]=> [5,1,2,3,4] K = 5 - 1
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp=0,rightNum;
    cin>>N>>K;
    if(K<=N-1){
        v.push_back(K+1);
        for(int i=1;i<N+1;i++){
            if(i==K+1){continue;}
            v.push_back(i);
        }
    }
    else{
        //1. rightNum-1보다 K가 큰 경우
        //2. rightNum을 배열 앞에 배치하고 셋에 삽입
        //3. K -= (rightNum--)-1
        //1을 만족하는 경우 1~3을 반복하고
        //아닌 경우 갱신된 K를 배열 앞에 배치하고 셋에 삽입
        rightNum = N;
        while(K>rightNum-1){
            K -= rightNum-1;
            v.push_back(rightNum);
            entry.insert(rightNum);
            rightNum--;
        }
        v.push_back(K+1);
        entry.insert(K+1);
        for(int i=1;i<N+1;i++){
            if(entry.find(i)!=entry.end()){continue;}
            v.push_back(i);
        }
    }
    for(int i=0;i<N;i++){cout<<v[i]<<' ';}
}
