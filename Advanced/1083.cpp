//基础的基数排序题
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
int num;
int main() {
	scanf("%d", &num);
	vector<pair<string, string>> vec(101, pair<string, string>());
	for (int i = 0; i < num; i ++) {
		string s1, s2;
		int g;
		cin >> s1 >> s2 >> g;
		vec[g].first = s1;
		vec[g].second = s2;
	}
	int st, ed;
	scanf("%d %d", &st, &ed);
	vector<pair<string, string>> res;
	for (int i = ed; i >= st; i--) {
		if (!vec[i].first.empty()) {
			res.push_back(vec[i]);
		}
	}
	if (res.empty())
		cout << "NONE";
	else {
		for (auto x : res) {
			cout << x.first << " " << x.second << endl;
		}
	}
}

