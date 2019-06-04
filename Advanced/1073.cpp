//将科学计数法转换为正常表示

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;



int main() {
	string str;
	getline(cin, str, '\n');
	int idx = 1, exp = 0, tmp = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == 'E') {
			tmp = i;
			if (str[tmp+1] == '-')
				idx = 0;
			int ct = str.size() - 1, j = 0;
			while (ct > tmp+1) {
				int tmpi = str[ct] - '0';
				exp += pow(10, j)*tmpi;
				ct--;
				j++;
			}
			break;
		}
	}
	if (idx == 0) {
		if (exp > 0) {
			string res = str.substr(3, tmp - 3);
			res = str[1] + res;
			string pon = "0.";
			while (exp > 1) {
				pon.push_back('0');
				exp--;
			}
			res = pon + res;
			if(str[0]=='-')
				res = '-' + res;
			cout << res << endl;
		}
		else {
			string res = str.substr(1, tmp - 1);
			if (str[0] == '-')
				res = '-' + res;
			cout << res << endl;
		}
	}
	else {
		string res = str.substr(1, 1);
		int i = 3;
		while (i < tmp) {
			if (exp < 1)
				break;
			res.push_back(str[i]);
			i++;
			exp--;
		}
		int tmpi = 0;
		while (i < tmp) {
			if (tmpi == 0) {
				res.push_back('.');
				tmpi++;
			}
			res.push_back(str[i]);
			i++;
		}
		while (exp > 0) {
			res.push_back('0');
			exp--;
		}
		if (str[0] == '-')
			res = '-' + res;
		cout << res << endl;
	}


}

