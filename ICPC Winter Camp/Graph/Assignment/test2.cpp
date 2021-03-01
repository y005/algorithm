//https://www.acmicpc.net/problem/16953
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
long long A,B;

long long func(){
    queue<pair<long long, int>> q;
    pair<long long, int> tmp;
    q.push(make_pair(A,1));
    while(!q.empty()){
        tmp = q.front();
        if(tmp.first == B){break;}
        q.pop();
        if(B>=2*tmp.first){q.push(make_pair(2*tmp.first,tmp.second+1));}
        if(B>=10*tmp.first+1){q.push(make_pair(10*tmp.first+1,tmp.second+1));}
    }
    if(q.empty()){return -1;}
    return q.front().second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    cout<<func()<<"\n";
}
