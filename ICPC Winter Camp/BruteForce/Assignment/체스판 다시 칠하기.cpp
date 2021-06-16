//https://www.acmicpc.net/problem/1018
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int m,n;
vector<string> v;

int func(){
    int method1,method2,Min;
    int ans = 64;
    char current = 'W';
    string tmp;
    for(int i=0;i<m-8+1;i++){
        for(int j=0;j<n-8+1;j++){
            method1 = 0;
            method2 = 0;
            for(int a=i;a<i+8;a++){
                for(int b=j;b<j+8;b++){
                    v[a][b] == current ? method2++ : method1++;
                    current = current == 'W'? 'B' : 'W';
                }
                current = current == 'W'? 'B' : 'W';
            }
            Min = min(method1,method2);
            ans = min(ans,Min);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tmp;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<func();
}
