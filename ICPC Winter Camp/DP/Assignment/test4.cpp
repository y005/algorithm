//https://www.acmicpc.net/problem/1757
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
vector<int> v;
int ans[10001][501];
//ans[a][b] = a분 동안 지침지수 b일 때 달릴 수 있는 최대거리
//한 번 쉬게 되면 지침지수가 0이 될 때까지 쉬는 것이 포인트!
//인덱스를 동일하게 해서 헷갈리지 않는 것이 중요
int func(){
    ans[1][1] = v[1];
    for(int i=2;i<n+1;i++){
        for(int j=0;j<min(i+1,m+1);j++){//i와 m 중에 더 작은 수까지의 지침지수만 존재함
            if(j==0){
                //이전까지 지침지수가 0인데 또 쉬는 경우
                int localMax = ans[i-1][0];
                //ans[i][0] = i-k분 일때 지침지수가 k이고 k분 동안 쉬는 경우들 중 최대거리를 선정
                for(int k=1;(k<m+1)&&(i-k>0);k++){
                    localMax = max(localMax,ans[i-k][k]);
                }
                ans[i][0] = localMax;
            }
            else{
                //지침지수가 0이 아닌 경우 이 전까지 달리고 또 달린 경우만 존재
                ans[i][j] = ans[i-1][j-1]+v[i];
            }
        }
    }
    return ans[n][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>m;
    v.push_back(0);
    for(int i=1;i<n+1;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<func();
}
