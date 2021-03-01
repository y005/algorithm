//https://www.acmicpc.net/problem/1967
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int maxVal = -1;
int u;
vector<pair<int,int>> v[10001];
//v[parent].first = adj;
//v[parent].second = weight

void func(int current,int prev,int w){
    if(maxVal<w){
        u = current;
        maxVal = w;
    }
    for(int i=0;i<v[current].size();i++){
        //이전 점으로 다시 돌아가는 경우는 제외 
        if(prev!=v[current][i].first){
            func(v[current][i].first,current,w+v[current][i].second);
        }
    }
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
    func(1,0,0);
    maxVal = -1;
    func(u,0,0);
    //아까 찾은 점에서 최대 거리 출력
    cout<<maxVal;
}
