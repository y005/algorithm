#include <iostream>
#include <vector>
#define INT_MAX 1000
using namespace std;
vector <int> ability;
int enemy;

int func(int sec,int current){
    
    if(current==enemy){return sec;}
    if(current>enemy){return INT_MAX;}
    int min = INT_MAX;
    int tmp;
    
    for(int i=0;i<3;i++){
        tmp = func(sec+1,current+ability[i]);
        if(min>tmp){
            min = tmp;
        }
    }
    return min;
}

int main()
{
    int teacher,a,b,c;
    
    cin>>teacher>>enemy;
    cin>>a>>b>>c;
    
    ability.push_back(a);
    ability.push_back(b);
    ability.push_back(c);
    
    if(func(0,teacher)==INT_MAX){cout<<-1<<endl;}
    else{cout<<func(0,teacher)<<endl;}
    
    return 0;
}

