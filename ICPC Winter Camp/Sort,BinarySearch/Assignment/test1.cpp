//https://www.acmicpc.net/problem/2750
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<'\n';
    }
}
