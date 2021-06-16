//https://www.acmicpc.net/problem/11726
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int func[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin>>n;
    func[1] = 1;
    func[2] = 2;
    for(int i=3;i<n+1;i++){
        func[i] = (func[i-1]+func[i-2])%10007;
    }
    cout<<func[n];
}
