#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int map[25][25];
int sz;
vector<string> m; 
vector<int> result;
int move1[8][2] = {{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
int visited[25][25] = {0,};

//그룹찾기 dfs로 탐색하는 과정
//스택을 이용해서 구현함
//이동방향에 아파트 발견시 스택에 푸시
//아파트 갯수 또한 증가  
int group(int x,int y){   
    //<<x,y>,id>  
    stack<pair<int,int> > st;
    pair<int,int> now;
    
	int next_x,next_y,count=1;
	st.push(make_pair(x,y));
	
    while(!st.empty()){
        now = st.top();
        st.pop();
        for(int i=0;i<8;i++){
            next_x = now.first + move1[i][0];
            next_y = now.second + move1[i][1];
            if((next_x<0)||(next_y<0)){continue;}
            if((next_x>=sz)||(next_y>=sz)){continue;}
            if(!(visited[next_x][next_y])&&(map[next_x][next_y])){ 
				visited[next_x][next_y] =1;				
                st.push(make_pair(next_x,next_y));
                count++;
            }
        }
    }
    return count;
}

//2차원 배열 지도를 완전 탐색 중아파트 표시인 
//1을 발견하면 그 아파트와 연결된 단지를 dfs를
//통해 연결된 아파트 갯수를 찾고 그룹번호  
void grouping(){
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			if(!(visited[i][j])&&(map[i][j])){
				visited[i][j] = 1;
				result.push_back(group(i,j));    
			}		
		}
	}
}
int main (){
    cin >> sz;
    string tmp;
    for (int i = 0; i < sz; i++){
        cin>>tmp;
        m.push_back(tmp);
    }
    for (int i = 0; i < sz; i++){
        tmp = m[i];
        for(int j=0;j<sz;j++){
            if(tmp[j]=='1'){map[i][j]=1;}
            else{map[i][j]=0;}
        }
    }
	for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<endl;
    }
    grouping();
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
	for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
