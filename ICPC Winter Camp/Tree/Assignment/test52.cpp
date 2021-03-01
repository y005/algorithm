//https://www.acmicpc.net/problem/1967
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int visited[10001];
int post[10001];
int idx= -1;
vector<pair<int,int>> v[10001];
//v[parent].first = adj;
//v[parent].second = weight

int func(int current){
    int tmp;
    int maxVal = -1;
    if((idx!=current)&&v[current].size()==1){return 0;}
    for(int i=0;i<v[current].size();i++){
        if(!visited[v[current][i].first]){
            visited[v[current][i].first] = 1;
            tmp = v[current][i].second+func(v[current][i].first);
            if(maxVal<tmp){
                post[current]= v[current][i].first;
                maxVal = tmp;
            }
        }
    }
    return maxVal;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    //임의의 정점과 거리가 먼 점 찾기
    visited[1] = 1;
    func(1);
    idx=1;
    //가장 거리가 먼 점 찾기
    while(post[idx]){idx = post[idx];}
    //아까 찾은 점에서 최대 거리 출력
    //시작하는 리프노드는 예외 리턴문에서 제외!!
    for(int i=1;i<n+1;i++){visited[i] = 0;}
    visited[idx] = 1;
    cout<<func(idx);
}
