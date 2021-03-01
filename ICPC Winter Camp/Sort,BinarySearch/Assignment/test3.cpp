//https://www.acmicpc.net/problem/1920
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n,m;
set<int> v1;
vector<int> v2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v1.insert(tmp);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        v2.push_back(tmp);
    }
    int result;
    for(int i=0;i<m;i++){
        result = v1.find(v2[i]) != v1.end() ? 1 : 0;
        cout<<result<<'\n';
    }
}
