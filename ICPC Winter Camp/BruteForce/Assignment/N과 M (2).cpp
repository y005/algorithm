//https://www.acmicpc.net/problem/15650
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a,b;
//선택한 숫자 저장 배열
vector<int> v;

void func(int n,int m){
    if(m==b){
        for(int j=0;j<b;j++){
            cout<<v[j]+1<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=n;i<a;i++){
        v.push_back(i);
        func(i+1,m+1);
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    func(0,0);
}
