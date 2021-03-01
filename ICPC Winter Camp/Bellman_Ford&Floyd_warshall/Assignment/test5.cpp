//https://www.acmicpc.net/problem/11404
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#define INF 2147483647

using namespace std;

int n,m;
//cost[i][j]는 i,j 간의 최단거리 값
long long cost[101][101];

void func(){
    //k를 경유한 i,j간의 최단 거리 갱신
    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if((cost[i][k]!=INF) && (cost[k][j] !=INF)){
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(cost[i][j]==INF||cost[i][j]==0){cout<<0<<" ";}
            else{cout<<cost[i][j]<<" ";}
        }
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s,e;
    long long c;
    cin>>n>>m;

    //거리간 버스 비용 상태로 초기화
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i==j){cost[i][j]=0;continue;}
            cost[i][j] = INF;
        }
    }
    //노선 버스 비용 정보 추가
    for(int i=0;i<m;i++){
        cin>>s>>e>>c;
        //같은 노선인 버스가 하나가 아닐 수 있음
        //같은 출발-도착 비용 중 작은 비용을 채택
        if((cost[s][e]!=0)&&(cost[s][e]!=INF)){
            cost[s][e] = min(cost[s][e],c);
            continue;
        }
        cost[s][e] = c;
    }
    func();
}
