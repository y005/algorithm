//https://www.acmicpc.net/problem/3079
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n,m;
vector<long long> v;

bool possible(long long val){
    long long total=0;
    for(long long i=n-1;i>-1;i--){
        total += val/v[i];
    }
    return total >= m ? true : false;
}

long long func(){
    sort(v.begin(),v.end());
    long long left = 0;
    long long right = m*v[0];
    long long mid;
    while(left<right){
        mid = (left+right)/2;
        if(possible(mid)){//주어진 시간동안 가능한 경우
            right = mid;
        }
        else{//주어진 시간동안 불가능하는 경우
            left = mid+1;
        }
    }
    return left;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tmp;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<func();
}
