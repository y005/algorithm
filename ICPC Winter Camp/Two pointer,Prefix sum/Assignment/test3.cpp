//https://www.acmicpc.net/problem/2003
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long m;
int n;
vector<int> v;

long long func(){
    long long ans=0;
    int a=0;
    int b=-1;
    long long sum=0;
    while(b<n){
        if(sum<m){sum += v[++b];}
        else{
            if(sum==m){
                ans++;
                sum += v[++b];
            }
            else{
                sum -= v[a++];
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<func();
}
