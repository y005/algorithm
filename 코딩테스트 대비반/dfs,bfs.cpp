#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main(){  
    int v,e,start;
    cin>>v>>e>>start;
    map< int,set<int> > graph;
    int x,y;
    for(int i=0;i<e;i++){
         cin>>x>>y;
         graph[x].insert(y);
         graph[y].insert(x); 
    }
    stack<int> st;
    int current;
	bool visited [e];
	fill(visited, visited+e, false);
    st.push(start);
    visited[start] =true;
	while(!st.empty()){
        current=st.top();
        st.pop();
        cout<<current<<" ";
		for(int i=v-1;i>-1;i--){
            if((!visited[i])&&(graph[current].find(i)!=graph[current].end())){
                st.push(i);
                visited[i]= 1;
            }
        }
    }
    cout<<endl;
    queue<int> q;
    bool visited1 [e];
   	fill(visited1, visited1+e, false);

	q.push(start);
    visited1[start] =true;
	while(!q.empty()){
        current=q.front();
        q.pop();
        cout<<current<<" ";
        for(int i=0;i<v;i++){
            if((!visited1[i])&&(graph[current].find(i)!=graph[current].end())){
                q.push(i);
        		visited1[i]= 1;
            }
        }
    }
}
