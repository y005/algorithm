//https://www.acmicpc.net/problem/20046
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int m,n;
//건설 비용정보
int arr[1001][1001];
//시작점에서 드는 비용 정보
int cost[1001][1001];
//first 시작점에서 해당 정점까지 비용
//second 해당 정점 좌표
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

void func(){
    pair<int,pair<int,int>> cur;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        if(cur.first>cost[cur.second.first][cur.second.second]){continue;}
        //주변 정점인 위아래 한칸 주변 기준으로 cost값 완화 여부 확인
        for(int x=cur.second.first-1;x<=min(m,cur.second.first+1);x++){
            if(x<1){continue;}
            for(int y=cur.second.second-1;y<=min(n,cur.second.second+1);y++){
                if(y<1){continue;}
                if(abs(x-cur.second.first)==abs(y-cur.second.second)){continue;}
                if(arr[x][y]==-1){continue;}
                if(cost[x][y]>arr[x][y]+cost[cur.second.first][cur.second.second]){
                    cost[x][y] = arr[x][y]+cost[cur.second.first][cur.second.second];
                    pq.push({cost[x][y],{x,y}});
                }
            }
        }
    }
    if(cost[m][n]==2147483647){cout<<-1;return;}
    cout<<cost[m][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>m>>n;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>tmp;
            arr[i][j] = tmp;
            cost[i][j] = 2147483647;
        }
    }
    //시작할 때 부터 도로를 건설 못하는 예외 생각!!
    if(arr[1][1]==-1){cout<<-1;return 0;}
    cost[1][1] = arr[1][1];
    pq.push({arr[1][1],{1,1}});
    func();
}
