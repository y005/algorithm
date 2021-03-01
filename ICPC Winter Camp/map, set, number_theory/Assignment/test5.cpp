//https://www.acmicpc.net/problem/14490
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//유클리드 호제법 사용
//최대공약수 구하기

int n,m;
//int func(int a,int b){
//    if(!(a%b)){return b;}
//    else{return func(b,a%b);}
//}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char a;
    cin>>n>>a>>m;
    //int ans = n>m? func(n,m):func(m,n);
    int tmp;
    int big = n>m? n : m;
    int small = big==n? m : n;
    while(big%small){
        tmp = small;
        small = big%small;
        big = tmp;
    }
    cout<<n/small<<":"<<m/small;
    return 0;
}
