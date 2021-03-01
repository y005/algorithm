//https://www.acmicpc.net/problem/1260
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n,m,s;
int edge[1001][1001];
int visited1[1001];
int visited2[1001];
vector<int> ans1;
vector<int> ans2;

void dfs(int current){
    visited1[current] = 1;
    ans1.push_back(current);
    for(int i=1;i<n+1;i++){
        if((!visited1[i])&&edge[current][i]){dfs(i);}
    }
}
void bfs(){
    queue<int> q;
    int tmp;
    q.push(s);
    visited2[s] = 1;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        ans2.push_back(tmp);
        for(int i=1;i<n+1;i++){
            if(edge[tmp][i]&&(!visited2[i])){
                visited2[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    dfs(s);
    bfs();
    for(int i=0;i<ans1.size();i++){cout<<ans1[i]<<' ';}
    cout<<'\n';
    for(int i=0;i<ans2.size();i++){cout<<ans2[i]<<' ';}
    cout<<'\n';
}
