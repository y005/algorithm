#include <iostream>
#include <vector> 
using namespace std;

int func(int n,int m){
    int sum=0;
    if(n==1){return m;}
    for(int i=1;i<=m-n+1;i++){
        sum += func(n-1,m-i);
    }
    return sum;
}

int main(){
    vector<int> result;
    int n,tmp0,tmp1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp0>>tmp1;
        result.push_back(func(tmp0,tmp1));
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
