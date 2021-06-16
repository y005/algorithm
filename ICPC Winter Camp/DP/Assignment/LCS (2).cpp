//https://www.acmicpc.net/problem/9251
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
string a,b;
int ans[1000][1000];
//각각 i,j번째에서 끝나는 문자열들의 최대 공통 문자열길이
int func(){
    ans[0][0] = a[0]==b[0];
    for(int i=1;i<a.length();i++){
        //i,0번째에서 끝나는 문자열들의 최대 공통 문자열길이
        ans[i][0] = max(ans[i-1][0],(int)(a[i]==b[0]));
    }
    for(int j=1;j<b.length();j++){
        ans[0][j] = max(ans[0][j-1],(int)(a[0]==b[j]));
    }
    for(int i=1;i<a.length();i++){
        for(int j=1;j<b.length();j++){
            if(a[i]==b[j]){ans[i][j] = ans[i-1][j-1]+1;}
            else{ans[i][j] = max(ans[i][j-1],ans[i-1][j]);}
        }
    }
    return ans[a.length()-1][b.length()-1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    cout<<func();
}
