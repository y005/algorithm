//https://www.acmicpc.net/problem/1002
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num;
    int a1,a2,b1,b2;
    float r1,r2,dist;
    int* result;
    cin>>num;
    result = new int[num];
    for(int i=0;i<num;i++){
        cin>>a1>>a2>>r1>>b1>>b2>>r2;
        dist = sqrt(pow(a1-b1,2)+pow(a2-b2,2));
        if(dist==0){
            if(r1==r2){result[i] = -1;}
            else{result[i] = 0;}
        }
        else if(dist<r1+r2){
            if(dist==abs(r1-r2)){result[i]=1;}
            else if(dist<abs(r1-r2)){result[i]=0;}
            else{result[i]=2;}
        }
        else if(dist==r1+r2){result[i]=1;}
        else{result[i]=0;}
    }
    for(int i=0;i<num;i++){
        cout<<result[i]<<endl;
    }
}
