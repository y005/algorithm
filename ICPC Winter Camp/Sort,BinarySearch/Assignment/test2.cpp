//https://www.acmicpc.net/problem/11931
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int v[1000000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v[i] = tmp;
    }
    sort(v,v+n);
    for(int i=n-1;i>-1;i--){
        cout<<v[i]<<'\n';
    }
}
