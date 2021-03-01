//https://www.acmicpc.net/problem/1158
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,k;
vector<int> v;
vector<int> ans;

void func(){
    int count=0;
    int idx=-1;
    while(count<n){
        for(int i=0;i<k;i++){
            idx = (idx+1)%n;
            if(!v[idx]){i--;}
        }
        ans.push_back(v[idx]);
        v[idx] = 0;
        ++count;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    func();
    cout<<"<";
    for(int i=0;i<ans.size();i++){
        if(i==n-1){cout<<ans[i]<<">";}
        else{cout<<ans[i]<<", ";}
    }
}
