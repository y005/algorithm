//https://www.acmicpc.net/problem/15649
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a,b;
vector<int> v;
vector<int> tmp;

void func(int m){
    if(m==b){
        for(int j=0;j<b;j++){
            cout<<v[j]+1<<" ";
        }
        cout<< '\n';
        return;
    }
    for(int i=0;i<a;i++){
        if(tmp[i]==0){
            tmp[i]=1;
            v.push_back(i);
            func(m+1);
            v.pop_back();
            tmp[i]=0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(int i=0;i<a;i++){tmp.push_back(0);}
    func(0);
}
