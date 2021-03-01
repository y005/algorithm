//https://www.acmicpc.net/problem/20302
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n;
//결과값을 소인수분해
//ans[i] = 해당 수의 지수
int ans[100001];
//작은 수부터 나누면 자연스럽게 소인수분해가 됨
//입력값 0에 대한 예외처리

void func(int num){
    int sz =(int) sqrt(num);
    for(int i=2;i<=sz;i++){
        while(!(num%i)){
            num /= i;
            ++ans[i];
        }
    }
    if(num>1){++ans[num];}
}
void func1(int num){
    int sz = (int)sqrt(num);
    for(int i=2;i<=sz;i++){
        while(!(num%i)){
            num /= i;
            --ans[i];
        }
    }
    if(num>1){--ans[num];}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    char oper;
    bool zero = false;
    cin>>n;
    for(int i=0;i<n;i++){
        if(!i){
            cin>>tmp;
            if(!tmp){zero = true;}
            else{
                tmp = tmp<0? -1*tmp : tmp;
                func(tmp);
            }
        }
        else{
            cin>>oper>>tmp;
            if(!tmp){zero = true;}
            else{
                tmp = tmp<0? -1*tmp : tmp;
                //나누기 소인수 지수 -
                if(oper=='/'){func1(tmp);}
                //곱하기 소인수 지수+
                else{
                    func(tmp);
                }
            }
        }
    }
    bool flag = true;
    if(zero){
        cout<<"mint chocolate";
    }
    else{
        for(int i=2;i<=100000;i++){
            if(ans[i]<0){flag = false;}
        }
        if(!flag){cout<<"toothpaste";}
        else{cout<<"mint chocolate";}
    }
}
