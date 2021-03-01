//https://www.acmicpc.net/problem/5639
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> v;
stack<int> st;

//전위순회
//(루트,왼쪽서브트리(작은값),오른쪽서브트리(큰값)가 재귀적으로 출력)
//후위순회
//(왼쪽서브트리(작은값),오른쪽서브트리(큰값),루트가 재귀적으로 출력)
//1.(서브)트리의 맨 앞은 루트부분
//2.루트를 기준으로 큰값이 있는 위치 탐색하여 3부분으로 나눔
//3.왼쪽 서브트리와 오른쪽 서브트리 부분을 앞에 놓고 루트를 마지막에 출력
//(스택에 삽입)
//4.1~3을 재귀적으로 반복(루트->오른쪽 서브트리->왼쪽 서브트리)

void func(int root,int end){
    if(root>=end){return;}
    int val = v[root];
    int i;
    //오른쪽 서브트리 시작 위치 구하기
    for(i=root+1;i<end;i++){
        if(val<v[i]){
            st.push(val);
            func(i,end);//오른쪽 서브트리
            func(root+1,i);//왼쪽 서브트리
            return;
        }
    }
    //왼쪽 서브트리만 있는 경우
    st.push(val);
    func(root+1,i);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    while(cin>>tmp){v.push_back(tmp);}
    func(0,v.size());
    while(!st.empty()){
        cout<<st.top()<<'\n';
        st.pop();
    }
}
