//https://www.acmicpc.net/problem/4949
#include<iostream>
#include<vector>
#include<string>
#include <stack>
using namespace std;

vector<string> v;
//'(',')','[',']'
// 1, 2, 3, 4
bool func(int i){
    stack<int> st;
    for(int j=0;j<v[i].size();j++){
        switch (v[i][j]) {
            case '(':
                st.push(1);
                break;
            case '[':
                st.push(3);
                break;
            //stack에 맞는 오른쪽 괄호가 없는 경우 no
            case ')':
                if(st.empty()||st.top()!=1){return false;}
                else{
                    st.pop();
                    break;
                }
            case ']':
                if(st.empty()||st.top()!=3){return false;}
                else{
                    st.pop();
                    break;
                }
            }
        }
    return st.empty()? true : false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tmp;
    while(1){
        //띄어쓰기한 문장을 입력받을 때 사용
        getline(cin,tmp);
        if(tmp=="."){break;}
        v.push_back(tmp);
    }
    for(int i=0;i<v.size();i++){
        tmp = func(i) ? "yes" : "no";
        cout<<tmp<<'\n';
    }
}
