//https://www.acmicpc.net/problem/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,k,cnt;
vector<int> v;
int arr[4243];
int tmp[4243];

void merge(int s,int m,int e){
    int arrayIdx = s,leftIdx,rightIdx = m+1;
    for(leftIdx=s;leftIdx<e+1;leftIdx++){tmp[leftIdx] = arr[leftIdx];}
    leftIdx = s;
    int result;
    while((leftIdx<m+1)&&(rightIdx<e+1)){
		result = (tmp[leftIdx]>tmp[rightIdx]);
		arr[arrayIdx++] = !result*tmp[leftIdx]+result*tmp[rightIdx];
		cnt  +=  result*(m-leftIdx+1);
		leftIdx += (!result);
		rightIdx += result;
	}
    while((leftIdx<m+1)||(rightIdx<e+1)){
		arr[arrayIdx++] = (rightIdx<e+1)*tmp[rightIdx++]+(leftIdx<m+1)*tmp[leftIdx++];
	}
}
void mergeSort(int s,int e){
    int m;
    if(s<e){
        m = (s+e)>>1;
        mergeSort(s,m);
        mergeSort(m+1,e);
        merge(s,m,e);
    }
}

bool func(){
    //초기화
    cnt = 0;
    mergeSort(0,v.size());
    if(cnt==k){return true;}
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){v.push_back(i+1);}
    if(!k){
        for(int i=0;i<n;i++){cout<<v[i]<<" ";}
        return 0;
    }
    do{
        //정렬을 할 예비 배열 생성
        for(int i=0;i<n;i++){arr[i]=v[i];}
        if(func()){
            for(int i=0;i<n;i++){cout<<v[i]<<" ";}
            break;
        }
	}while(next_permutation(v.begin(),v.end()));
}
