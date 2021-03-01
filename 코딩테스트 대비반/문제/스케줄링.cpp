#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int END= -1;

class Work {
	public:
	//시작 가능 날짜,마감 기한 날짜,소요시간 
	int start, deadline, time;
	Work(int a = 0, int b = 0, int c = 0) : start(a), deadline(b), time(c) {}
};

//우선순위 큐를 정렬하기 위한 정렬함수 재정의 
bool compWork (Work& a,Work& b) {
	if (a.start == b.start) {
		return a.deadline < b.deadline;
	}
	return a.start < b.start;
}

//우선순위 큐를 활용하는 것은 최대인 값만 구할 때는 좋지만
//큐에서 팝을 해야지 다음 값을 구할 수 있기 때문에 입력 배
//열의 훼손이 일어나기 때문에 사용하지 않습니다. 
//전체 작업들을 순회하기 때문에 매번 벡터를 재정의 함수를 
//이용해 정렬하는 것이 더 효율적입니다. 
vector<Work> input;

//스케줄링의 기본 원리 
//먼저 시작 날짜 우선 정렬 같은 경우 마감기간 우선 정렬 
//오늘 가능한 업무 중 마감기간이 제일 촉박한 일을 우선 정렬

bool match() {
	int time;
	sort(input.begin(), input.end(), compWork);
	//기준: 가능한 날짜 중 마감이 짧은 것을 우선으로 정렬 
	for (int day = 1; day < END+1; day++) {
		time = 8;
		sort(input.begin(), input.end(), compWork);
		for (int i = 0; i < input.size(); i++) {
			if ((!input[i].time) ||(input[i].start > day)){ continue; }
			else {
				//시작 가능한 업무들은 이제 마감 기간을 
				//우선으로 정렬하기 위해서 업무의 시작 
				//날짜를 늘려줍니다.
				//(시작 가능한 업무 중 마감 기간이 짧은 순서로)
				input[i].start++;
				if (input[i].deadline >= day) {
					if (input[i].time >= time) {
						//WAR(anti dependency)
						input[i].time -= time;
						time = 0;
					}
					else {
						//WAR(anti dependency)
						time -= input[i].time;
						input[i].time = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < input.size(); i++) {
		if (input[i].time) { return false; }
	}
	return true;
}

int main() {
	//테스트 케이스 갯수
	int n, tmp1, tmp2, tmp3, tmp4;
	cin >> n;
	Work tmp;
	//케이스 별로 가능한지 확인합니다. 
	vector<bool> output;
	bool result;

	for (int j = 0; j < n; j++) {
		cin >> tmp1;
		//업무들의 시작일,마감일, 소요시간
		for (int k = 0; k < tmp1; k++) {
			cin >> tmp2 >> tmp3 >> tmp4;
			if (tmp3 > END) {END = tmp3;}
			tmp = Work(tmp2, tmp3, tmp4);
			input.push_back(tmp);
		}
		result = match();
		output.push_back(result);
		input.clear();
	}
	for (int i = 0; i < output.size(); i++) {
		if (output[i]) { cout << "yes" << endl; }
		else { cout << "no" << endl; }
	}
	return 0;
}
