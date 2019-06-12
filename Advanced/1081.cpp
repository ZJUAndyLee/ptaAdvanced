//分数的相加和约分 在累加的过程中要一边加一边约分 否则会超过整数范围。
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int num;

int GCD(int n1, int n2) {
	if (n1%n2 == 0)
		return n2;
	while (n1%n2 != 0) {
		int tmp = n1 % n2;
		n1 = n2;
		n2 = tmp;
	}
	return n2;
}

int LCM(int n1, int n2) {
	int tmp = n1 * n2;
	tmp = tmp / GCD(n1, n2);
	return tmp;
}

int main() {
	scanf("%d", &num);
	vector<pair<int, int>> vec;
	for (int i = 0; i < num; i++) {
		int x, y;
		scanf("%d/%d", &x, &y);
		vec.push_back(pair<int, int>(x, y));
	}
	pair<int, int> res(0, 1);
	for (int i = 0; i < num; i++) {
		int fm = vec[i].second > res.second ? LCM(vec[i].second, res.second) : LCM(res.second, vec[i].second);
		res.first = res.first*(fm / res.second);
		res.first += (fm / vec[i].second)*vec[i].first;
		res.second = fm;
		if (res.first != 0) {
			int gcd = res.first > res.second ? GCD(res.first, res.second) : GCD(res.second, res.first);
			res.first = res.first / gcd;
			res.second = res.second / gcd;
		}
	}
	
	if (res.first > 0) {
		if (res.first >= res.second) {
			int zs = res.first / res.second;
			cout << zs;
			res.first = res.first % res.second;
			if (res.first != 0) {
				cout << " " << res.first << "/" << res.second << endl;
			}
		}
		else {
			cout << res.first << "/" << res.second << endl;
		}
	}
	else if (res.first == 0) {
		cout << 0;
	}
	else {
		if (-res.first >= res.second) {
			int zs = res.first / res.second;
			cout << zs;
			res.first = -res.first % res.second;
			if (res.first != 0) {
				cout << " " << res.first << "/" << res.second << endl;
			}
		}
		else {
			cout << res.first << "/" << res.second << endl;
		}
	}
	//system("pause");
}

