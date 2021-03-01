//https://www.acmicpc.net/problem/1463
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int ans[1000000];

int func(){
    if(n<4){return ans[n];}
    for(int i=4;i<n+1;i++){
        ans[i] = 1 + min({ans[i-1],ans[(!(i%2))*(i/2)],ans[(!(i%3))*(i/3)]});
    }
    return ans[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ans[0] = 99;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    cout<<func();
}
