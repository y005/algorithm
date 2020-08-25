#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int END= -1;

class Work {
	public:
	//���� ���� ��¥,���� ���� ��¥,�ҿ�ð� 
	int start, deadline, time;
	Work(int a = 0, int b = 0, int c = 0) : start(a), deadline(b), time(c) {}
};

//�켱���� ť�� �����ϱ� ���� �����Լ� ������ 
bool compWork (Work& a,Work& b) {
	if (a.start == b.start) {
		return a.deadline < b.deadline;
	}
	return a.start < b.start;
}

//�켱���� ť�� Ȱ���ϴ� ���� �ִ��� ���� ���� ���� ������
//ť���� ���� �ؾ��� ���� ���� ���� �� �ֱ� ������ �Է� ��
//���� �Ѽ��� �Ͼ�� ������ ������� �ʽ��ϴ�. 
//��ü �۾����� ��ȸ�ϱ� ������ �Ź� ���͸� ������ �Լ��� 
//�̿��� �����ϴ� ���� �� ȿ�����Դϴ�. 
vector<Work> input;

//�����ٸ��� �⺻ ���� 
//���� ���� ��¥ �켱 ���� ���� ��� �����Ⱓ �켱 ���� 
//���� ������ ���� �� �����Ⱓ�� ���� �˹��� ���� �켱 ����

bool match() {
	int time;
	sort(input.begin(), input.end(), compWork);
	//����: ������ ��¥ �� ������ ª�� ���� �켱���� ���� 
	for (int day = 1; day < END+1; day++) {
		time = 8;
		sort(input.begin(), input.end(), compWork);
		for (int i = 0; i < input.size(); i++) {
			if ((!input[i].time) ||(input[i].start > day)){ continue; }
			else {
				//���� ������ �������� ���� ���� �Ⱓ�� 
				//�켱���� �����ϱ� ���ؼ� ������ ���� 
				//��¥�� �÷��ݴϴ�.
				//(���� ������ ���� �� ���� �Ⱓ�� ª�� ������)
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
	//�׽�Ʈ ���̽� ����
	int n, tmp1, tmp2, tmp3, tmp4;
	cin >> n;
	Work tmp;
	//���̽� ���� �������� Ȯ���մϴ�. 
	vector<bool> output;
	bool result;

	for (int j = 0; j < n; j++) {
		cin >> tmp1;
		//�������� ������,������, �ҿ�ð�
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
