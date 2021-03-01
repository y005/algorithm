//https://www.acmicpc.net/problem/1865
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//테스트케이스의 수
int tc;
//테스트케이스의 정점갯수,양수가중치 간선,음수가중치 간선 갯수
pair<int,pair<int,int>> setting[5];
//간선 시작점,도착점,경과시간
vector<pair<int,pair<int,int>>> road[5];
//시간 저장 배열
long long time[5][501];

void func(int i){
    //두 개 이상의 컴포넌트 예외를 처리하기 위해서는
    //1. 모든 정점을 출발점으로 조사해서 cycle의 유무를 확인
    //2. 이 알고리즘에서 cycle의 형성 유무에 대해서만 생각
    //이 중 1은 시간이 오래 걸리고 2의 경우 INF처리된 정점은
    //그냥 지나치면 다른 컴포넌트에 대한 완화 작업을 통한 음수
    //사이클 확인이 불가능해지기 때문에 이 문제의 경우 INF에도
    //완화를 시킬 수 있도록 해야함(초기값 INF 설정 X)

    //원하는 문제의 답은 사이클 유무확인 만이기 때문에 가능

    for(int j=1;j<setting[i].first;j++){
        //정점 갯수-1만큼 완화
        for(int k=0;k<road[i].size();k++){
            //해당 간선의 도착점이 완화가능하면 완화함
            if(time[i][road[i][k].second.first]> time[i][road[i][k].first]+road[i][k].second.second){
                time[i][road[i][k].second.first] = time[i][road[i][k].first]+road[i][k].second.second;
            }
        }
    }
    for(int k=0;k<road[i].size();k++){
        //해당 간선의 도착점이 완화가능하면 완화함
        if(time[i][road[i][k].second.first]> time[i][road[i][k].first]+road[i][k].second.second){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,w,s,e,t;
    cin>>tc;
    for(int i=0;i<tc;i++){
        cin>>n>>m>>w;
        setting[i] = {n,{m,w}};
        //양수 가중치 간선 입력
        //도로의 경우 양 방향으로 된 점 주의
        for(int j=0;j<m;j++){
            cin>>s>>e>>t;
            road[i].push_back({s,{e,t}});
            road[i].push_back({e,{s,t}});
        }
        //음수 가중치 간선 입력
        for(int j=0;j<w;j++){
            cin>>s>>e>>t;
            road[i].push_back({s,{e,-t}});
        }
    }
    for(int i=0;i<tc;i++){
        //시작점 기준으로 정렬
        func(i);
    }
}
