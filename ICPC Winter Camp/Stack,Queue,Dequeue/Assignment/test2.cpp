//https://www.acmicpc.net/problem/1935
#include<iostream>
#include<vector>
#include<string>
#include <stack>
using namespace std;

int n;
string str;
//알파벳에 해당하는 숫자 저장배열
vector<int> v;
//후위표기식
stack<double> st;

double func(){
    double a,b;
    for(int i=0;i<str.length();i++){
        //피연산자인 경우
        if((str[i]>'A'-1)&&(str[i]<'Z'+1)){
            st.push(v[str[i]-'A']);
        }
        //수식인 경우
        else{
            switch (str[i]) {
                case '*':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a*b);
                    break;
                case '/':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a/b);
                    break;
                case '+':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a+b);
                    break;
                case '-':
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    st.push(a-b);
                    break;
            }
        }
    }
    return st.top();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    //fixed 호출되는 소수점자리 설정
    double ans = func();
    cout<<fixed;
    cout.precision(2);
    cout<<ans<<'\n';
}
