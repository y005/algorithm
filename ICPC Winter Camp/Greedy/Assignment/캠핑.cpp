//https://www.acmicpc.net/problem/4796
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a,b,c;
std::vector<int> v;

int func(){
    return c/b*a+min(c%b,a);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=0;
    bool flag=true;
    while(flag){
        cin>>a>>b>>c;
        if((a|b|c)==0){break;}
        v.push_back(func());
        n++;
    }
    for(int i=0;i<n;i++){
        cout<<"Case "<<i+1<<": "<<v[i]<<endl;
    }
}
