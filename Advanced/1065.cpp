/**大数相加：
* 直接字符串做注意加法减法的区别 以及需要进位 以及比较的规则*/
#include <string>
#include <iostream>
using namespace std;

bool strjudge(string &s1, string &s2) {
	if (s1.front() == '-'&&s2.front() == '-') {
		if (s1.size() > s2.size())
			return false;
		else if (s1.size() == s2.size()) {
			return s1 >= s2 ? false : true;
		}
		else
			return true;
	}
	else if (s1.front() != '-'&&s2.front() != '-') {
		if (s1.size() > s2.size())
			return true;
		else if (s1.size() == s2.size()) {
			return s1 > s2 ? true : false;
		}
		else
			return false;
	}
	else if (s1.front() == '-')
		return false;
	else
		return true;
}

string ADD(string &s1, string &s2) {
	int iter1 = s1.size() - 1, iter2 = s2.size() - 1;
	string tmp="";
	int idx = 0;
	while (iter1 >= 0 && iter2 >= 0) {
		int tmpi = (s1[iter1] - '0') + (s2[iter2] - '0') + idx;
		if (tmpi >= 10) {
			tmp = to_string(tmpi - 10) + tmp;
			idx = 1;
		}
		else {
			tmp = to_string(tmpi) + tmp;
			idx = 0;
		}
		iter1--, iter2--;
	}
	if (iter1 < 0 && iter2 < 0) {
		if (idx > 0)
			tmp = to_string(idx) + tmp;
	}
	while (iter1 >= 0) {
		int tmpi = (s1[iter1] - '0') + idx;
		if (tmpi >= 10) {
			tmp = to_string(tmpi - 10) + tmp;
			idx = 1;
		}
		else {
			tmp = to_string(tmpi) + tmp;
			idx = 0;
		}
		iter1--;
	}
	while (iter2 >= 0) {
		int tmpi = (s2[iter2] - '0') + idx;
		if (tmpi >= 10) {
			tmp = to_string(tmpi - 10) + tmp;
			idx = 1;
		}
		else {
			tmp = to_string(tmpi) + tmp;
			idx = 0;
		}
		iter2--;
	}
	return tmp;
}

string MINUS(string &s1, string &s2) {
	int iter1 = s1.size() - 1, iter2 = s2.size() - 1;
	string tmp="";
	int idx = 0;
	while (iter1>=0&&iter2>=0) {
		int tmpi = s1[iter1] - s2[iter2] - idx;
		if (tmpi >= 0) {
			tmp = to_string(tmpi) + tmp;
			idx = 0;
		}
		else {
			tmpi = 10 + tmpi;
			tmp = to_string(tmpi) + tmp;
			idx = 1;
		}
		iter1--, iter2--;
	}
	while (iter1 >= 0) {
		int tmpi = s1[iter1] - '0' - idx;
		
		if (tmpi >= 0) {
			tmp = to_string(tmpi) + tmp;
			idx = 0;
		}
		else {
			tmpi = 10 + tmpi;
			tmp = to_string(tmpi) + tmp;
			idx = 1;
		}
		iter1--;
	}
	while (iter2 >= 0) {
		int tmpi = s2[iter2] - '0' - idx;
		if (tmpi >= 0) {
			tmp = to_string(tmpi) + tmp;
			idx = 0;
		}
		else {
			tmpi = 10 + tmpi;
			tmp = to_string(tmpi) + tmp;
			idx = 1;
		}
		iter2--;
	}
	int ct = 0;
	while (ct < tmp.size()) {
		if (tmp[ct] != '0')
			break;
		ct++;
	}
	if (ct == tmp.size())
		return "0";
	else {
		string res = tmp.substr(ct, 20);
		return res;
	}
}

bool judge(string &s1, string &s2, string &s3) {
	int iter1 = s1.size() - 1, iter2 = s2.size() - 1;
	string tmp;
	if (s1.front() == '-'&&s2.front() == '-') {
		s1.erase(s1.begin()), s2.erase(s2.begin());
		tmp = ADD(s1, s2);
		tmp = '-' + tmp;
	}
	else if (s1.front() != '-'&&s2.front() != '-') {
		tmp = ADD(s1, s2);
	}
	else if (s1.front() == '-'&&s2.front() != '-') {
		s1.erase(s1.begin());
		
		if (strjudge(s1, s2)) {
			tmp = MINUS(s1, s2);
			tmp = '-' + tmp;
		}
		else {
			tmp = MINUS(s2, s1);
		}
	}
	else {
		s2.erase(s2.begin());
		if (strjudge(s1, s2))
			tmp = MINUS(s1, s2);
		else {
			tmp = MINUS(s2, s1);
			tmp = '-' + tmp;
		}
	}
	//cout << tmp << endl;
	return strjudge(tmp, s3);
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string x, y, z;
		cin >> x >> y >> z;
		if (judge(x,y,z))
			printf("Case #%d: true\n", i + 1);
		else
			printf("Case #%d: false\n", i + 1);
	}

}
