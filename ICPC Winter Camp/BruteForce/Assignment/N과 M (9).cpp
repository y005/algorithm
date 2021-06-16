//https://www.acmicpc.net/problem/15663
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
vector<int> v;
vector<int> v1;
int arr[8];
//i번째로 놓을 원소를 선택하고
//i+1번째 상황도 동일한 재귀함수 호출 문제
void func(int i){
    int tmp=0;
    if(i==m){
        for(int j=0;j<m;j++){
            printf("%d ",v1[j]);
        }
        printf("\n");
        return;
    }
    //i번째에 놓을 원소를 선택한다.
    for(int j=0;j<n;j++){
        //앞에 이미 있으면 다른 원소를 선택
        if(arr[j]||(tmp==v[j])){continue;}
        else{
            //i번째에 해당 원소를 배치한 상황
            v1.push_back(v[j]);
            arr[j] = 1;
            func(i+1);
            //다른 원소를 배치한 상황을 위한 세팅
            v1.pop_back();
            arr[j] = 0;
        }
        //i번째에 놓을 원소 숫자가 같은 지 확인
        //을 통해 중복수열 방지
        tmp = v[j];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    func(0);
}
