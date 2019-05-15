#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;

//stack queue的运用

void HaveFunwithNumbers(string &s) {
	vector<pair<int, int>> vis(10, pair<int,int>(0, 0));
	int idx = 0, sz = s.size() - 1;
	stack<int> sk;
	for (int i = sz; i >= 0; i--) {
		int tmp = s[i] - '0';
		if (vis[tmp].first == 0) {
			vis[tmp].first = 1;
			vis[tmp].second = 1;
		}
		tmp *= 2;
		if (tmp < 10) {
			sk.push(tmp + idx);
			idx = 0;
		}
		else {
			tmp -= 10;
			sk.push(tmp + idx);
			idx = 1;
		}
	}
	if (idx > 0)
		sk.push(idx);
	int res = 0;
	vector<int> vres;
	while (!sk.empty()) {
		int tmp = sk.top();
		vres.push_back(tmp);
		sk.pop();
		if (vis[tmp].first == 0)
			res = 1;
		else
			vis[tmp].second = 0;
	}
	for (auto x: vis) {
		if (x.second == 1)
			res = 1;
	}
	if (res == 1) {
		cout << "No" << endl;
		for (auto x : vres)
			cout << x;
	}
	else {
		cout << "Yes" << endl;
		for (auto x : vres)
			cout << x;
	}
}

int main() {
	string str;
	cin >> str;
	HaveFunwithNumbers(str);

 }
