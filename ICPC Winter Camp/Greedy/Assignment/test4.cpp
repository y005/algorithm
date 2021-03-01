//https://www.acmicpc.net/problem/1931
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector< pair <int, int> > v;

int func(void){
    int count = 0;
    int current = -1;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(current > v[i].second){
            continue;
        }
        else{
            current = v[i].first;
            count++;
        }
    }
    return count;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s,e;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        v.push_back(pair<int,int>(e,s));
    }
    cout<<func();
}
