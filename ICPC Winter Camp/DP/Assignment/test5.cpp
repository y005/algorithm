//https://www.acmicpc.net/problem/20500
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
long long v[1516][3];

//15의 배수 == 3의 배수 & 5의 배수
//f(a,b) = 5로 끝나는 a자리의 수
//         각 자리의 수 합%3 == b인 수의 갯수
//f(N,0) = 1(N번 자리에 5가 오는 경우) X f(N-1,1) + 1(N번 자리에 1이 오는 경우) X f(N-1,2)
//f(N,1) = 1(N번 자리에 1이 오는 경우) X f(N-1,0) + 1(N번 자리에 5이 오는 경우) X f(N-1,2)
//f(N,2) = 1(N번 자리에 1이 오는 경우) X f(N-1,1) + 1*(N번 자리에 5이 오는 경우) Xf(N-1,0)

long long func(){
    for(int i=3;i<n+1;i++){
        v[i][0] = (v[i-1][1]+v[i-1][2])%1000000007;
        v[i][1] = (v[i-1][0]+v[i-1][2])%1000000007;
        v[i][2] = (v[i-1][1]+v[i-1][0])%1000000007;
    }
    return v[n][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    v[2][0] = 1;
    v[2][1] = 1;
    cout<<func();
}
