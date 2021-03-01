#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include <map>
#include <string>
#define pis pair<int,string>
using namespace std;

int n,m;
//횟수 저장을 위한 배열
map<string,int> map1;
//정렬을 위한 배열
vector<pis> v;
//중복 확인
vector<string> check;
struct cmp{
    bool operator()(pis a,pis b){
        //빈도 큰거 먼저
        if(a.first!=b.first){return a.first > b.first;}
        //단어 길이
        if(a.second.length()!=b.second.length()){
            return a.second.length()>b.second.length();
        }
        return a.second < b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp.length()<m){continue;}
        if(map1.empty()){map1.insert({tmp,0});continue;}
        if(map1.find(tmp) != map1.end()){
            map1[tmp] += 1;
            continue;
        }
        map1.insert({tmp,0});
    }
    for(auto idx = map1.begin();idx!=map1.end();idx++){
        v.push_back({idx->second,idx->first});
    }
    sort(v.begin(),v.end(),cmp());
    for(int i=0;i<v.size();i++){cout<<v[i].second<<'\n';}
}
