#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//map 처음 인자에는 단어, 다음 인자에는 문자 길이를 비교합니다 
//스트링 클래스에서 자체 지원하는 비교 문자  
bool myPairCMP(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second < b.second) {
		return true;
	}
	// 길이가 같을때 문자끼리 비교해서 작은게 앞으로 오게한다.
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	int N;
	cin >> N;
	vector<pair<string, int>> myVec;
	// 1. 입력 vector에 <단어,단어의 길이> 를 넣어준다.
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		myVec.push_back(make_pair(temp, temp.length()));
	}
	// 2.소팅해준다.
	//자체설정한 비교 함수를 인자로 넣어준다  
	sort(myVec.begin(), myVec.end(), myPairCMP);
	cout << "---------------myAnswer--------------- \n";
	// 3.출력
	map<string, int> myMap;
	for (int i = 0; i < N; i++) {
		// 4. 중복 처리
		if (myMap[myVec[i].first] > 0)
			continue;
		else
			myMap[myVec[i].first]++;
		cout << myVec[i].first << "\n";
	}
	return 0;
}

