//https://www.acmicpc.net/problem/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool check[130];
char ans[13];
int num[130];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b, c;
	cin >> a >> b >> c;
	int index = 0;
	for (int i = 0; i < a.size(); i++) {
		if (!check[a[i]]) {
			check[a[i]] = true;
			ans[index++] = a[i];
		}
	}
	for (int i = 0; i < b.size(); i++) {
		if (!check[b[i]]) {
			check[b[i]] = true;
			ans[index++] = b[i];
		}
	}
	for (int i = 0; i < c.size(); i++) {
		if (!check[c[i]]) {
			check[c[i]] = true;
			ans[index++] = c[i];
		}
	}
	int ne[12];
	for (int i = 0; i < 10; i++) {
		ne[i] = i;
	}
	do {
		for (int i = 0; i < index; i++) {
			num[ans[i]] = ne[i];
		}
		int anum = 0, bnum = 0, cnum = 0;
		for (int i = 0; i < a.size(); i++) {
			anum *= 10;
			anum += num[a[i]];
		}
		for (int i = 0; i < b.size(); i++) {
			bnum *= 10;
			bnum += num[b[i]];
		}
		for (int i = 0; i < c.size(); i++) {
			cnum *= 10;
			cnum += num[c[i]];
		}
		if (anum + bnum == cnum) {
			cout << "YES";
			return 0;
		}
	} while (next_permutation(ne, ne + 10));
	cout << "NO";
}
