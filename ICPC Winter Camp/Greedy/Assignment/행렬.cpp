//https://www.acmicpc.net/problem/1080
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
//A에서 B로 행렬의 변환을 위해서
//필요한 영역의 연산 횟수를 기록함
//0이면 연산이 짝수번 실행되어야 함
//1이면 연산이 홀수번 실행되어야 함
int arr[50][50];

//아래로 오른쪽으로 1이면
//현재점을 시작점으로 3X3 뒤집기
//지난 시작기준점들은 무조건 0을 만족함
int func(){
    int cnt=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(arr[x][y]==1){
                if((x<n-2)&&(y<m-2)){
                    cnt++;
                    for(int i=x;i<x+3;i++){
                        for(int j=y;j<y+3;j++){
                            arr[i][j] = (arr[i][j]+1)%2;
                        }
                    }
                }
                else{
                    return -1;
                }
            }
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(int j=0;j<m;j++){
            arr[i][j] = tmp[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(int j=0;j<m;j++){
            arr[i][j] = arr[i][j] == tmp[j]-'0' ? 0 : 1;
        }
    }
    cout<<func();
}
