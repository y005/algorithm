//https://www.acmicpc.net/problem/1182
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,s,ans;
vector<int> v;
void func(int i,int sum,int same,int cnt) {
    if(i>n){return;}
    //1.합이 만족된 상태에서 다음 원소를 미포함한 경우
    //중복으로 인정되는 상황
    //2.합이 0인 경우 원소 하나도 포함하지 않는 경우
    //인정되는 상황
    if((sum==s)&&(!same)&&cnt){
        same = 1;
        ans++;
    }
    //하나의 원소라도 추가되면 같지 않아짐
    func(i+1,sum+v[i],0,cnt+1);
    //하나의 원소를 추가안해서 이전 부분 배열과 동일
    func(i+1,sum,same,cnt);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    func(0,0,0,0);
    cout<<ans;
}
