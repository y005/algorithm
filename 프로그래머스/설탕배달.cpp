//https://www.acmicpc.net/problem/2839
#include<iostream>
using namespace std;
int mem[5000];

//DP를 이용한 방법(memoization)
int func(int n){
    for(int i=1;i<=n;i++){mem[i]= -1;}
    mem[0]=0;
    mem[3]=1;
    mem[5]=1;
    for(int i=6;i<=n;i++){
        int a = mem[i-3];int b = mem[i-5];
        //이 전의 최소값이 모두 존재하거나 존재하지않는 경우
        if(a*b>0){mem[i] = 1+min(a,b) ? 1+min(a,b) : -1;}
        //둘 중 하나만 존재하는 경우
        else{mem[i]=1+(b>0)*b+(a>0)*a;}
    }
    return mem[n];
}
int main(){
    int input;
    cin>>input;
    cout<<func(input);
    return 0;
}
