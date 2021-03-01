//https://www.acmicpc.net/problem/1697
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
long long N,K;
//이 전에도 방문한 적이 있는 지 확인
int visited[100001];
//현재 위치가 이전에도 방문한 위치였다면
//현재 위치에서 목표에 도착하게 될 시간은
//이전에 현재 위치에서 목표로 가서 도착하
//게 된 시간보다 느리기 때문에 큐에서 제외

long long func(){
    queue<pair<long long, int>> q;
    pair<long long, int> tmp;
    long long num;
    q.push(make_pair(N,0));
    while(!q.empty()){
        tmp = q.front();
        if(tmp.first == K){break;}
        q.pop();
        num = 2*tmp.first;
        if((0<=num)&&(num<=100000)){
            if(!visited[num]){
                q.push(make_pair(num,tmp.second+1));
                visited[num] = 1;
            }
        }
        num = tmp.first-1;
        if((0<=num)&&(num<=100000)){
            if(!visited[num]){
                q.push(make_pair(num,tmp.second+1));
                visited[num] = 1;
            }
        }
        num = tmp.first+1;
        if((0<=num)&&(num<=100000)){
            if(!visited[num]){
                q.push(make_pair(num,tmp.second+1));
                visited[num] = 1;
            }
        }
    }
    if(q.empty()){return -1;}
    return q.front().second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    cout<<func()<<"\n";
}
