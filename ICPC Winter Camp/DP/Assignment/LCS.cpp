//https://www.acmicpc.net/problem/9251
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
string a,b;
int ans[1000][1000];
//각각 i-1,j-1부터 시작하는 최대 공통 문자열길이
int func(int i,int j){
    if((i==a.length()) || (j==b.length())){return 0;}
    int& ret= ans[i][j];
    if(ret!=-1){return ret;}
    if(a[i]==b[j]){ret = func(i+1,j+1)+1;}
    else{ret = max(func(i+1,j),func(i,j+1));}
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    memset(ans, -1, sizeof(ans));
    cout<<func(0,0);
}
