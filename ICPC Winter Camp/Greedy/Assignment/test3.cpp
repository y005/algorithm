//https://www.acmicpc.net/problem/2847
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;

int function(){
    sort(v.begin(), v.end());
    int ans = 200001;
    for(int i=0;i<n;i++){
        ans = min(ans,v[i]+v[2*n-1-i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<function();
}
