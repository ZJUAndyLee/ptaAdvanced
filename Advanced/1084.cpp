//哈希策略
#include<string>
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	unordered_set<char> hs;
	for (auto x : s2) {
		hs.insert(x);
	}
	vector<char> res;
	unordered_set<char> tmpres;
	for (auto x : s1) {
		if (hs.find(x) == hs.end()) {
			if (x >= 'a'&&x <= 'z') {
				x = x - 'a' + 'A';
			}
			if (tmpres.find(x) == tmpres.end()) {
				res.push_back(x);
				tmpres.insert(x);
			}
		}
	}
	for (auto x : res)
		cout << x;

}
