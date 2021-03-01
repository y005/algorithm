//https://www.acmicpc.net/problem/1916
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int n,m,start,arrive;
//first 인근 정점 번호
//second 경로 가중치
vector<pair<int,int>> edge[1001];
//first 시작점에서 도착 정점까지 최단 길이
//second 도착 정점 번호
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int cost[1001];
//cost를 기준으로 우선순위 큐에 삽입
//cost값이 갱신되는 것도 큐에서 다시 반영해야 함
void func(){
    pair<int,int> current;
    while(!pq.empty()){
        //cost값이 제일 작은 정점 방문
        //current.first = 해당 정점에 대한 cost값
        //current.second = 정점 번호
        current = pq.top();
        pq.pop();
        //어떤 정점에 대한 cost값이 여러번 단축되는 경우 우선순위
        //큐 안에 해당 정점이 중복으로 있을 수 있어 최단거리를
        //기준으로 먼저 실행함
        if(current.first>cost[current.second]){continue;}
        //방문 정점에서 인근 정점의 cost값 새로 단축이 가능한지 확인
        for(int i = 0;i<edge[current.second].size();i++){
            if(cost[edge[current.second][i].first]>edge[current.second][i].second+current.first){
                cost[edge[current.second][i].first] = edge[current.second][i].second+current.first;
                pq.push({edge[current.second][i].second+current.first,edge[current.second][i].first});
            }
        }
    }
    cout<<cost[arrive];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        edge[x].push_back({y,w});
    }
    cin>>start>>arrive;
    for(int i=1;i<n+1;i++){
        cost[i] = 2147483647;
    }
    cost[start] = 0;
    pq.push({0,start});
    func();
}
