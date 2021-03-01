//https://www.acmicpc.net/problem/19538
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

long long n,m;
vector<vector<long long>> adj;//주변 지인 정보
vector<long long> rumor;//루머를 현재 믿는 사람 목록
long long time[200001];//루머를 믿게 된 시간 저장
long long cnt[200001];//주변 지인들 중 루머를 믿는 사람 갯수 저장

void func(){
    queue<long long> q;//새로 루머를 믿은 사람 리스트
    vector<long long> v;//새로 루머를 믿은 사람들의 지인(추가로 루머를 믿게 될 가능성 있는 사람 리스트)
    long long currentTime = 0;
    //최초 유포자들을 큐에 삽입
    for(long long i=0;i<rumor.size();i++){
        q.push(rumor[i]);
    }
    while(!q.empty()){
        currentTime++;
        while(!q.empty()){
            //새롭게 루머를 믿은 사람들의 주변 지인 count업데이트
            for(long long i=0;i<adj[q.front()].size();i++){
                cnt[adj[q.front()][i]]++;
                //루머를 안 믿는 사람들 중에서만 업데이트
                if(time[adj[q.front()][i]]==-1){
                    v.push_back(adj[q.front()][i]);
                }
            }
            q.pop();
        }
        //주변 지인들 중 새롭게 루머를 믿게 된 사람들
        //큐 삽입, 믿는 시간 기록, 루머믿는 목록 추가
        for(long long i=0;i<v.size();i++){
            //중복되는 이웃을 검사하지 않고 스킵 
            if(time[v[i]]!=-1){continue;}
            long long tmp = adj[v[i]].size()%2 ? adj[v[i]].size()/2+1 : adj[v[i]].size()/2;
            if(cnt[v[i]]>= tmp){
                q.push(v[i]);
                time[v[i]] = currentTime;
                rumor.push_back(v[i]);
            }
        }
        v.clear();
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tmp;
    vector<long long> v1;
    adj.push_back(v1);
    cin>>n;
    for(long long i=1;i<n+1;i++){
        while(1){
            cin>>tmp;
            if(!tmp){break;}
            v1.push_back(tmp);
        }
        adj.push_back(v1);
        v1.clear();
    }
    for(long long i=1;i<n+1;i++){time[i] = -1;}
    cin>>m;
    for(long long i=0;i<m;i++){
        cin>>tmp;
        rumor.push_back(tmp);
        time[tmp] = 0;
    }
    func();
    for(long long i=1;i<n+1;i++){
        cout<<time[i]<<' ';
    }
}
