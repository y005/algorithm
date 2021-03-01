//https://www.acmicpc.net/problem/16563
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n;
vector<int> v;
//시간복잡도를 위한 소인수 저장 배열이 필요
//에라토스테네스의 체 사용
//prime[i] = i가 소수값이면 0
int prime[2500];
vector<int> primeNum;

void func(){
    //2~해당 수 제곱근의 아랫값까지 나눌 수 있는지 확인
    for(int i=0;i<n;i++){
        int a = 0;
        int b = floor(sqrt(v[i]));
        while(primeNum[a]<=b){
            if(!(v[i]%primeNum[a])){
                cout<<primeNum[a]<<" ";
                v[i] /= primeNum[a];
                b = floor(sqrt(v[i]));
                a = 0;
            }
            else{a++;}
        }
        //마지막 남은 소수 추가
        cout<<v[i]<<'\n';
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    int max = -1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(max<tmp){max=tmp;}
        v.push_back(tmp);
    }
    //최대수의 제곱근까지만 사용
    for(int i=2;i<floor(sqrt(max))+1;i++){
        //2부터 자신의 배수를 소수에서 제외
        for(int j=i+1;j<floor(sqrt(max))+1;j++){
            if(j%i==0){prime[j] = 1;}
        }
    }
    for(int i=2;i<floor(sqrt(max))+1;i++){
        if(!prime[i]){primeNum.push_back(i);}
    }
    func();
    return 0;
}
