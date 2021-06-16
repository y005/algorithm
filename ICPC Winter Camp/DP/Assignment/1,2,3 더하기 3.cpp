//https://www.acmicpc.net/problem/15988
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;
long long ans[1000000+1];

long long func(int m){
    if(m<4){return ans[m];}
    for(int i=4;i<m+1;i++){
        ans[i] = (ans[i-1]+ans[i-2]+ans[i-3])%1000000009;
    }
    return ans[m];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cout<<func(v[i])<<'\n';
    }
}
