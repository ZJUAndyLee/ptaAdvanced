//关键把先导零去了 然后分成大于1以及小于1的两种情况去解决问题

#include<iostream>
#include<string>
#include<map>
using namespace std;

int radix;
string s1, s2;
pair<string, int> exChange1(string &s, int idx) {
	int ct = 0;
	while (ct < s.size()) {
		ct++;
		if (s[ct] == '.')
			break;
	}
	string res = "0.";
	int  tmp = 0, iter = 0;
	while (iter < s.size()) {
		if (s[iter] != '.') {
			res.push_back(s[iter]);
			tmp++;
		}
		iter++;
		if (tmp == idx)
			break;
	}
	return pair<string, int>(res, ct);
}
pair<string, int> exChange2(string &s, int idx) {
	int ct = 2;
	while (ct < s.size()) {
		if (s[ct] != '0')
			break;
		ct++;
	}
	int residx = 0;
	if (ct < s.size()) {
		residx = 2 - ct;
	}

	string res = "0.";
	int tmp = 0;
	while (ct < s.size()) {
		res.push_back(s[ct]);
		tmp++;
		ct++;
		if (tmp == idx)
			break;
	}
	return pair<string, int>(res, residx);
}

int main() {
	cin >> radix >> s1 >> s2;
	pair<string, int> res1;
	pair<string, int> res2;
	if (s1[0] == '0') {
		res1 = exChange2(s1, radix);
	}
	else {
		res1 = exChange1(s1, radix);
	}
	if (s2[0] == '0') {
		res2 = exChange2(s2, radix);
	}
	else {
		res2 = exChange1(s2, radix);
	}
	while (res1.first.size() - 2 < radix) {
		res1.first.push_back('0');
	}
	while (res2.first.size() - 2 < radix) {
		res2.first.push_back('0');
	}
	res1.first += "*10^";
	res2.first += "*10^";
	if (res1.first == res2.first&&res1.second == res2.second) {
		cout << "YES" << " " << res1.first << res1.second << endl;
	}
	else {
		cout << "NO" << " " << res1.first << res1.second << " " << res2.first << res2.second << endl;
	}
	system("pause");
}

