//https://www.acmicpc.net/problem/11286
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> v;
int n;

struct cmp{
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.first == b.first ? a.second> b.second : a.first>b.first;
    }
};

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp){
            pq.push({abs(tmp),tmp});
        }
        else{
            if(pq.empty()){cout<<0<<'\n';}
            else{
                cout<<pq.top().second<<'\n';
                pq.pop();
            }
        }
    }
}
