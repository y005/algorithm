//https://www.acmicpc.net/problem/11403
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#define INF 2147483647
#define pii pair<int,int>
using namespace std;

int n;
//dp[i][j]는 i,j 간의 최단거리 값
int dp[101][101];

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
        for(int j=1;j<n+1;j++){
            if(dp[i][j]==INF||dp[i][j]==0){cout<<0<<" ";}
            else{cout<<1<<" ";}
        }
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    //연결된 상태로 갱신
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>tmp;
            if(i==j){dp[i][j]=0;}
            dp[i][j] = tmp? tmp:INF;
        }
    }
    func();
}
