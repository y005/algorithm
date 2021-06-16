//https://www.acmicpc.net/problem/2748
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
long long fibo[2] = {0,1};

long long func(){
    if(n==0||n==1){return n;}
    int m = 2;
    while(m<n+1){
        fibo[m%2] = fibo[0]+fibo[1];
        m++;
    }
    return fibo[(m-1)%2];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cout<<func();
}
