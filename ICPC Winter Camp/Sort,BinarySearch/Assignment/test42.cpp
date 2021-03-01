//https://www.acmicpc.net/problem/3079
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n,m;
vector< pair<long long,long long > > v;

long long find_upper(long long pivot){
    long long idx,mid;
    long long left = 0;
    long long right = v.size()-1;

    while(left<right){
        mid = (left+right)/2;
        if(v[mid].second<pivot){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    for(idx=mid;idx<n;idx++){
        if(v[idx].second>pivot){break;}
    }
    return idx;
}

bool cmpSecond(pair<long long,long long> a,pair<long long,long long> b) {
    return a.second < b.second ? true : false;
}

long long func(){
    sort(v.begin(),v.end(),cmpSecond);
    long long tmp = 0;
    long long add = v[0].first;
    long long pivot = v[0].first;
    long long idx;
    while(m>tmp){
        idx = find_upper(pivot);//pivot보다 큰 idx 반
        for(long long i=idx-1;(i>-1)&&(m>tmp);i--){
            v[i].second += v[i].first;
            tmp++;
        }
        pivot += add;
        sort(v.begin(),v.end(),cmpSecond);
    }
    return pivot-add;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tmp;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>tmp;
        v.push_back(make_pair(tmp,tmp));
    }
    cout<<func();
}
