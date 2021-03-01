//https://www.acmicpc.net/problem/4358
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n;
map<string,int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    while(!cin.eof()){
        getline(cin,str);
        if(str==""){break;}
        if(m.find(str)!=m.end()){
            m[str]++;
            n++;
            continue;
        }
        m.insert({str,1});
        n++;
    }
    cout<<fixed;
    cout.precision(4);
    map<string,int>::iterator iter;
    for(iter = m.begin();iter!=m.end();iter++){
        cout<<iter->first<<" " << (double)iter->second/n*100<<'\n';
    }
}
