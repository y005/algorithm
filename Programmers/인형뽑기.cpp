//https://programmers.co.kr/learn/courses/30/lessons/64061
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> basket;
    int n = board.size();
    vector<int> index(n,n-1);
    int answer=0;
    int x,y;
    basket.push(-1);

    for(int i=n-1;i>=0;i--){
      for(int j=0;j<n;j++){
          if(board[i][j]!=0){index[j] =i;}
      }
    }
    for(int i=0;i<moves.size();i++){
        y = moves[i]-1;
        if(index[y]>n-1){continue;}
        x = index[y];
        if(board[x][y]==0){continue;}
        else{
            if(basket.top()==board[x][y]){
                basket.pop();
                answer++;
                index[y]++;
            }
            else {
                basket.push(board[x][y]);
                index[y]++;
            }
        }
    }
    return answer*2;
}
