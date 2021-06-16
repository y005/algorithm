//https://www.acmicpc.net/problem/1149
#include<iostream>
#include<vector>
using namespace std;
#define R 0
#define G 1
#define B 2

int n;
int arr[1000][3];
//0~i-1번째 집을 RGB로 색칠할 때 최솟값
vector< vector<int> > v;
int func(){
    arr[0][R] = v[0][R];
    arr[0][G] = v[0][G];
    arr[0][B] = v[0][B];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==R){arr[i][R] = v[i][R]+min(arr[i-1][G],arr[i-1][B]);}
            else if(j==G){arr[i][G] = v[i][G]+min(arr[i-1][R],arr[i-1][B]);}
            else{arr[i][B] = v[i][B]+min(arr[i-1][R],arr[i-1][G]);}
        }
    }
    return min(arr[n-1][R],min(arr[n-1][G],arr[n-1][B]));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> v1;
        for(int j=0;j<3;j++){
            cin>>tmp;
            v1.push_back(tmp);
        }
        v.push_back(v1);
    }
    cout<<func()<<"\n";
}
