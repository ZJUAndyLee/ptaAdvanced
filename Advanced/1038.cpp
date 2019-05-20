//string排序问题 关键是排序规则：两个string两种前后组合的方式 那种方式更小相对于的组合方式谁就该在前面

#include<iostream>
#include<vector>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

bool cmp(string &s1,string &s2) {
	return s1 + s2 < s2 + s1 ? true : false;
}

int main() {
	vector<string> str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
	}
	sort(str.begin(), str.end(), cmp);
	vector<string> res;
	int vsz = str.size(), idx = 0, j = 0;
	while(j<vsz) {
		if (j == idx) {
			if (str[j][0] == '0') {
				int i = 1, sz = str[j].size();
				while (i < sz) {
					if (str[j][i] != '0')
						break;
					i++;
				}
				if (i < sz) {
					string tmps = str[j].substr(i, sz - i);
					res.push_back(tmps);
				}
				else
					idx++;
			}
            else
				res.push_back(str[j]);
		}
		else
			res.push_back(str[j]);
		j++;
	}
	if (res.empty())
		cout << 0;
	else {
		for (auto &s : res) {
			cout << s;
		}
	}

}
