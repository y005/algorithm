//https://www.acmicpc.net/problem/13904
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,d,w,maxVal;
vector<pair<int,int>> v;

int func(){
    int tmp,score=0;
    int* schedule = new int[maxVal+1];
    for(int i=0;i<maxVal+1;i++){schedule[i] = 0;}
    for(int i=0;i<n;i++){
        tmp = v[i].second;
        while(schedule[tmp]!=0){--tmp;}
        if(tmp>=1){
            schedule[tmp] = 1;
            score += -v[i].first;
        }
    }
    return score;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d>>w;
        maxVal = max(maxVal,d);
        v.push_back({-w,d});
    }
    sort(v.begin(),v.end());
    cout<<func();
    return 0;
}
