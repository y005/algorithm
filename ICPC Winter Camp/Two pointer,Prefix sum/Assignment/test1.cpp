//https://www.acmicpc.net/problem/11659
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>m;
    vector<long long> v(n+1);
    for(int i=1;i<n+1;i++){
        cin>>tmp;
        v[i] = v[i-1]+tmp;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<'\n';
    }
}
