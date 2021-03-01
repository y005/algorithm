//https://www.acmicpc.net/problem/11725
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n;
//정점들 간 이웃 관계 저장
vector<int> node[100001];
//자기 자신의 부모 노드 번호 저장
int parent[100001];
//방문 기록
int visited[100001];

//트리는 1번 노드를 루트로 시작
void func(void){
    stack<int> st;
    st.push(1);
    int current;
    while(!st.empty()){
        current = st.top();
        st.pop();
        for(int i=0;i<node[current].size();i++){
            if(!visited[node[current][i]]){
                visited[node[current][i]] = 1;
                parent[node[current][i]] = current;
                st.push(node[current][i]);
            }
        }
    }
    for(int i=2;i<n+1;i++){
        cout<<parent[i]<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    func();
}
