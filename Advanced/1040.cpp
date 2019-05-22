//简单动态规划

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string str;
	getline(cin, str, '\n');
	int res = 0;
	int sz = str.size();
	vector<vector<bool>> dp(sz + 1, vector<bool>(sz + 1, false));
	for (int i = 0; i <= sz; i++) {
		dp[i][i] = 1;
		res = 1;
	}
	for (int i = 0; i < sz - 1; i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i + 1] = 1;
			res = 2;
		}
	}
	for (int l = 3; l <= sz; l++) {
		for (int i = 0; i < sz + 1 - l; i++) {
			int j = i + l - 1;
			if (dp[i + 1][j - 1]) {
				if (str[i] == str[j]) {
					dp[i][j] = 1;
					res = l > res ? l : res;
				}
			}
		}
	}
	cout << res;

}
