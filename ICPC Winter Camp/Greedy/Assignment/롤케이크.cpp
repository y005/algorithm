//https://www.acmicpc.net/problem/16206
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,cut,ans,twenty;
//twenty 20의 갯수 변수
//v1 10의 배수만 담은 배열
//v2 10의 배수가 아닌 수만 담은 배열
vector<int> v1,v2;

int func(){
    //20처리
    while((twenty>0)&&(cut>0)){
        cut--;
        twenty--;
        ans += 2;
    }
    //10의 배수 처리
    sort(v1.begin(),v1.end());
    for(int i=0;(cut>0)&&(i<v1.size());i++){
        //하나의 조각을 다 10으로 나눌 수 있는 경우
        if(cut >= v1[i]/10-1){
            cut -= v1[i]/10-1;
            ans += v1[i]/10;
        }
        //다 나눌 수 없는 경우
        else{
            ans += cut;
            cut = 0;
        }
    }
    //나머지 case처리
    for(int i=0;(cut>0)&&(i<v2.size());i++){
        //하나의 조각을 10으로 최대한 나눌 수 있는 경우
        if(cut>= v2[i]/10){
            cut -= v2[i]/10;
            ans += v2[i]/10;
        }
        else{
            ans += cut;
            cut = 0;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>cut;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp == 10 || tmp==20){
            if(tmp==20){twenty++;}
            else{ans++;}
        }
        else{
            tmp%10==0 ? v1.push_back(tmp) : v2.push_back(tmp);
        }
    }
    cout<<func();
}
