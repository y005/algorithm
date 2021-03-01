#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<string> words;
int sz;
//한 단어만 바꿀수 있는 관계의 그래프 연결리스트

bool isPossible(int& current,int& next){
    int count =0;
    string a = words[current];
    string b = words[next];
    int n = a.size();
    
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){count++;}
    }
    if(count==1){return true;}
    else{return false;}
}

int find(){
    //<단어인덱스,레벨> 
    queue<pair<int,int> > q; 
    pair<int,int> current;
    
    vector<bool> visited;
    for(int i=0;i<sz;i++){
        visited.push_back(false);
    }
    
    q.push(pair<int,int>(0,0));
    visited[0] = true; 
    
    while(!q.empty()){
        current = q.front();
        q.pop();
        if((current.first)==(sz-1)){return current.second;}
        for(int i=0;i<sz;i++){
            if(isPossible(current.first,i)&&(!visited[i])){
                visited[i] = true;
                q.push(make_pair(i,(current.second)+1));
            }
        } 
    }
    return 0;
}

int main(){
    cin>>sz;
    string tmp;
    for(int i=0;i<sz;i++){
        cin>>tmp;
        words.push_back(tmp);
    }    
    cout<<find();
    return 0;
}
