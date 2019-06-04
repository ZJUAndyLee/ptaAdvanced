//找到出现次数最多的单词 注意大小写转换

#include <vector>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

bool cmp(pair<string, int> &p1, pair<string, int> &p2) {
	return p1.second > p2.second ? true : false;
}

int main() {
	string str;
	getline(cin, str, '\n');
	int sz = str.size(), i = 0;
	unordered_map<string, int> mp;
	while (i < sz) {
		if ((str[i] <= '9'&&str[i] >= '0') || (str[i] <= 'Z'&&str[i] >= 'A') || (str[i] <= 'z'&&str[i] >= 'a')) {
			string tmps;
			while (i < sz) {
				if ((str[i] <= '9'&&str[i] >= '0') || (str[i] <= 'z'&&str[i] >= 'a')) {
					tmps.push_back(str[i]);
				}
				else if (str[i] <= 'Z'&&str[i] >= 'A') {
					char c = str[i] - 'A' + 'a';
					tmps.push_back(c);
				}
				else
					break;
				i++;
			}
			mp[tmps]++;
		}
		i++;
	}
	vector<pair<string, int>> vec(mp.begin(), mp.end());
	/*for (pair<string, int>x : mp) {
		vec.push_back(x);
	}*/

	sort(vec.begin(), vec.end(), cmp);
	int res = vec[0].second;
	set<string> smp;
	for (auto x : vec) {
		if (x.second == res) {
			smp.insert(x.first);
		}
		else
			break;
	}
	cout << *(smp.begin()) << " " << res << endl;

}
