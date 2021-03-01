#include<iostream>
#include<queue>
#include<set>
using namespace std;

int toInt(int num[]){
	int sum = 0;
	int ten = 1;
	for(int i=0;i<4;i++){
		sum += num[i]*ten;
		ten *= 10;
	}
	return sum;
}
void toArr(int num[],int A){
	int ten=10;
	for(int i=0;i<4;i++){
		num[i] = A%ten;
		A = A/10;
	}
}
int primeNum(int x,int y){
	int isPrime[10000]={0,};//1000~9999
	set<int> prime;
	int div;
	queue<int> A;
	int X[4];
	int Y[4];
	//숫자를 배열로 변환 	
	//에라토스테네스 체를 이용한 소수 배열 
	for(int i=2;i<10000;i++){	
		div=999/i;
		for(int j=(div+1)*i;j<10000; j+=i){	
			if(i==j){continue;}
			isPrime[j] = 1;
		}
	}
	int count = 0;
	A.push(x);
	int current;
	int old,N;
	int idx=0;
	prime.insert(x);
	//큐를 이용한 너비탐색  
	int start = 1;
	
	while(!A.empty()){
		current = A.front();
		A.pop(); 
		if(current==y){break;}
		toArr(X,current);
		for(int i=0;i<4;i++){
			for(int j=0;j<10;j++){
				old = X[i];
				X[i] = j;
				N = toInt(X);
				X[i] = old;
				if((!isPrime[N])&&(N>999)&&(prime.find(N)==prime.end())){
					cout<<N<<endl;
					prime.insert(N);
					A.push(N);
				}
			}
		}	
	}	
	return count;
} 

int main(){
	int n,n1,n2;
	vector<int>num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>n1>>n2;	
		num.push_back(primeNum(n1,n2));
	}
	for(int i=0;i<n;i++){	
		cout<<num[i];
	}
}
