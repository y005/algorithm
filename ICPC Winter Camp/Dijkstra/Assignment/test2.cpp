//https://www.acmicpc.net/problem/11000
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int n;

//일찍 끝나는 수업 순서로 정렬
//종료 시간이 같은 경우 시작 시간이
//늦은 수업을 우선 순위로 정렬
struct cmp{
    bool operator()(int a,int b){
        return a > b;
    }
};
//각 강의실에서 제일 늦은 수업의 수업 종료 시간이 오름차순으로 저장됨
priority_queue<int,vector<int>,cmp> pq1;
//수업하는 강의의 시간 정보 배열로 시작시간 기준으로 오름차순 정렬
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int func(){
    pq1.push(pq.top().second);
    pq.pop();
    while(!pq.empty()){
        //넣을려는 수업의 추가 강의실 필요 여부 체크
        //확인해야 하는 강의실도 끝나는 시간이 제일 빠른 시간 먼저 확인
        //해당 강의실에 종료한 뒤에 강의가 시작하는 경우
        //강의실에 강의를 넣는 것이 가능
        if(pq1.top()<=pq.top().first){
                pq1.pop();
                pq1.push(pq.top().second);
                pq.pop();
        }
        //현재 보유한 강의실들에서 강의를 하지 못하는 경우
        else{
            pq1.push(pq.top().second);
            pq.pop();
        }
    }
    return pq1.size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s,e;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        pq.push({s,e});
    }
    cout<<func();
}
