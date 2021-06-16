//https://www.acmicpc.net/problem/9095
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[12];
void func(int n){
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4;i<n+1;i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n,ret=-1;
    vector<int> v;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        v.push_back(n);
        ret = max(ret,n);
    }
    func(ret);
    for(int i=0;i<T;i++){
        cout<<arr[v[i]]<<"\n";
    }
}
