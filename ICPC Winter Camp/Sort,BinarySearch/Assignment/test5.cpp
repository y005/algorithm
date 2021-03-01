//https://www.acmicpc.net/problem/16401
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long m,n;
vector<long long> v;
long long ans;

bool possible(long long val){
    long long total=0;
    for(long long i=n-1;(i>-1)&&(total<m);i--){
        total += v[i]/val;
    }
    return total >= m ? true : false;
}

void func(){
    sort(v.begin(),v.end());
    long long left = 1;
    long long right = v[n-1];
    long long mid;
    //left는 안되는 길이 값 중 제일 짧은 길이
    while(left<=right){
        mid = (left+right)/2;
        if(possible(mid)){//주어진 길이로 분배가 가능한 경우
            if(ans<mid){ans=mid;}
            left = mid+1;
        }
        else{//주어진 길이로 분배가 불가능한 경우
            right = mid-1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tmp;
    cin>>m>>n;
    for(long long i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    func();
    cout<<ans;
}
