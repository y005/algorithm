//https://www.acmicpc.net/problem/14659
#include<iostream>
#include<vector>
using namespace std;

int num;
vector<int> v;


int function(){

    int maxHeight=-1;
    int maxKill = 0;
    int localMaxKill = 0;

    for(int i=0;i<num;i++){
        if(v[i]>maxHeight){
            maxHeight = v[i];
            localMaxKill = 0;
        }
        maxKill = max(maxKill,localMaxKill);
        localMaxKill++;
    }
    return maxKill;
}

int main(void) {
    int tmp;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<function();
    return 0;
}
