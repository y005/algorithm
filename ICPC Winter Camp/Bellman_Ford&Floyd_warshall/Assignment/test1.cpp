//https://www.acmicpc.net/problem/11657
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int n,m;
//간선의 출발점,도착지점,노선 시간 저장
vector<pair<int,int>> v[501];
//시작 정점에서 도달하는 최단 시간 저장
long long time[501];
//long으로 최단 시간을 저장하면 time값이
//음수 가중치를 계속 만나는 경우 underfl
//ow로 낮은 값으로 갱신이 되어 음수 사이
//클 확인에서 추가적인 relax를 감지못해
//제대로된 음수 사이클 확인을 못함

//벨만 포드 원리
//모든 간선에 대한 완화를 x번 반복하여 완화하면
//x번 이하의 간선을 사용하는 최단 거리를 구함
//v정점에 대해서 v-1번의 반복

void func(){
    //v-1번 반복
    for(int i=1;i<n;i++){
        for(int j=1;j<n+1;j++){
            //한번이라도 방문한 적이 있는 정점인지 확인
            if(time[j]==2147483647){continue;}
            //해당 시작점에서 출발하는 도착정점에 대한 완화
            for(int k=0;k<v[j].size();k++){
                if(time[v[j][k].first]>v[j][k].second+time[j]){
                    time[v[j][k].first] = v[j][k].second+time[j];
                }
            }
        }
    }
    for(int j=1;j<n+1;j++){
        //한번이라도 방문한 적이 있는 정점인지 확인
        if(time[j]==2147483647){continue;}
        //해당 시작점에서 출발하는 도착정점에 대한 완화
        for(int k=0;k<v[j].size();k++){
            if(time[v[j][k].first]>v[j][k].second+time[j]){
                cout<<-1<<'\n';
                return;
            }
        }
    }
    for(int i=2;i<n+1;i++){
        if(time[i]==2147483647){cout<<-1<<'\n';continue;}
        cout<<time[i]<<'\n';
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s,e,w;
    cin>>n>>m;
    for(int i=1;i<m+1;i++){
        cin>>s>>e>>w;
        v[s].push_back({e,w});
    }
    for(int i=1;i<n+1;i++){time[i]=2147483647;}
    //예외처리 필수
    time[1] = 0;
    func();
}
