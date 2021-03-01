//https://www.acmicpc.net/problem/1389
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#define INF 2147483647
#define pii pair<int,int>
using namespace std;

int n,m;
//dp[i][j]는 i,j 간의 케빈 베이컨 값
int dp[101][101];
//주변 지인들간의 케빈 베이컨의 합 저장
//케빈 베이컨 합, 사람번호
vector<pii> bacon;

void func(){
    //k를 경유한 i,j간의 최단 거리 갱신
    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if((dp[i][k]!=INF) && (dp[k][j] !=INF)){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
    }
    for(int i=1;i<n+1;i++){
        int sum=0;
        for(int j=1;j<n+1;j++){
            sum += dp[i][j];
        }
        bacon.push_back({sum,i});
    }
    sort(bacon.begin(),bacon.end());
    cout<<bacon[0].second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>n>>m;
    //연결되어 있지 않는 상태로 갱신
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i==j){dp[i][j]=0;}
            dp[i][j] = INF;
        }
    }
    //친구 관계 갱신
    for(int i=0;i<m;i++){
        cin>>a>>b;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    //dp[i][j]의 합이 제일 작은 적은 번호 수 출력
    func();
}
