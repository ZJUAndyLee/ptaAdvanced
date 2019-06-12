//关键点是什么时候加入 Wan 和 Yi 这两个数量级

#include <iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

string Exg(char c) {
	switch (c)
	{
	case '1':
		return "yi";
	case '2':
		return "er";
	case '3':
		return "san";
	case '4':
		return "si";
	case '5':
		return "wu";
	case '6':
		return "liu";
	case '7':
		return "qi";
	case '8':
		return "ba";
	case '9':
		return "jiu";
	default:
		return "ling";
	}
}

int main() {
	string str;
	cin >> str;
	stack<string> res;
	bool fu = false;
	if (str.front() == '-') {
		fu = true;
		str.erase(str.begin());
	}
	int ct = str.size() - 1;
	bool zero = true;
	bool wan = false;
	bool yi = false;
	if (str.size() > 8)
		yi = true;
	if (str.size() > 4) {
		int ct = 0;
		for (int i = str.size() - 5; i >= 0; i--, ct++) {
			if (ct == 4)
				break;
			if (str[i] != '0') {
				wan = true;
				break;
			}
		}
	}
	int tmpi = 1;
	int numwan = 0, numyi = 0;
	while (ct >= 0) {
		if (yi&&ct == str.size()-9) {
			numyi = res.size();
		}
		if (wan&&ct == str.size()-5) {
			numwan = res.size();
		}
		if (zero) {
			if (str[ct] != '0') {
				zero = false;
				int tmp = tmpi % 4;
				if (tmp == 0) {
					res.push("Qian");
				}
				else if (tmp == 3) {
					res.push("Bai");
				}
				else if (tmp == 2) {
					res.push("Shi");
				}
				string tmps = Exg(str[ct]);
				res.push(tmps);
			}
		}
		else {
			if (str[ct] != '0') {
				int tmp = tmpi % 4;
				if (tmp == 0) {
					res.push("Qian");
				}
				else if (tmp == 3) {
					res.push("Bai");
				}
				else if (tmp == 2) {
					res.push("Shi");
				}
				string tmps = Exg(str[ct]);
				res.push(tmps);
			}
			else {
				if (res.top() != "ling") {
					res.push("ling");
				}
			}
		}
		ct--, tmpi++;
	}
	if (fu)
		res.push("Fu");
	int idx = 0;
	if (res.empty()) {
		cout << "ling";
	}
	while (!res.empty()) {
		if (idx != 0)
			cout << " ";
		cout << res.top();
		res.pop();
		if (yi&&res.size() == numyi)
			cout << " Yi";
		if (wan&&res.size() == numwan)
			cout << " Wan";
		idx++;
	}


}
