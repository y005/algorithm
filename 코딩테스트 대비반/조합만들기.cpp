#include<iostream>
#include<vector>
using namespace std;
int cache[3]={0,0,0};
vector<int> v;
vector<vector<int> > result;
int idx;
void comb(int n){
	if(n==3){
		result.push_back(v);
		idx++;
		return;
	}
	for(int i=0;i<3;i++){
		if(!cache[i]){
			v.push_back(i);
			cache[i]=1;
			comb(n+1);
			cache[i]=0;
			v.pop_back();	
		}
	}
}
int main(){
	comb(0); 	
	for(int i=0;i<idx;i++){
		for(int j=0;j<3;j++){
			cout<< result[i][j]<<" ";	
		}
		cout<<endl;
	}
	return 0;
}
