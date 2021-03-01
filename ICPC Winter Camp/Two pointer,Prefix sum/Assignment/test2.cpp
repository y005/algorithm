//https://www.acmicpc.net/problem/11660
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
long long ans[1025][1025];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp,x1,y1,x2,y2;
    cin>>n>>m;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>tmp;
            ans[i][j] = ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+tmp;
        }
    }
    for(int i=0;i<m;i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<ans[x2][y2]-ans[x2][y1-1]-ans[x1-1][y2]+ans[x1-1][y1-1]<<'\n';
    }
}
