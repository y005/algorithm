#include <iostream>
#include <vector>
using namespace std;
vector<int>arr;
int n,count,result;

//�� �迭�� ���� ���� ��� , �� ��츦 
//�Լ� ȣ���Ͽ� ��������� ó�� �մϴ� 
void target(int sum,int i){
    if(i==n){
        if(sum==result){
            count++;
            return;
        }
        else{return;}
    }     
    target(sum+arr[i],i+1);
    target(sum-arr[i],i+1);
}

int main(){
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    cin>>result;
    target(0,0);
    cout<<count;
    return 0;
}
