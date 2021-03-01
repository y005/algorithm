//https://programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int prevScore = 0;
    int currentScore = 0;

    for(int i=0;i<dartResult.size();i++){
        char result = dartResult.at(i);
        switch(result){
            case 'S':
                break;
            case 'D':
                currentScore *= currentScore;
                break;
            case 'T':
                currentScore = currentScore*currentScore*currentScore;
                break;
            case '#':
                currentScore *= -1;
                break;
            case '*':
                currentScore *= 2;
                answer += prevScore;
                break;
            default:
                prevScore = currentScore;
                answer += prevScore;
                currentScore = result - '0';
                if(result=='1'&&dartResult[i+1]=='0'){currentScore = 10;i++;}
                break;
        }
    }
    answer += currentScore;
    return answer;
}
