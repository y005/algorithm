//https://programmers.co.kr/learn/courses/30/lessons/68644
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> check;
    int n = numbers.size();
    //재귀함수 사용하는 대신 순열에서 제약(오름차순으로만 선택 가능)을 사용
    //조합계산(for문을 사용하며 오름차순으로 선택만 가능하게 제약하여 조합으로 결과나옴)
    //중복 체크를 위한 set에도 값을 삽입(검색 빠르게 가능)
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(check.find(numbers[i]+numbers[j])!=check.end()){continue;}
            check.insert(numbers[i]+numbers[j]);
            answer.push_back(numbers[i]+numbers[j]);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
