//https://www.acmicpc.net/problem/1003
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

int n,val=-1;
vector<int> v;
pii fibo[41];

void func(){
    fibo[0] = {1,0};
    fibo[1] = {0,1};
    for(int i=2;i<val+1;i++){
        fibo[i].first += fibo[i-1].first+fibo[i-2].first;
        fibo[i].second += fibo[i-1].second+fibo[i-2].second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
        val = max(val,tmp);
    }
    func();
    for(int i=0;i<v.size();i++){
        cout<<fibo[v[i]].first<<" "<<fibo[v[i]].second<<"\n";
    }
}
