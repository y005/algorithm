//https://www.acmicpc.net/problem/17215
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string result;
  int ans=0,frame=1,strikeBonus1=0,strikeBonus2=0,pairBonus=0,score,prev=0,cnt=2;
  cin>>result;
  for(int i=0;i<(int)result.length();i++){
      switch(result[i]){
          case 'S':
              cnt = 0;
              score = 10;
              break;
          case '-':
              cnt--;
              score = 0;
              break;
          case 'P':
              cnt--;
              score = 10 - prev;
              break;
          default:
              cnt--;
              score = result[i]-'0';
      }
      ans += score + (strikeBonus1-->0)*score + (strikeBonus2-->0)*score + (pairBonus-->0)*score;
      strikeBonus1 = strikeBonus2;
      strikeBonus2 = 0;
      if((result[i]=='S')&&(frame<10)){strikeBonus2 = 2;}
      if((result[i]=='P')&&(frame<10)){pairBonus = 1;}
      prev = score;
      if(!cnt){frame++;cnt=2;}
  }
  cout<<ans<<'\n';
}
