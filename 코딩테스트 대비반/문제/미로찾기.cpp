#include<iostream>
#include<stack> 
#include<vector> 
#include<algorithm>
using namespace std;

//스택을 활용한 미로찾기 알고리즘 
int arr[8][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,1,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,0,1,1},
	{1,1,1,1,1,1,1,0,1,1},
	{1,1,1,1,1,1,1,0,1,1},
	{1,1,1,1,1,1,1,0,1,1}
};
int visited [8][10] = {0,};
int move [8][2] = {
	{1,0},
	{0,1},
	{1,1},
	{-1,0},
	{0,-1},
	{-1,-1},
	{-1,1},
	{1,-1}
};
vector<pair<int,int> > result;
bool possible(pair<int,int>& a){
	if(visited[a.first][a.second]){return false;}
	if((a.first>7)||(a.first<0)){return false;}
	if((a.second>7)||(a.second<0)){return false;}
	return true;
}
void findMaze(){
	stack<pair<int,int> > st;
	pair<int,int> current;
	pair<int,int> next;
	
	st.push(make_pair(1,0));
	while(!st.empty()){
		current = st.top();
		st.pop();
		cout<<current.first<<","<<current.second<<endl;
		if((current.first==7)&&(current.second==7)){
			cout<<"find!!"<<endl; 
			return;  
		}
		for(int i=0;i<8;i++){
			next.first = current.first+move[i][0];
			next.second = current.second+move[i][1];
			if(possible(next)&&(!arr[next.first][next.second])){
				st.push(next);
				visited[next.first][next.second]=1;
			}
		}
	}	
	cout<<"not found"<<endl;
}
int main(){
	findMaze();
}
