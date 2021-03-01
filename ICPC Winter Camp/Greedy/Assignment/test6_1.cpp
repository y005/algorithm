//https://www.acmicpc.net/problem/2839
#include<iostream>
using namespace std;
int mem[5000];

int func(int n){
    for(int i=1;i<=n;i++){mem[i]= -1;}
    mem[0]=0;
    mem[3]=1;
    mem[5]=1;
    for(int i=6;i<=n;i++){
        int a = mem[i-3];int b = mem[i-5];
        if(a*b>0){mem[i] = 1+min(a,b) ? 1+min(a,b) : -1;}
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
