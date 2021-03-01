//https://www.acmicpc.net/problem/2231
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//n은 분해합 a는 자리수
int n,a;
std::vector<int> v;

int func(){
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                for(int d=0;d<10;d++){
                    for(int e=0;e<10;e++){
                        for(int f=0;f<10;f++){
                            for(int g=0;g<10;g++){
                                if(n==1000001*a+100001*b+10001*c+1001*d+101*e+11*f+2*g){
                                    return 1000000*a+100000*b+10000*c+1000*d+100*e+10*f+g;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cout<<func();
}
