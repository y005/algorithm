//https://www.acmicpc.net/problem/1021
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int n,m;
vector<int> v;
deque<int> d;

void func1(){
    d.pop_front();
}

void func2(){
    int tmp = d.front();
    d.pop_front();
    d.push_back(tmp);
}

void func3(){
    int tmp = d.back();
    d.pop_back();
    d.push_front(tmp);
}
int func(){
    int count=0;
    deque<int>::iterator idx;
    for(int i=0;i<m;i++){
        int count2=0;
        int count3;
        //2번 연산으로 가는 횟수 기록
        for(idx=d.begin();idx!=d.end();idx++){
            if(*idx==v[i]){break;}
            count2++;
        }
        count3 = d.size()-count2;
        if(count2<count3){
            count += count2;
            while(count2){
                func2();
                count2--;
            }
            func1();
        }
        else{
            count += count3;
            while(count3){
                func3();
                count3--;
            }
            func1();
        }
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        d.push_back(i+1);
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<func();
}
