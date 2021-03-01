//https://www.acmicpc.net/problem/2847
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;

int function(){
    int prev = 20001;
    int count = 0;
    for(int i=n-1;i>-1;i--){
        if(prev<=v[i]){
            count += v[i]-(prev-1);
            v[i] = prev-1;
        }
        prev = v[i];
    }
    return count;
}
int main(){
        int tmp;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>tmp;
            v.push_back(tmp);
        }
        cout<<function();
}
