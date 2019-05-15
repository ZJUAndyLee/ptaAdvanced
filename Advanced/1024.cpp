#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<queue>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;

void PalindromicNumber(string &s,int n) {
	int idx = 0, sz = s.size();
	stack<int> stk;
	for (int i = sz - 1; i >= 0; i--)
		stk.push(s[i] - '0');
		
	while (idx <= n) {
		stack<int> tmpsk;
		queue<int> tmpqe;
		vector<int> tmpres;
		while (!stk.empty()) {
			int tmpi = stk.top();
			stk.pop();
			tmpres.push_back(tmpi);
			tmpsk.push(tmpi);
			tmpqe.push(tmpi);
		}
		int ct = 0, flag = 0;
		while (!tmpsk.empty()) {
			int tmp1 = tmpsk.top(), tmp2 = tmpqe.front();
			tmpsk.pop(), tmpqe.pop();
			if (tmp1 != tmp2)
				ct = 1;
			if (tmp1 + tmp2+flag < 10) {//注意前面进位的点要一起加进来计算
				stk.push(tmp1 + tmp2 + flag);
				flag = 0;
			}
			else {
				stk.push(tmp1 + tmp2 - 10 + flag);
				flag = 1;
			}
		}
		if (flag > 0)
			stk.push(flag);
		if (ct == 0||idx==n) {
			for (auto x : tmpres) {
				cout << x;
			}
			cout << endl << idx;
			return;
		}
		idx++;
	}
}

int main() {
	int num;
	string str;
	cin >> str>>num;
	PalindromicNumber(str,num);

 }
