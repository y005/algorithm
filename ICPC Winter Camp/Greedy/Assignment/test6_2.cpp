//https://www.acmicpc.net/problem/2839
#include<iostream>
using namespace std;

int func(int n){
    int k = n%5==0 ? n/5: n/5+1;
    while(k<=n/3){
        if(!(((5*k-n)%2)|((n-3*k)%2))){break;}
        k++;
    }
    return k==n/3+1 ? -1 : k;
}

int main(){
    int input;
    cin>>input;
    cout<<func(input);
    return 0;
}
