//https://www.acmicpc.net/problem/2002
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n,ans;
map<string,int> in;
vector<string> out;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>n;
    //들어온 차
    for(int i=0;i<n;i++){
        cin>>str;
        in.insert({str,i});
    }
    //나간 차
    for(int i=0;i<n;i++){
        cin>>str;
        out.push_back(str);
    }
    //자신의 차량보다 늦게 나온 차량 중에 나보다
    //먼저 들어온 경우 추월했기 때문에
    //해당 차량은 추월 차량
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(in[out[i]]>in[out[j]]){ans++;break;}
        }
    }
    cout<<ans;
}
