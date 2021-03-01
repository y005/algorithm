//https://www.acmicpc.net/problem/1253
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n;
vector<long long> v;
vector<long long> ans;

int func(){
    int ans=0;
    for(int i=0;i<n;i++){
        int a = 0;
        int b = n-1;
        long long sum = 0;
        bool check = false;
        while(a<b){
            sum = v[a]+v[b];
            if(sum<v[i]){a++;}
            if(sum==v[i]){
                if((a!=i)&&(b!=i)){check=true; break;}
                if(a==i){a++;}
                if(b==i){b--;}
            }
            if(sum>v[i]){b--;}
        }
        if(check){ans++;}
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    cout<<func();
}
