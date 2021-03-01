//https://www.acmicpc.net/problem/1966
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int c,n,m;
queue<int> q;
vector<int> v;
vector<int> ans;

//n: 문서 갯수 m: 출력순서를 원하는 문서의 인덱스
int func(){
    int count = 0;
    while(!q.empty()){
        int tmp = q.front();
        //출력할 수 있는 문서인 경우
        if(tmp==v[v.size()-1]){
            if(m==0){return ++count;}
            else{
                ++count;
                q.pop();
                v.pop_back();
                m--;
            }
        }
        else{//출력 못하는 문서인 경우
            //m == 0이면 해당 문서가 대기줄 맨뒤로 배치
            //아닐 경우는 문서가 대기줄에서 한 칸 앞으로 이동
            m = m ? m-1: q.size()-1;
            q.push(tmp);
            q.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>n>>m;
        for(int j=0;j<n;j++){
            cin>>tmp;
            q.push(tmp);
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        ans.push_back(func());
        v.clear();
        while(!q.empty()){
            q.pop();
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }
}
