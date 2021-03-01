//https://www.acmicpc.net/problem/9663
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,ans;
bool can;
vector<int> pos;
vector<int> visitedCol;

//m: 현재 퀸을 배치하려고 하는 열
void func(int m){
    if(m==n){ans++;return;}
    //m열 i행의 자리에 대한 위치 가능 검사
    for(int i=0;i<n;i++){
        //이미 해당 행에 하나의 퀸이 위치했을 경우 넘어감
        if(visitedCol[i]){continue;}
        else{
            can = true;
            //해당 행에 없는 경우 이전에 배열한 퀸들의 위치와 대각선 관계를 이루는지 검사
            for(int j=0;j<m;j++){
                if((m-j)==abs(i-pos[j])){can=false;break;}
            }
            //모든 검사를 통과할 경우 해당 위치에 퀸을 배치하고 다음 열의 퀸배치 함수 호출
            if(can){
                pos[m] = i;
                visitedCol[i] = 1;
                func(m+1);
                visitedCol[i] = 0;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        pos.push_back(-1);
        visitedCol.push_back(0);
    }
    func(0);
    cout<<ans;
}
