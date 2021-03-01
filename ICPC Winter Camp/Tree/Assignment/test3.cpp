//https://www.acmicpc.net/problem/1991
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
//자식 트리
int tree[26][2];
//'A'~'Z'를 0~25로 표현

//전위순회: 제일 먼저 방문
void preOrder(int v){
    char p = v +'A';
    cout<<p;
    if(tree[v][0]!=-1){preOrder(tree[v][0]);}
    if(tree[v][1]!=-1){preOrder(tree[v][1]);}
}
//중위순회: 2번쨰로 방문
void inOrder(int v){
    char p = v+'A';
    if(tree[v][0]!=-1){inOrder(tree[v][0]);}
    cout<<p;
    if(tree[v][1]!=-1){inOrder(tree[v][1]);}

}
//후위순회: 가장 늦게 방문
void postOrder(int v){
    char p = v+'A';
    if(tree[v][0]!=-1){postOrder(tree[v][0]);}
    if(tree[v][1]!=-1){postOrder(tree[v][1]);}
    cout<<p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char p,l,r;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p>>l>>r;
        tree[p-'A'][0] = l == '.' ? -1: l-'A';
        tree[p-'A'][1] = r == '.' ? -1: r-'A';
    }
    preOrder(0);
    cout<<'\n';
    inOrder(0);
    cout<<'\n';
    postOrder(0);
}
