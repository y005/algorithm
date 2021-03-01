//https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    vector< pair<int,int> > numpads;
    numpads.push_back(make_pair(3,1)) ;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){ numpads.push_back(make_pair(i,j)) ;}
    }
    pair<int,int> left(3,0),right(3,2);
    string answer = "";
    int num,leftDist,rightDist;
    for(int i =0;i<numbers.size();i++){
        num = numbers[i];
        if(num%3==1){
            left.first = numpads[num].first;
            left.second = numpads[num].second;
            answer += "L";
        }
        else if(num%3==0&&!(num==0)){
            right.first = numpads[num].first;
            right.second = numpads[num].second;
            answer += "R";
        }
        else{
            leftDist = abs(left.first - numpads[num].first)+abs(left.second - numpads[num].second);
            rightDist = abs(right.first - numpads[num].first)+abs(right.second - numpads[num].second);
            if(leftDist<rightDist){left.first = numpads[num].first;left.second = numpads[num].second; answer += "L";}
            else if(leftDist==rightDist){
                if(hand =="right"){
                    right.first = numpads[num].first;
                    right.second = numpads[num].second;
                    answer += "R";
                }
                else{
                    left.first = numpads[num].first;
                    left.second = numpads[num].second;
                    answer += "L";
                }
            }
            else{right.first = numpads[num].first;right.second = numpads[num].second; answer += "R";}
        }
    }
    return answer;
}
