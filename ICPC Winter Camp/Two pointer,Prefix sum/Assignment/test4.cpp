//https://www.acmicpc.net/problem/1484
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int G;
vector<long long> v;
vector<long long> ans;

void func(){
    long long tmp;
    vector<long long>::iterator b = lower_bound(v.begin(),v.end(),G);
    vector<long long>::iterator a = v.begin();
    while(b!=v.end()){
        tmp = (*b)-(*a);
        if(tmp>G){a++;}
        if(tmp<=G){
            if(tmp==G){ans.push_back(*b);}
            b++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>G;
    for(long long i=0;i<50000;i++){
        v.push_back((i+1)*(i+1));
    }
    func();
    if(ans.size()<1){
        cout<<-1<<'\n';
    }
    for(long long i=0;i<ans.size();i++){
        cout<<sqrt(ans[i])<<'\n';
    }
}
