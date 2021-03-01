#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//map ó�� ���ڿ��� �ܾ�, ���� ���ڿ��� ���� ���̸� ���մϴ� 
//��Ʈ�� Ŭ�������� ��ü �����ϴ� �� ����  
bool myPairCMP(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second < b.second) {
		return true;
	}
	// ���̰� ������ ���ڳ��� ���ؼ� ������ ������ �����Ѵ�.
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
	// 1. �Է� vector�� <�ܾ�,�ܾ��� ����> �� �־��ش�.
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		myVec.push_back(make_pair(temp, temp.length()));
	}
	// 2.�������ش�.
	//��ü������ �� �Լ��� ���ڷ� �־��ش�  
	sort(myVec.begin(), myVec.end(), myPairCMP);
	cout << "---------------myAnswer--------------- \n";
	// 3.���
	map<string, int> myMap;
	for (int i = 0; i < N; i++) {
		// 4. �ߺ� ó��
		if (myMap[myVec[i].first] > 0)
			continue;
		else
			myMap[myVec[i].first]++;
		cout << myVec[i].first << "\n";
	}
	return 0;
}

