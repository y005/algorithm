//https://www.acmicpc.net/problem/5829
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n,m;
long long k;
vector<char> seq;
int adj[1001][2];
long long time[1001];
//몇번째 순회 중에 해당 정점에 도착했는 지 기록
//1번 순회 = M번 이동
int func(){
    int current=1;//현재 위치
    long long plus = 0;//추가로 몇 번 순회해야하는지
    time[current]= 1;//몇 번 순회시 방문했는지 표시
    for(long long i=0;i<k;i++){
        //M번의 이동
        for(int j=0;j<m;j++){
            current = seq[j]=='L' ? adj[current][0]:adj[current][1];
        }
        //1번 순회해서 도착한 점이 이전에 방문했던 점이 아니면 기록
        if(!time[current]){time[current] = i+1;continue;}
        //이전에 방문한 점이었으면 사이클이 몇번 순회 시 나오는지 기록
        plus = (k-i-1) % (i+1-time[current]);
        //나눈 나머지 만큼은 직접 이동하여 확인
        for(long long a=0;a<plus;a++){
            for(int j=0;j<m;j++){
                current = seq[j]=='L' ? adj[current][0]:adj[current][1];
            }
        }
        return current;
    }
    return current;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int left,right;
    char tmp;
    cin>>n>>m>>k;
    for(int i=1;i<n+1;i++){
        cin>>left>>right;
        adj[i][0] = left;
        adj[i][1] = right;
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        seq.push_back(tmp);
    }
    cout<<func();
}
