//https://www.acmicpc.net/problem/1068
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,erase;
vector<int> tree[50];
int ans;
//n번째 배열에는 자신의 자식번호들이 저장

//고려해야하는 상황
//1. 루트노드를 지우는 경우 고려
//2. 루트 노드가 0이 아닐 경우 고려
//3. 리프노드가 새롭게 생기는 경우 고려
void func(int current){
    if(tree[current].empty()){ans++;return;}
    for(int i=0;i<tree[current].size();i++){
        if(tree[current][i]==erase){
            if(tree[current].size()==1){ans++;}
            continue;
        }
        func(tree[current][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    int start;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==-1){start = i;continue;}
        tree[tmp].push_back(i);
    }
    cin>>erase;
    if(erase==start){cout<<0<<'\n'; return 0;}
    func(start);
    cout<<ans;
}
