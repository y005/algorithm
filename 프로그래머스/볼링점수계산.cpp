//https://www.acmicpc.net/problem/17215
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int func(string result){
    vector<pair <int,int> > scores;
    char current;
    int idx = 0,num1,num2,frame=0;
    //데이터를 처리하기 쉬운 형태로 묶어서 처리
    //본 게임: 한 프레임에 두 번의 기회
    //보너스 게임 처리 유의: 최대 2번의 기회 각각 최대 10점
    while(frame<10){
        current = result.at(idx++);
        switch(current){
            case 'S' :
                scores.push_back(make_pair(10,0));
                break;
            default:
                num1 = current =='-' ? 0 : atoi(&current);
                current = result.at(idx++);
                num2 = atoi(&current);
                if(current == '-'){num2 = 0;}
                if(current == 'P'){num2 = 10-num1;}
                scores.push_back(make_pair(num1,num2));
        }
        frame++;
    }
    //보너스 게임점수는 따로 받습니다.
    num1 =0;
    num2 =0;
    while(idx<result.size()){
        num1 = num2;
        current = result.at(idx++);
        if(current == 'S'){num2 = 10;}
        else if(current == '-'){num2 = 0;}
        else{num2 = atoi(&current);}
    }
    scores.push_back(make_pair(num1,num2));
    scores.push_back(make_pair(0,0));
    scores.push_back(make_pair(0,0));
    for(int i=0;i<scores.size();i++){cout<<scores[i].first<<","<<scores[i].second<<endl;}
    //숫자로 표현된 데이터들을 프로세스
    //현재 점수+추가 점수를 매번 더하고 있습니다.
    int totalScore=0;
    //점수 계산 구간
    for(int i=0;i<10;i++){
        pair<int,int> num = scores[i];
        if((i==9)&&(scores[i].first == 10)){totalScore += 10+scores[i+1].first+scores[i+1].second;}
        else if(scores[i].first == 10){
            if(scores[i+1].first == 10){totalScore += 10+10+scores[i+2].first;}
            else{totalScore += 10+scores[ i+1].first+scores[i+1].second;}
        }
        else if(scores[i].first+scores[i].second == 10){
            totalScore += 10 + scores[i+1].first;
        }
        else{
          totalScore += scores[i].first + scores[i].second;
        }
        cout<<"score: "<<totalScore<<endl;
    }
    //totalScore += num1+num2;
    //추가 점수 스테이지
    return totalScore;
}

int main(){
  string result;
  cin>>result;
  cout<<func(result);
}
